//https://www.spoj.com/problems/DISQUERY/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second

const int MAX = (int)1e5+1, LG = ceil(log2(MAX));

vector<pii> G[MAX];
vector<int> lvl(MAX);
vector<vector<int>> up(MAX, vector<int>(LG+1)), mini(MAX, vector<int>(LG+1)), maxi(MAX, vector<int>(LG+1));

void dfs(int u, int p, int dist=-1, int h=0) {
    lvl[u] = h;
    up[u][0] = p;
    if(dist != -1)
        mini[u][0] = maxi[u][0] = dist;
    for(int i = 1; i <= LG; ++i) {
        up[u][i] = up[up[u][i-1]][i-1];
        mini[u][i] = min(mini[u][i-1], mini[up[u][i-1]][i-1]);
        maxi[u][i] = max(maxi[u][i-1], maxi[up[u][i-1]][i-1]);
    }
    for(pii v : G[u]) {
        if(v.ff != p)
            dfs(v.ff, u, v.ss, h+1);
    }
}

int lca(int u, int v) {
    if(lvl[u] < lvl[v])
        swap(u, v);
    for(int i = LG; i >= 0; --i) {
        if(lvl[u] - (1<<i) >= lvl[v])
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

pii get_min_max(int u, int v) { // assumes u is at a level >= level of v
    if(u == v)
        return {0, 0};
    pii res = {INT_MAX, INT_MIN};
    for(int i = LG; i >= 0; --i) {
        if(lvl[u] - (1<<i) >= lvl[v]) {
            res.ff = min(res.ff, mini[u][i]);
            res.ss = max(res.ss, maxi[u][i]);
            u = up[u][i];
        }
    }
    return res;
}

pii query(int u, int v) {
    pii res;
    int l = lca(u, v);
    if(l == u)
        return get_min_max(v, l);
    if(l == v)
        return get_min_max(u, l);
    pii p = get_min_max(u, l), q = get_min_max(v, l);
    res.ff = min(p.ff, q.ff);
    res.ss = max(p.ss, q.ss);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= LG; ++j) {
            maxi[i][j] = INT_MIN;
            mini[i][j] = INT_MAX;
        }
    }
    dfs(1, 1);
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        pii res = query(u, v);
        cout << res.ff << ' ' << res.ss << '\n';
    }
} 
