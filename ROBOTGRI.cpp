//  www.spoj.com/problems/ROBOTGRI/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll MOD = (1<<31) - 1;
const int MAX = (int)(1e3+1);

vector<string> G(MAX);
ll ways[MAX][MAX] = {0};
bool vis[MAX][MAX] = {false};
int n;

void solve() {
    ways[n][n-1] = 1;
    for(int i = n-1; i >= 0; --i)
        for(int j = n-1; j >= 0; --j)
            if(G[i][j] == '.')
                ways[i][j] = (ways[i+1][j] + ways[i][j+1])%MOD;
}

inline bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < n && G[i][j] == '.';
}

void bfs() {
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    vis[0][0] = true;
    while(!q.empty()) {
        int  i = q.front().ff, j = q.front().ss; q.pop();
        if(isValid(i-1, j) && !vis[i-1][j]) {
            vis[i-1][j] = true;
            q.push({i-1, j});
        }
        if(isValid(i, j-1) && !vis[i][j-1]) {
            vis[i][j-1] = true;
            q.push({i, j-1});
        }
        if(isValid(i, j+1) && !vis[i][j+1]) {
            vis[i][j+1] = true;
            q.push({i, j+1});
        }
        if(isValid(i+1, j) && !vis[i+1][j]) {
            vis[i+1][j] = true;
            q.push({i+1, j});
        }
    }
}

int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> G[i];
    solve();
    if(ways[0][0])
    	cout << ways[0][0];
    else {
    	bfs();
    	if(vis[n-1][n-1])
    		cout << "THE GAME IS A LIE";
    	else
    		cout << "INCONCEIVABLE";
    }
    return 0;
}
