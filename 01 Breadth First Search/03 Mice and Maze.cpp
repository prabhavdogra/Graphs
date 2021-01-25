#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Mice and Maze (SPOJ)
// https://www.spoj.com/problems/MICEMAZE/

ll bfs(vector <pair<ll, ll>> adj[], ll n, ll start, ll time) {
    bool exited[n] = {false}, visited[n] = {false};
    queue <pair<ll, ll>> q;
    q.push({start, 0});
    exited[start] = true;
    visited[start] = true;
    while(q.size()) {
        ll n = q.front().first;
        ll t = q.front().second;
        q.pop();
        for(auto it : adj[n]) {
            if(t + it.second > time) continue;
            q.push({it.first, t + it.second});
            visited[it.first] = true;
            exited[it.first] = true;
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i++) {
        if(exited[i] == true) ans++;
        // cout << exited[i] << " ";
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
    ll n, e, t, m, a, b, c;
    cin >> n >> e >> t >> m;
    vector <pair<ll, ll>> adj[n];
    for(ll i = 0 ; i < m ; i++) {
        cin >> a >> b >> c; 
        a--; b--;
        adj[b].push_back({a, c}); // NOTE: Reversing the connections
    }
    e--;
    cout << bfs(adj, n, e, t) << '\n';
    return 0;
}
