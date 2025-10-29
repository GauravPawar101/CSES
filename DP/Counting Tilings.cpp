// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int n, m;

// Generate all valid next masks from current mask
void generate(int pos, int cur_mask, int next_mask, vector<int>& next_masks) {
    if (pos == n) {
        next_masks.push_back(next_mask);
        return;
    }
    
    // If current position already filled (by previous vertical tile)
    if (cur_mask & (1 << pos)) {
        generate(pos + 1, cur_mask, next_mask, next_masks);
        return;
    }
    
    // Option 1: Place vertical tile (fills current pos in cur column, extends to next)
    generate(pos + 1, cur_mask | (1 << pos), next_mask | (1 << pos), next_masks);
    
    // Option 2: Place horizontal tile (fills current and next pos in cur column)
    if (pos + 1 < n && !(cur_mask & (1 << (pos + 1)))) {
        generate(pos + 2, cur_mask | (1 << pos) | (1 << (pos + 1)), next_mask, next_masks);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    // Precompute transitions
    vector<vector<int>> trans(1 << n);
    for (int mask = 0; mask < (1 << n); mask++) {
        generate(0, mask, 0, trans[mask]);
    }
    
    // dp[mask] = number of ways to fill columns with current column having profile 'mask'
    vector<long long> dp(1 << n, 0);
    dp[0] = 1;
    
    for (int col = 0; col < m; col++) {
        vector<long long> ndp(1 << n, 0);
        
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] > 0) {
                for (int next : trans[mask]) {
                    ndp[next] = (ndp[next] + dp[mask]) % MOD;
                }
            }
        }
        
        dp = ndp;
    }
    
    cout << dp[0] << endl;
    
    return 0;
}
