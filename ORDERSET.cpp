// www.spoj.com/problems/ORDERSET/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
    indexed_set s;
    int q;
    cin >> q;
    while(q--) {
        char c;
        int x;
        cin >> c >> x;
        if(c == 'I') {
            s.insert(x);
        } else if(c== 'D') {
            s.erase(x);
        } else if(c == 'K') {
            if(x > s.size()) {
                cout << "invalid\n";
            } else {
                auto it = s.find_by_order(x-1);
                cout << *it << '\n';   
            }
        } else {
            cout << s.order_of_key(x) << '\n';
        }
    }
    return 0;
}
