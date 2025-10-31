// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<long long> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; ++i)
        arr[i] = (a * arr[i - 1] + b) % c;

    vector<long long> L(n);
    for (int i = 0; i < n; ++i) {
        if (i % k == 0) {
            L[i] = arr[i]; 
        } else {
            L[i] = arr[i] | L[i - 1];
        }
    }

    vector<long long> R(n);
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1 || (i + 1) % k == 0) {
            R[i] = arr[i]; 
        } else {
            R[i] = arr[i] | R[i + 1];
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n - k; ++i) {
        ans ^= (R[i] | L[i + k - 1]);
    }

    cout << ans << "\n";
    return 0;
}
