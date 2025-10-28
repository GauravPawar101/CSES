// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    vector<pair<int, int>> dp(1 << n);
    dp[0] = {1, 0}; 
    
    for (int mask = 1; mask < (1 << n); mask++) {
        dp[mask] = {n + 1, 0}; 
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                int prev = mask ^ (1 << i); 
                auto [rides, weight] = dp[prev];
                
                if (weight + w[i] <= x) {
                    auto candidate = make_pair(rides, weight + w[i]);
                    dp[mask] = min(dp[mask], candidate);
                } else {
                    auto candidate = make_pair(rides + 1, w[i]);
                    dp[mask] = min(dp[mask], candidate);
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1].first << endl;
    
    return 0;
}
