// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
        
    vector<long long> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
    
    map<long long, int> compress;
    for (int i = 0; i < sorted_arr.size(); ++i) {
        compress[sorted_arr[i]] = i;
    }
    
    FenwickTree ft(sorted_arr.size());
    long long inversions = 0;
    
    for (int i = 0; i < k; ++i) {
        int idx = compress[arr[i]];
        inversions += ft.rangeQuery(idx + 1, sorted_arr.size() - 1);
        ft.update(idx, 1);
    }
    
    cout << inversions;
    
    for (int i = k; i < n; ++i) {
        int remove_idx = compress[arr[i - k]];
        ft.update(remove_idx, -1);
        inversions -= ft.rangeQuery(0, remove_idx - 1);
        
        int add_idx = compress[arr[i]];
        inversions += ft.rangeQuery(add_idx + 1, sorted_arr.size() - 1);
        ft.update(add_idx, 1);
        
        cout << " " << inversions;
    }

    cout << "\n";
    return 0;
}
