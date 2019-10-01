// https://www.spoj.com/problems/PPATH/

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define vpii vector<pii >
#define vpll vector<pll >
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define rep(i, j, k) for(int i = j; i < k; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define T int tt; cin>>tt; while(tt--)
 
const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;
const int MAX = (int)1e4;
 
bool isPrime(ll n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(ll i = 5; i*i <= n; i += 6)
        if(n%i == 0 || n%(i+2) == 0) return false;
    return true;
}
 
vll primes;
void find_primes(ll n = 100000000) { //Segmented-sieve
    ll limit = floor(sqrt(n)) + 1;
    vll test; test.pb(2), primes.pb(2);
    for(ll i = 3; i < limit; i += 2)
        if(isPrime(i)) test.pb(i), primes.pb(i);
    ll lo = limit, hi = 2*limit; bool p[limit];
    while(lo < n) {
        if(hi > n) hi = n; 
        memset(p, true, sizeof(p));
        for(int i = 0; i < test.size(); i++) {
            ll mn = floor(lo/test[i]) * test[i];
            if(mn < lo) mn += test[i];
            for(ll j = mn; j < hi; j += test[i]) p[j-lo] = 0;
        }
        for(ll i = 0; i < limit; i++)
            if(p[i] && i+lo < hi) primes.pb(i+lo);
        lo += limit, hi += limit;
    }
}
 
uset<int> prime, vis;
queue<pii > q;
 
inline void process(int &x, int inc, int d) {
    x += inc;
    if(prime.count(x) && !vis.count(x)) {
        q.push({x, d+1}); 
        vis.insert(x);
    }
}
 
int main() {
    fastio;
    find_primes(MAX);
    for(auto x : primes) prime.insert(x);
    T {
        int s, e, dis;
        cin >> s >> e;
        while(!q.empty()) q.pop();
        vis.clear();
        q.push({s, 0});
        while(!q.empty()) {
            int a = q.front().ff, d = q.front().ss;
            q.pop();
            if(a == e) {
                dis = d;
                break;
            }
            int x = a, min = 999, max = MAX, inc = 1000;
            while(x - inc > min) 
                process(x, -inc, d);
            x = a;
            while(x + inc < max) 
                process(x, inc, d);
            x = a, min = a/1000 * 1000, max = (a/1000 + 1)* 1000, inc = 100;
            while(x - inc > min)
                process(x, -inc, d);
            x = a;
            while(x + inc < max)
                process(x, inc, d);
            x = a, min = a/100 * 100, max = (a/100 + 1)* 100, inc = 10;
            while(x - inc > min)
                process(x, -inc, d);
            x = a;
            while(x + inc < max)
                process(x, inc, d);
            x = a, min = a/10 * 10, max = (a/10 + 1)* 10, inc = 1;
            while(x - inc > min)
                process(x, -inc, d);
            x = a;
            while(x + inc < max)
                process(x, inc, d);
        }
        cout << dis << "\n";
    }
    return 0;
} 
