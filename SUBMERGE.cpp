// www.spoj.com/problems/SUBMERGE/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

const int MAX = (int)(1e4+1);

int n, m, timer;
vector<int> G[MAX], tin(MAX), low(MAX);
bool vis[MAX];
set<int> cutpoints;

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for(int v : G[u]) {
        if(v == p)
            continue;
        if(vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= tin[u] && p != -1)
                cutpoints.insert(u);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cutpoints.insert(u);
}

void find_cutpoints() {
    timer = 0;
    cutpoints.clear();
    for(int i = 1; i <= n; ++i)
        vis[i] = false;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i])
            dfs(i);
    }
}

int main() {
    fastio;
    while(true) {
        cin >> n >> m;
        if(!n && !m)
            break;
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        find_cutpoints();
        cout << cutpoints.size() << '\n';
        for(int i = 0; i <= n; ++i)
            G[i].clear();
    }
    return 0;
}
