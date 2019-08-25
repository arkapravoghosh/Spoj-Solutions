// www.spoj.com/problems/CAM5/

#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)
 
const int MAX = (int)1e5+1;
 
vector<int> G[MAX];
bool vis[MAX] = {false};
 
void dfs(int v) {
    vis[v] = true;
    for(auto u : G[v])
        if(!vis[u])
            dfs(u);
}
 
int main() {
    fastio;
    T {
        int n, m;
        cin>>n>>m;
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        int comp = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                comp++;
                dfs(i);
            }
        }
        cout << comp << '\n';
        for(int i = 0; i <= n; ++i)
            G[i].clear(), vis[i] = false;
    }
    return 0;
} 
