// www.spoj.com/problems/GSS3/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAX = 5e4+1;

typedef struct data {
    ll sum, pref, suff, ans;
}data;

inline data new_data(int &v) {
    data d;
    d.sum = d.pref = d.suff = d.ans = v;
    return d;
}

inline data combine(data &l, data &r) {
    data d;
    d.sum = l.sum + r.sum;
    d.pref = max(l.pref, l.sum + r.pref);
    d.suff = max(r.suff, r.sum + l.suff);
    d.ans = max({l.ans, r.ans, l.suff + r.pref});
    return d;
}

int a[MAX];
data tree[4*MAX];

void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = new_data(a[l]);
        return;
    }
    int m = (l+r)>>1;
    build(node<<1, l, m);
    build(node<<1|1, m+1, r);
    tree[node] = combine(tree[node<<1], tree[node<<1|1]);
}

data query(int node, int l, int r, int p, int q) {
    if(l >= p && r <= q)
        return tree[node];
    int m = (l+r)>>1;
    if(q <= m)
        return query(node<<1, l, m, p, q);
    else if(p > m)
        return query(node<<1|1, m+1, r, p, q);
    data d1 = query(node<<1, l, m, p, q), d2 = query(node<<1|1, m+1, r, p, q);
    return combine(d1, d2);
}

void update(int node, int l, int r, int idx, int y) {
    if(l == r) {
        tree[node] = new_data(y);
        return;
    }
    int m = (l+r)>>1;
    if(idx <= m)
        update(node<<1, l, m, idx, y);
    else
        update(node<<1|1, m+1, r, idx, y);
    tree[node] = combine(tree[node<<1], tree[node<<1|1]);
}

int main() {
    fastio;
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    cin >> m;
    while(m--) {
        int ch, x, y;
        cin >> ch >> x >> y;
        if(!ch) {
            update(1, 1, n, x, y);
        } else {
            data d = query(1, 1, n, x, y);
            cout << d.ans << '\n';
        }
    }
    return 0;
}
