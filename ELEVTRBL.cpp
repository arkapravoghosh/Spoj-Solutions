// www.spoj.com/problems/ELEVTRBL/

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int f, s, g, u, d, MAX = (int)1e6+5;
    cin >> f >> s >> g >> u >> d;
    int mindis = -1;
    queue<int> q;
    int dis[MAX];
    for(int i = 0; i < MAX; ++i) 
        dis[i] = -1;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()) {
        int n = q.front(); q.pop();
        if(n == g) {
            mindis = dis[n];
            break;
        }
        if(n+u <= f && dis[n+u] == -1) {
            q.push(n+u);
            dis[n+u] = dis[n]+1;
        }
        if(n-d > 0 && dis[n-d] == -1) {
            q.push(n-d);
            dis[n-d] = dis[n] + 1;
        }
    }
    if(mindis == -1)
        cout << "use the stairs";
    else
        cout << mindis;
    return 0;
} 
