// www.spoj.com/problems/HISTOGRA/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<ll, ll>
#define vi vector<ll>
#define vull vector<ull>
#define vpii vector<pii >
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define rep(i, j, k) for(ll i = j; i < k; ++i)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)
 
const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;
const int MAX = (int)1e5;
 
int main() {
    fastio;
    while(true) {
        int n;
        cin >> n;
        if(n == 0)
            break;
        vector<ll> a(n);
        ll maxx = 0;
        for(int i = 0; i < n; i++)
            cin>>a[i];
        stack<ll> st;
        int i = 0;
        while(i < n) {
            if(st.empty() || a[st.top()] <= a[i])
                st.push(i++);
            else {
                int t = st.top();
                st.pop();
                ll mx = a[t] * (st.empty() ? i : i - st.top() - 1);
                maxx = max(maxx, mx);
            }
        }
        while(!st.empty()) {
            int t = st.top();
            st.pop();
            ll mx = a[t] * (st.empty() ? i : i - st.top() - 1);
            maxx = max(maxx, mx);
        }
        cout << maxx << '\n';
    }
    return 0;
} 
