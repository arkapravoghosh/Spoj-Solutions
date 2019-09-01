// www.spoj.com/problems/BUGLIFE/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vpii vector<pii >
#define vpll vector<pll >
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define rep(i, j, k) for(int i = j; i < k; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)
 
const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;
const int MAX = (int)1e5+1;

vector<int> G[MAX];
int color[MAX];
 
bool isBipartite(int u, int c) {
    color[u] = c;
    for(int v : G[u]) {
        if(color[v] == -1) {
            if(!isBipartite(v, 1-c)) 
                return false;
        } else if(color[v] == color[u])
            return false;
    }
    return true;
}

int main() {
    fastio;
    int t = 1;
    T {
        cout << "Scenario #" << t++ << ":\n";
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].pb(v);
            G[v].pb(u);
        }
        bool f = true;
        for(int i = 0; i <= n; ++i)
        	color[i] = -1;
        for(int i = 1; i <= n; ++i) {
            if(color[i] == -1 && !isBipartite(i, 0)) {
                f = false;
                break;
            }
        }
        if(f)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
        for(int i = 0; i <= n; ++i)
            G[i].clear();
    }
    return 0;
}
