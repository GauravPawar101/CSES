// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int LOG = 20;          
const int N = 2e5 + 5;
int up[N][LOG];              
int n, q;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> q;
 
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        up[i][0] = boss;
    }
 
    up[1][0] = 0;
 
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (up[i][j - 1])
                up[i][j] = up[up[i][j - 1]][j - 1];
            else
                up[i][j] = 0;
        }
    }

  // LCA using bits to answer kth ancestor of x
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                x = up[x][i];
                if (x == 0) break;
            }
        }
        cout << (x == 0 ? -1 : x) << "\n";
    }
 
    return 0;
}
