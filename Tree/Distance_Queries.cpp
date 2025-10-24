// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
const int LOG = 20;
 
vector<int> adj[N];
vector<int> euler, depth_euler;
int first[N], depth[N];
int st[2*N][LOG];
 
void dfs(int u, int p, int d) {
    depth[u] = d;
    first[u] = euler.size();
    euler.push_back(u);
    depth_euler.push_back(d);
 
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d+1);
        euler.push_back(u);
        depth_euler.push_back(d);
    }
}
 
void build_rmq() {
    int m = euler.size();
    for (int i = 0; i < m; i++) st[i][0] = i;
 
    for (int j = 1; (1 << j) <= m; j++) {
        for (int i = 0; i + (1 << j) <= m; i++) {
            int x = st[i][j-1], y = st[i + (1<<(j-1))][j-1];
            st[i][j] = (depth_euler[x] < depth_euler[y]) ? x : y;
        }
    }
}
 
int query_rmq(int l, int r) {
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len);
    int x = st[l][k], y = st[r-(1<<k)+1][k];
    return (depth_euler[x] < depth_euler[y]) ? x : y;
}
 
int lca(int u, int v) {
    int l = first[u], r = first[v];
    if (l > r) swap(l, r);
    return euler[query_rmq(l, r)];
}

// Dist = depth(a) + depth(b) - 2 * (depth(LCA(a, b))
int dist(int a, int b) {
    int anc = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[anc];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1, 0, 0);
    build_rmq();
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dist(a, b) << "\n";
    }
