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

    long long ans = arr[0], sum;
    for (int i = 1; i < k; ++i) ans ^= arr[i];
    sum = ans;
    for (int i = 1; i < n; ++i) {
        if (i - k >= 0){
        sum ^= arr[i - k];
        sum ^= arr[i];
        ans ^= sum;}
    }

    cout << ans << "\n";
    return 0;
}
