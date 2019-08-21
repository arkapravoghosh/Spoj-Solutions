// www.spoj.com/problems/GCPC11J/

#include <bits/stdc++.h>
using namespace std;
 
const int MAX = (int)(1e5+3);
 
vector<int> G[MAX], dis(MAX);
 
void dfs(int u, int p, int d) {
    dis[u] = d+1;
    for(auto v : G[u])
        if(v != p)
            dfs(v, u, dis[u]);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; cin >> t; 
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(0, -1, -1);
        int dist = distance(dis.begin(), max_element(dis.begin(), dis.begin()+n));
        dfs(dist, -1, -1);
        dist = *max_element(dis.begin(), dis.begin()+n);
        if(dist%2)
            cout << (dist>>1)+1 << '\n';
        else
            cout << (dist>>1) << '\n';
        for(int i = 0; i < n; ++i)
            G[i].clear();
    }
    return 0;
} 
