// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<array<long long, 3>> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    
    sort(a.begin(), a.end(), [](const array<long long, 3>& a, const array<long long, 3>& b) {
        return a[1] < b[1];
    });
    
    vector<long long> dp(n);
    dp[0] = a[0][2];
    
    for (int i = 1; i < n; i++) {
        long long c1 = dp[i - 1], c2 = a[i][2];
        
        int l = 0, r = i - 1, last = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid][1] < a[i][0]) {
                last = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (last != -1) {
            c2 += dp[last];
        }
        
        dp[i] = max(c1, c2);
    }
    
    cout << dp[n - 1] << endl;
    
    return 0;
}
