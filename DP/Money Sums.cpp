// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std; 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    
    int maxSum = 0;
    for (int x : a) maxSum += x;
    
    vector<bool> dp(maxSum + 1, false);
    dp[0] = true; 
    
    for (int i = 0; i < n; i++) {
        for (int sum = maxSum; sum >= a[i]; sum--) {
            if (dp[sum - a[i]]) {
                dp[sum] = true;
            }
        }
    }
    
    vector<int> result;
    for (int sum = 1; sum <= maxSum; sum++) {
        if (dp[sum]) {
            result.push_back(sum);
        }
    }
    
    cout << result.size() << "\n";
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}
