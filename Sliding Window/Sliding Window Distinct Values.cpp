// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int tlen = 0;
    map<long long, int> cnt; 
    
    for (int i = 0; i < k; ++i) {
        ++cnt[arr[i]];
        tlen += (cnt[arr[i]] == 1); 
    }
    cout << tlen << " ";
    for (int i = k; i < n; ++i) {
        ++cnt[arr[i]];
        if (cnt[arr[i]] == 1) ++tlen;

        long long leaving_val = arr[i - k];
        --cnt[arr[i - k]];
        if (cnt[arr[i - k]] == 0) { 
            --tlen;
            cnt.erase(leaving_val); 
        }
        cout << tlen << " ";
    }

    cout << "\n";
    return 0;
}
