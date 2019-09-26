// https://www.spoj.com/problems/RMID2/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fastio;
    int tt;
    cin>>tt;
    while(tt--) {
        int n, c = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> q;
        cin >> n;
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
    }
    return 0;
}
