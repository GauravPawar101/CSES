// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m;
    cin >> n >> m;
    int mx = max(n, m);
    vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, 1e9));
 
    for (int i = 1; i <= mx; ++i)
        dp[i][i] = 0;
 
    for (int i = 1; i <= mx; ++i) {
        for (int j = i + 1; j <= mx; ++j) { 
            for (int k = 1; k < i; ++k)
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
 
            for (int k = 1; k < j; ++k)
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
 
            dp[j][i] = dp[i][j]; 
        }
    }
 
    cout << dp[n][m] << "\n";
}
