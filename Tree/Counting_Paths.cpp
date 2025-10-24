// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
const int LOG = 20;
 
vector<int> adj[N];
int up[N][LOG];
int depth[N];
int cnt[N];
int n, q;

// Build up Query DS
void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; i++)
        up[u][i] = up[u][i - 1] ? up[up[u][i - 1]][i - 1] : 0;
 
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
 
int lift(int u, int k) {
    for (int i = 0; i < LOG; i++)
        if (k & (1 << i))
            u = up[u][i];
    return u;
}
 
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = lift(a, depth[a] - depth[b]);
    if (a == b) return a;
 
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

// Accumulate Paths
void dfs_accumulate(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs_accumulate(v, u);
        cnt[u] += cnt[v];
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    depth[1] = 0;
    dfs(1, 0);
 
    while (q--) {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        cnt[a]++;
        cnt[b]++;
        cnt[c]--;  // To stop double Counting
        if (up[c][0] != 0)
            cnt[up[c][0]]--;
    }
 
    dfs_accumulate(1, 0);
 
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << " ";
    cout << "\n";
