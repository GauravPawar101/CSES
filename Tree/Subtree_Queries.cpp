// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
vector<int> adj[N];
int in[N], out[N], timer = 0;
long long flat[N], val[N];
 
struct SegTree {
    int n;
    vector<long long> seg;
    SegTree(int n) : n(n), seg(4 * n, 0) {}
 
    void build(int idx, int l, int r, long long arr[]) {
        if (l == r) { seg[idx] = arr[l]; return; }
        int m = (l + r) / 2;
        build(2 * idx, l, m, arr);
        build(2 * idx + 1, m + 1, r, arr);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
 
    void update(int idx, int l, int r, int pos, long long val) {
        if (l == r) { seg[idx] = val; return; }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * idx, l, m, pos, val);
        else update(2 * idx + 1, m + 1, r, pos, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
 
    long long query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int m = (l + r) / 2;
        return query(2 * idx, l, m, ql, qr) + query(2 * idx + 1, m + 1, r, ql, qr);
    }
};
 
void dfs(int u, int p) {
    in[u] = ++timer;
    flat[in[u]] = val[u];
    for (int v : adj[u]) if (v != p) dfs(v, u);
    out[u] = timer;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1, 0);
    SegTree st(n);
    st.build(1, 1, n, flat);
 
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s; long long x;
            cin >> s >> x;
            st.update(1, 1, n, in[s], x);
        } else {
            int s;
            cin >> s;
            cout << st.query(1, 1, n, in[s], out[s]) << "\n";
        }
    }
}
Share code to others
Test details
