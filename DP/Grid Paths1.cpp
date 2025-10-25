// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<string> grid(n);
    for (auto &x: grid) cin >> x;
 
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[0][0] != '*') dp[0][0] = 1;
 
    vector<pair<int,int>> dir = {{1,0}, {0,1}};
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') continue;
            for (auto [dx, dy] : dir) {
                int ni = i + dx;
                int nj = j + dy;
                if (ni < n && nj < n && grid[ni][nj] != '*') {
                    dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                }
            }
        }
    }
 
    cout << dp[n-1][n-1] << "\n";
}
