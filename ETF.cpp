// www.spoj.com/problems/ETF/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

int phi(int n) {
    int res = n;
    for(int i = 2; i*i <= n; ++i) {
        if(n%i == 0) {
            while(n%i == 0)
                n /= i;
            res -= res/i;
        }
    }
    if(n > 1)
        res -= res/n;
    return res;
}

int main() {
    fastio;
    T {
        int n;
        cin >> n;
        cout << phi(n) << '\n';
    }
    return 0;
}
