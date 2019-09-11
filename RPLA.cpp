// www.spoj.com/problems/RPLA/

#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back

const int MAX = (int)(1e5+1);

int n, m;
vector<int> G[MAX], indegree(MAX), zerodegree, temp;
vector<pair<int, int> > order(MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt, t = 1;
    cin >> tt;
    while(tt--) {
        cout << "Scenario #" << t++ << ":\n";
        cin >> n >> m;
        for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            G[v].pb(u);
            ++indegree[u];
        }
        for(int i = 0; i < n; ++i) {
            if(indegree[i] == 0)
                zerodegree.pb(i);
        }
        int rank = 1;
        while(zerodegree.size()) {
            for(auto u : zerodegree) {
                order[u] = {rank, u};
                for(auto v : G[u]) {
                    --indegree[v];
                    if(!indegree[v])
                        temp.pb(v);
                }
            }
            ++rank;
            zerodegree.clear();
            zerodegree = temp;
            temp.clear();
        }
        sort(order.begin(), order.begin()+n);
        for(int i = 0; i < n; ++i)
            cout << order[i].ff << ' ' << order[i].ss << '\n';
        for(int i = 0; i < n; ++i)
            G[i].clear(), indegree[i] = 0, order[i] = {0, 0};
    }
    return 0;
}
