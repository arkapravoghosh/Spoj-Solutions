//https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAX = (int)(1e6+1);

ll coun[MAX] = {0}, a[MAX], ans = 0, block;

inline void add(int pos) {
    ++coun[a[pos]];
    if(coun[a[pos]] == 1) ++ans;
}

inline void remove(int pos) {
    --coun[a[pos]];
    if(coun[a[pos]] == 0) --ans;
}

int main() {
    fastio;
    int n, q;
    cin >> n;
    block = sqrt(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    cin >> q;
    vector<pair<pair<int, int>, int>> b(q);
    ll res[q];
    for(int i = 0; i < q; ++i) {
        cin >> b[i].ff.ff >> b[i].ff.ss;
        --b[i].ff.ff, --b[i].ff.ss;
        b[i].ss = i;
    }
    sort(b.begin(), b.end(), [](auto &x, auto &y) {
            if(x.ff.ff/block != y.ff.ff/block) //queries belong to diff blocks
                return x.ff.ff < y.ff.ff;
            return x.ff.ss < y.ff.ss;
        });
    int l = 0, r = 0;
    for(auto v : b) {
        int x = v.ff.ff, y = v.ff.ss;
        while(l < x) {
            remove(l);
            ++l;
        }
        while(l > x) {
            add(l-1);
            --l;
        }
        while(r <= y) {
            add(r);
            ++r;
        }
        while(r > y+1) {
            remove(r-1);
            --r;
        }
        res[v.ss] = ans;
    }
    for(int i = 0; i < q; ++i)
        cout << res[i] << '\n';
    return 0;
}
