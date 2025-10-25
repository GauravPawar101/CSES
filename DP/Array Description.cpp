// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;
 
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0)); 
 
    if (a[0] == 0)
        for (int x = 1; x <= m; ++x)
            dp[0][x] = 1;
    else
        dp[0][a[0]] = 1;
 
    for (int i = 1; i < n; ++i) {
        for (int x = 1; x <= m; ++x) {
            if (a[i] != 0 && a[i] != x) continue; 
 
            dp[i][x] = (
                (long long)dp[i - 1][x - 1] +
                dp[i - 1][x] +
                dp[i - 1][x + 1]
            ) % MOD;
        }
    }
 
    int ans = 0;
    for (int x = 1; x <= m; ++x)
        ans = (ans + dp[n - 1][x]) % MOD;
 
    cout << ans << "\n";
}
