// www.spoj.com/problems/EXPEDI/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll, ll>
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)

int main() {
    fastio;
    T {
        priority_queue<int> pq;
        int n;
        cin >> n;
        vector<pii> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i].ff >> a[i].ss;
        sort(a.rbegin(), a.rend());
        int l, p;
        cin >> l >> p;
        int dist = l-p, j = 0, res = 0;
        while(dist > 0) {
            while(j < n && a[j].ff >= dist) {
                pq.push(a[j].ss);
                ++j;
            }
            if(pq.empty()) {
                res = -1;
                break;
            }
            dist -= pq.top();
            pq.pop();
            ++res;
        }
        cout << res << '\n';
    }
    return 0;
}
