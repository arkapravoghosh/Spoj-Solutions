// www.spoj.com/problems/POSTERS/

#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)
 
const int MAX = (int)(1e7+1);
 
int a[MAX] = {0}, tree[4*MAX] = {0};
unordered_set<int> s;
 
void update(int node, int l, int r, int i, int j, int val) {
    if(r < i || l > j)
        return;
    if(l >= i && r <= j) {
        tree[node] = val;
        return;
    }
    if(tree[node]) {
    	tree[node<<1] = tree[node<<1|1] = tree[node];
    	tree[node] = 0;
    }
    int m = (l+r)>>1;
    update(node<<1, l, m, i, j, val);
    update(node<<1|1, m+1, r, i, j, val);
}
 
void compute(int node, int l, int r) {
    if(l == r) {
        if(tree[node])
        	s.insert(tree[node]);
        tree[node] = 0;
        return;
    }
    if(tree[node])
    	tree[node<<1] = tree[node<<1|1] = tree[node];
    tree[node] = 0;
    int m = (l+r)>>1;
    compute(node<<1, l, m);
    compute(node<<1|1, m+1, r);
}

int main() {
    fastio;
    T {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            update(1, 0, MAX-1, l-1, r-1, i+1);
        }
        compute(1, 0, MAX-1);
        cout << s.size() << '\n';
        s.clear();
    }
    return 0;
}
