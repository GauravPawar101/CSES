// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std; 
 
static void csort(vector<array<int,4>>& v, int k) {
    if (v.empty()) return;
    int lo = v[0][k], hi = v[0][k];
    for (int i = 1; i < (int)v.size(); ++i) {
        lo = min(lo, v[i][k]);
        hi = max(hi, v[i][k]);
    }
    int R = hi - lo + 1;
    vector<int> cnt(R + 1, 0);
    for (auto& x : v) cnt[x[k] - lo + 1]++;
    for (int i = 1; i <= R; ++i) cnt[i] += cnt[i - 1];
    vector<array<int,4>> out(v.size());
    for (auto& x : v) {
        int pos = cnt[x[k] - lo]++;
        out[pos] = x;
    }
    v.swap(out);
} 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
 
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    const int INF = 1e9+7;
    vector<vector<int>> rk(n, vector<int>(n, INF)); 
 
    for (int d = n + n - 2; d >= 0; --d) {
        vector<array<int,4>> v;
        int imin = max(0, d - (n - 1));
        int imax = min(n - 1, d);
        for (int i = imin; i <= imax; ++i) {
            int j = d - i;
            int r1 = (i + 1 < n) ? rk[i+1][j] : INF;
            int r2 = (j + 1 < n) ? rk[i][j+1] : INF;
            int best = min(r1, r2);
            if (i == n - 1 && j == n - 1) best = -1;
            v.push_back({(int)a[i][j], best, i, j});
        }
        csort(v, 1);
        csort(v, 0);
        int id = -1;
        for (int k = 0; k < (int)v.size(); ++k) {
            if (k == 0 || v[k][0] != v[k-1][0] || v[k][1] != v[k-1][1]) ++id;
            rk[v[k][2]][v[k][3]] = id;
        }
    } 
 
    string ans;
    int i = 0, j = 0;
    ans.push_back(a[i][j]);
    while (i != n - 1 || j != n - 1) {
        char cmin = (char)127;
        int rmin = INT_MAX, ni = i, nj = j;
        if (i + 1 < n && make_pair(a[i+1][j], rk[i+1][j]) < make_pair(cmin, rmin)) {
            cmin = a[i+1][j]; rmin = rk[i+1][j]; ni = i+1; nj = j;
        }
        if (j + 1 < n && make_pair(a[i][j+1], rk[i][j+1]) < make_pair(cmin, rmin)) {
            cmin = a[i][j+1]; rmin = rk[i][j+1]; ni = i; nj = j+1;
        }
        i = ni; j = nj;
        ans.push_back(a[i][j]);
    }
    cout << ans << '\n';
    return 0;
}
