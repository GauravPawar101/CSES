// Author - Gaurav Pawar
 
#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
 
long long n, k;
long long x, a, b, c;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k >> x >> a >> b >> c;
    vector<long long> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; ++i) arr[i] = (a * arr[i - 1] + b) % c;
    long long ans = 0, sum = 0;
    for (int i = 0; i < k; ++i) sum += arr[i];
    ans = sum;
    for (int i = k; i < n; ++i) {
        sum += arr[i];
        sum -= arr[i - k];
        ans ^= sum;
    }
 
    cout << ans;
    return 0;
}
