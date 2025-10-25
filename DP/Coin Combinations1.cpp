// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const long long MOD = 1e9 + 7;
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;
    sort(coins.begin(), coins.end());
    vector<long long> dp(x + 1);
    dp[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int c : coins) {
            if (i - c < 0) break;
                dp[i] = (dp[i] + dp[i - c]) % MOD;
        }
    }
 
    cout << dp[x] << "\n";
