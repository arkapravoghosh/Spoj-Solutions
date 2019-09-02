// www.spoj.com/problems/TRVCOST/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define vi vector<ll>
#define vll vector<ll>
#define vull vector<ull>
#define vpii vector<pll >
#define vpll vector<pll >
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define rep(i, j, k) for(ll i = j; i < k; ++i)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;
const int MAX = (int)(1e3+1);

vpii G[MAX];
vi dis(MAX, INF);
vector<bool> processed(MAX, false);

void dijkstra(int s) {
    priority_queue<pii> q;
    q.push({0, s});
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.top().ss; q.pop();
        if(processed[u]) continue;
        processed[u] = true;
        for(auto x : G[u]) {
            int v = x.ff, w = x.ss;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}

int main() {
    fastio;
    //T {
        int n;
        cin >> n;
        rep(i, 0, n) {
            ll u, v, w;
            cin >> u >> v >> w;
            G[u].pb({v, w});
            G[v].pb({u, w});
        }
        int u;
        cin >> u;
        dijkstra(u);
        int q;
        cin >> q;
        while(q--) {
            int v;
            cin >> v;
            if(dis[v] == INF)
                cout << "NO PATH\n";
            else
                cout << dis[v] << '\n';
        }
    //}
    return 0;
}
