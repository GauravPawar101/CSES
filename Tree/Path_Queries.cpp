// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
 
const int N = 2e5 + 5;
int n, q, timer = 0;
vector<int> adj[N];
int in[N], out[N];
int64 val[N];
 
struct BIT {
    int n;
    vector<int64> tree;
 
    BIT(int n) : n(n), tree(n + 2, 0) {}
 
    void add(int i, int64 diff) {
        for (; i <= n; i += i & -i)
            tree[i] += diff;
    }
 
    int64 sum(int i) {
        int64 s = 0;
        for (; i > 0; i -= i & -i)
            s += tree[i];
        return s;
    }
};
 
void dfs(int u, int p) {
    in[u] = ++timer;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u);
    out[u] = ++timer;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1, -1);
    BIT bit(2 * n + 2);
 
    for (int i = 1; i <= n; ++i) {
        bit.add(in[i], val[i]);
        bit.add(out[i] + 1, -val[i]); //As Node weight should not be included when node isn't there
    }
 
    while (q--) {
        int type;
        cin >> type;
 
        if (type == 1) {
            int x;
            int64 y;
            cin >> x >> y;
            int64 diff = y - val[x];
            val[x] = y;
            bit.add(in[x], diff);
            bit.add(out[x] + 1, -diff);
        } else if (type == 2) {
            int u;
            cin >> u;
            cout << bit.sum(in[u]) << "\n";
        }
    }
}
