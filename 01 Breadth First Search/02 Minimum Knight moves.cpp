#include <bits/stdc++.h>
using namespace std;
#define ll              long long int

// NAKANJ - Minimum Knight moves SPOJ)
// https://www.spoj.com/problems/NAKANJ/

ll bfs(ll sx, ll sy, ll ex, ll ey) {
    queue <pair<pair<ll, ll>, ll>> q;
    bool visited[8][8];
    for(int i = 0 ; i < 8 ; i++) 
        for(int j = 0 ; j < 8 ; j++)
            visited[i][j] = false;
    q.push({{sx, sy}, 0});
    ll ans = INT_MAX;
    while(q.size()) {
        ll posx = q.front().first.first;
        ll posy = q.front().first.second;
        ll moves = q.front().second;
        q.pop();
        if(posx == ex && posy == ey) {
            ans = min(ans, moves);
            continue;
        }
        else if(posx > 7 || posx < 0 || posy > 7 || posy < 0) continue;
        if(visited[posx][posy] == true) continue;
        visited[posx][posy] = true;
        q.push({{posx + 2, posy + 1}, moves + 1});
        q.push({{posx + 2, posy - 1}, moves + 1});
        q.push({{posx - 2, posy + 1}, moves + 1});
        q.push({{posx - 2, posy - 1}, moves + 1});
        q.push({{posx + 1, posy + 2}, moves + 1});
        q.push({{posx - 1, posy + 2}, moves + 1});
        q.push({{posx + 1, posy - 2}, moves + 1});
        q.push({{posx - 1, posy - 2}, moves + 1});
    }
    return ans;
}

int main() {   
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin) ;
    //     freopen("output.txt", "w", stdout) ;
    // #endif 
    ll T;
    cin >> T;
    while(T--) {
        string a, b;
        cin >> a >> b;
        ll sx = a[0] - 'a', ex = b[0] - 'a', sy = a[1] - '1', ey = b[1] - '1';
        cout << bfs(sx, sy, ex, ey) << '\n';
    }
    return 0;
}
