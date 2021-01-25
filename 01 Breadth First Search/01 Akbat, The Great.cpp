#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// Akbar , The great - Spoj (BFS - 1)
// https://www.spoj.com/problems/AKBAR/

vector<int> visited(1000005);

void bfs(vector<int> adj[], int node, int power, int n) {
    queue <pair<int, int>> q;
    q.push({node, power});
    vector<int> vis(n);
    for(int i = 0 ; i < n ; i++) 
        vis[i] = visited[i];
    while(q.size()) {
        node = q.front().first;
        power = q.front().second;
        q.pop();
        if(power < 0) continue;
        if(visited[node] - vis[node] < 1) // Cyclic case 
            visited[node] += 1;
        for(auto it : adj[node]) {
            if(visited[it] - vis[it] >= 1) 
                continue;
            q.push({it, power - 1});
        }
    }
}

int main() { 
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;    
    while(T--) {
        int n, r, m, a, b, c; 
        cin >> n >> r >> m;
        for(int i = 0 ; i < n ; i++) 
            visited[i] = 0;
        vector<int> adj[n];
        for(int i = 0 ; i < r ; i++) {
            cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0 ; i < m ; i++) {
            cin >> a >> b;
            a--;
            if(b == 0) visited[a] += 1;
            else bfs(adj, a, b, n);
        }
        // for(int i = 0 ; i < n ; i++) 
        //     cout << visited[i] << " "; 
        // cout << '\n';
        ll f = 1; 
        for(int i = 0 ; i < n ; i++) { 
            if(visited[i] != 1) {
                f = 0; 
                break;
            } 
        } 
        f ? cout << "Yes" << '\n' : cout << "No" << '\n';
    }
    return 0; 
}