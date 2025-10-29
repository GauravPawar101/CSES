// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class FenwickTree {
    vector<long long> tree;
    int n;
    
public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}
    
    void update(int idx, long long val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] = (tree[idx] + val) % MOD;
        }
    }
    
    long long query(int idx) {
        long long sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum = (sum + tree[idx]) % MOD;
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    
    map<int, int> coords;
    for (int i = 0; i < b.size(); i++) {
        coords[b[i]] = i;
    }
    
    FenwickTree ft(b.size());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int val = coords[a[i]];
        long long count = ft.query(val - 1);
        long long temp = (1 + count) % MOD;
        ft.update(val, temp);
        ans = (ans + temp) % MOD;
    }
    
    cout << ans;
    
    return 0;
}
