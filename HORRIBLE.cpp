// www.spoj.com/problems/HORRIBLE/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = (int)1e5+1;
ll tree[4*MAX], lazy[4*MAX];

void update_lazy(int node, int l, int r) {
    tree[node] += (r - l + 1)*lazy[node];
    if(l != r) {
        lazy[node<<1] += lazy[node];
        lazy[node<<1|1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int l, int r, int a, int b, ll v) {
    if(lazy[node])
        update_lazy(node, l, r);
    if(b < l || a > r)
        return;
    if(l >= a && r <= b) {
        tree[node] += (r - l + 1)*v;
        if(l != r) {
            lazy[node<<1] += v;
            lazy[node<<1|1] += v;
        }
        return;
    }
    int m = (l+r)>>1;
    update(node<<1, l, m, a, b, v);
    update(node<<1|1, m+1, r, a, b, v);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

ll query(int node, int l, int r, int a, int b) {
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
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        for(int i = 0; i <= 4*n; ++i) tree[i] = lazy[i] = 0;
        while(c--) {
            int ch;
            cin >> ch;
            if(!ch) {
                ll p, q, v;
                cin >> p >> q >> v;
                update(1, 0, n-1, p-1, q-1, v);
            } else {
                ll p, q;
                cin >> p >> q;
                cout << query(1, 0, n-1, p-1, q-1) << '\n';
            }
        }
    }
    return 0;
}
