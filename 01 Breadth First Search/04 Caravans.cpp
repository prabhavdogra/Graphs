#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// 2034. Caravans (Timus Online Judge)
// https://acm.timus.ru/problem.aspx?space=1&num=2034

const ll N = 1e5;
vector<ll> adj[N];
ll path[N];

void distanceFromR(ll start, ll n) {
    for(ll i = 0 ; i < N ; i++) 
        path[i] = INT_MAX;
    queue<pair<ll, ll>> q;
    bool visited[n] = {0};
    q.push({start, 0});
    while(q.size()) {
        ll node = q.front().first;
        ll dis = q.front().second;
        q.pop();
        if(visited[node]) continue;
        else visited[node] = true;
        path[node] = min(path[node], dis);
        for(auto it : adj[node]) {
            q.push({it, dis + 1});
        }
    }
}

ll shortestPath(ll start, ll finish, ll n) {
    ll ans = INT_MIN;
    queue <pair<pair<ll, ll>, ll>> q;
    pair<bool, ll> visited[n];
    for(ll i = 0 ; i < n ; i++)
        visited[i] = {0, -1};
    q.push({{start, path[start]}, 0});
    ll flag = INT_MAX;
    while(q.size()) {
        ll node = q.front().first.first;
        ll temp = q.front().first.second;
        ll depth = q.front().second;
        q.pop();
        if(visited[node].first && depth > visited[node].second) continue;
        else visited[node] = {true, depth};
        for(auto it: adj[node]) {
            if(node == finish && depth <= flag) ans = max(temp, ans), flag = depth;
            if(flag < depth) continue;
            q.push({{it, min(temp, path[it])}, depth + 1});
        }
    }
    return ans;
}

int main() 
{   
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin) ;
    //     freopen("output.txt", "w", stdout) ;
    // #endif 
    ll n, m, a, b;
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll s, f, r;
    cin >> s >> f >> r;
    s--; f--; r--;
    distanceFromR(r, n);
    // for(ll i = 0 ; i < 7 ; i++) 
    //     cout << path[i] << " ";
    cout << shortestPath(s, f, n);
    return 0;
}
 