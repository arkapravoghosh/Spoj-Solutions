// www.spoj.com/problems/INVCNT/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

const int MAX = (int)1e7+1, MX = (int)2e5+1;

int n, BIT[MAX], a[MX];

void update(int i, int x) {
    while(i <= n) {
        BIT[i] += x;
        i += i&-i;
    }
}

int sum(int i) {
    int sum = 0;
    while(i >= 1) {
        sum += BIT[i];
        i -= i&-i;
    }
    return sum;
}

int main() {
    fastio;
    T {
        int m;
        cin >> m;
        n = 0;
        for(int i = 0; i < m; ++i) {
            cin >> a[i];
            n = a[i] > n ? a[i] : n;
        }
        for(int i = 0; i <= n; ++i)
			BIT[i] = 0;
        ll res = 0;
        for(int i = m-1; i >= 0; --i) {
            res += sum(a[i]);
            update(a[i], 1);
        }
        cout << res << '\n';
    }
    return 0;
}
