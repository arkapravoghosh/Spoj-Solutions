// www.spoj.com/problems/LCASQ/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

const int MAX = (int)1e4+1, LG = ceil(log2(MAX));

vector<int> G[MAX], lvl(MAX);
vector<vector<int>> up(MAX, vector<int>(LG+1));

void dfs(int u, int p, int h) {
    lvl[u] = h;
    up[u][0] = p;
    for(int i = 1; i <= LG; ++i)
        up[u][i] = up[up[u][i-1]][i-1];
    for(int v : G[u]) {
        if(v != p)
            dfs(v, u, h+1);
    }
}

int lca(int u, int v) {
    if(lvl[u] < lvl[v])
        swap(u, v);
    for(int i = LG; i >= 0; --i) {
        if(lvl[u]-(1<<i) >= lvl[v])
            u = up[u][i];
    }
    if(u == v)
        return u;
    for(int i = LG; i >= 0; --i) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    fastio;
    int n, m, u, v;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> m;
        for(int j = 0; j < m; ++j) {
            cin >> u;
            G[i].pb(u);
        }
    }
    dfs(0, 0, 0);
    int q;
    cin >> q;
    while(q--) {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    return 0;
}
