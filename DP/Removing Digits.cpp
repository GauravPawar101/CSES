// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
 
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp > 0) {
            int d = temp % 10;
            if (d != 0) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
            temp /= 10;
        }
    }
 
    cout << dp[n] << "\n";
    return 0;

}
