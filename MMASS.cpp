// www.spoj.com/problems/MMASS/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(0);
 
int main() {
    fastio;
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    mp['H'] = 1;
    mp['C'] = 12;
    mp['O'] = 16;
    stack<int> st;
    for(auto x : s) {
        if(x == '(')
            st.push(-1);
        else if(x == ')') {
            int sum = 0;
            while(st.top() != -1) {
                sum += st.top();
                st.pop();
            }
            st.pop();
            st.push(sum);
        }
        else if(isdigit(x)) {
            int sum = st.top();
            st.pop();
            sum *= (x - 48);
            st.push(sum);
        }
        else {
            st.push(mp[x]);
        }
    }
    int sum = 0;
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}
