// www.spoj.com/problems/RMID/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fastio;
    ll x;
    while(cin >> x) {
        ll n = x, c = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        priority_queue<ll> q;
        while(n != 0) {
            if(n == -1) {
                cout << q.top() << '\n';
                q.pop();
                --c;
                if(c%2) {
                    q.push(pq.top());
                    pq.pop();
                }
            } else{
                ++c;
                if(c%2) {
                    pq.push(n);
                    q.push(pq.top());
                    pq.pop();
                } else {
                    if(n < q.top()) {
                        pq.push(q.top());
                        q.pop();
                        q.push(n);
                    } else 
                        pq.push(n);
                }
            }
            cin >> n;
        }
        cout << '\n';
    }
    return 0;
} 
