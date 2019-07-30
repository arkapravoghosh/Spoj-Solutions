// Problem link - https://www.spoj.com/problems/CAM5/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<ll, ll>
#define vi vector<ll>
#define vull vector<ull>
#define vpii vector<pii >
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
const int MAX = (int)(1e5+1);

int parent[MAX], size[MAX];

int find(int u) {
    return u == parent[u] ? u : find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
}

int main() {
    fastio;
    T {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        uset<int> res;
        for(int i = 0; i < n; ++i)
            res.insert(parent[i]);
        cout << res.size() << '\n';
    }
    return 0;
}
