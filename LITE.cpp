// www.spoj.com/problems/LITE/

#include <bits/stdc++.h>
using namespace std;
 
const int MAX = (int)1e5+1;
int tree[4*MAX], lazy[4*MAX];
 
void update_lazy(int node, int l, int r) {
    tree[node] = (r-l+1)-tree[node];
    if(l != r) {
        lazy[node<<1] ^= 1;
        lazy[node<<1|1] ^= 1;
    }
    lazy[node] = 0;
}
 
void update(int node, int l, int r, int a, int b) {
    if(lazy[node])
        update_lazy(node, l, r);
    if(b < l || a > r)
        return;
    if(l >= a && r <= b) {
        tree[node] = (r-l+1)-tree[node];
        if(l != r) {
            lazy[node<<1] ^= 1;
            lazy[node<<1|1] ^= 1;
        }
        return;
    }
    int m = (l+r)>>1;
    update(node<<1, l, m, a, b);
    update(node<<1|1, m+1, r, a, b);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}
 
int query(int node, int l, int r, int a, int b) {
    if(lazy[node])
        update_lazy(node, l, r);
    if(b < l || a > r)
        return 0;
    if(l >= a && r <= b)
        return tree[node];
    int m = (l+r)>>1;
    return query(node<<1, l, m, a, b) + query(node<<1|1, m+1, r, a, b);
}
 
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, c;
    cin >> n >> c;
    for(int i = 0; i <= 4*n; ++i) 
    	tree[i] = lazy[i] = 0;
    while(c--) {
        int ch, p, q;
        cin >> ch >> p >> q;
        if(!ch)
            update(1, 0, n-1, p-1, q-1);
        else
            cout << query(1, 0, n-1, p-1, q-1) << '\n';
    }
    return 0;
} 
