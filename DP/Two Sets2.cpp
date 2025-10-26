// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std; 

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long totalSum = (long long)n * (n + 1) / 2;
    
    if (totalSum % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    
    int target = totalSum / 2;
    
    vector<long long> dp(target + 1, 0);
    dp[0] = 1; 
    
    for (int num = 1; num <= n; num++) {
        for (int sum = target; sum >= num; sum--) {
            dp[sum] = (dp[sum] + dp[sum - num]) % MOD;
        }
    }
    long long result = dp[target] * ((MOD + 1) / 2) % MOD;
    cout << result << "\n";
    
    return 0;
}
