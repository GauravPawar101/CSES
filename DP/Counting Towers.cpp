// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int N = 1e6;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
 
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = (4 * dp[i - 1][0] % MOD + dp[i - 1][1]) % MOD;
        dp[i][1] = (2 * dp[i - 1][1] % MOD + dp[i - 1][0]) % MOD;
    }
 
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }
 
    return 0;
