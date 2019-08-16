// www.spoj.com/problems/EC_P/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

const int MAX = (int)(1e3+1);

int n, m, timer;
vector<int> G[MAX], tin(MAX), low(MAX);
vector<pair<int, int>> bridges;
bool vis[MAX];

void dfs(int u, int p = -1) {
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for(int v : G[u]) {
        if(v == p)
            continue;
        if(vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) {
                bridges.pb({min(u, v), max(u, v)});
            }
        }
    }
}
 
void find_bridges() {
    timer = 0;
    bridges.clear();
    for(int i = 1; i <= n; ++i)
        vis[i] = false;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i])
            dfs(i);
    }
}
 
int main() {
    fastio;
    int t = 1;
    T {
        cout << "Caso #" << t++ << '\n';
        cin >> n >> m;
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        find_bridges();
        if(!bridges.size())
            cout << "Sin bloqueos\n";
        else {
            cout << bridges.size() << '\n';
            sort(bridges.begin(), bridges.end());
            for(auto x : bridges)
                cout << x.ff << ' ' << x.ss << '\n';
        }
        for(int i = 0; i <= n; ++i)
            G[i].clear();
    }
    return 0;
} 
