// www.spoj.com/problems/QTREE2/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second

const int MAX = (int)1e4+1, LG = ceil(log2(MAX));

int n;
vector<pii> G[MAX];
vector<int> lvl(MAX), dist(MAX);
vector<vector<int>> up(MAX, vector<int>(LG+1));

void dfs(int u, int p, int h=0, int w=0) {
    lvl[u] = h;
    up[u][0] = p;
    dist[u] = dist[p] + w;
    for(int i = 1; i <= LG; ++i)
        up[u][i] = up[up[u][i-1]][i-1];
    for(pii v : G[u]) {
        if(v.ff != p)
            dfs(v.ff, u, h+1, v.ss);
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
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

int query1(int u, int v) {
    int l = lca(u, v);
    return dist[u] + dist[v] - (dist[l]<<1);
}

int query2(int u, int v, int k) {
    int l = lca(u, v);
    if(lvl[u] - lvl[l] + 1 < k) {
        k = lvl[u] + lvl[v] - (lvl[l]<<1) + 1 - k + 1;
        swap(u, v);
    }
    --k;
    for(int i = LG; i >= 0; --i) {
        if((1<<i) <= k) {
            k -= (1<<i);
            u = up[u][i];
        }
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n;
        for(int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].pb({v, w});
            G[v].pb({u, w});
        }
        dist[1] = 0;
        dfs(1, 1);
        string s;
        cin >> s;
        while(s != "DONE") {
            if(s == "DIST") {
                int u, v;
                cin >> u >> v;
                cout << query1(u, v) << '\n';
            } else {
                int u, v, k;
                cin >> u >> v >> k;
                cout << query2(u, v, k) << '\n';
            }
            cin >> s;
        }
        for(int i = 0; i <= n; ++i)
            G[i].clear();
    }
    return 0;
}
