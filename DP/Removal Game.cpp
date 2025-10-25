// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std; 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x: a) cin >> x;
    
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            long long takeLeft = a[i] + min(
                (i + 2 <= j ? dp[i+2][j] : 0),  
                (i + 1 <= j - 1 ? dp[i+1][j-1] : 0)  
            );
            
            long long takeRight = a[j] + min(
                (i + 1 <= j - 1 ? dp[i+1][j-1] : 0), 
                (i <= j - 2 ? dp[i][j-2] : 0)  
            );
            
            dp[i][j] = max(takeLeft, takeRight);
        }
    }
    
    cout << dp[0][n-1] << "\n";
    
    return 0;
}
