// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int &y : h) cin >> y;
    for (int &y : s) cin >> y;
 
    vector<long long> dp(x + 1, 0);
 
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= h[i]; --j) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
 
    cout << dp[x] << "\n";
}
