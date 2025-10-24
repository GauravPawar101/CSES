// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
const int LOG = 20;
 
int up[N][LOG];   
int depth[N];     
vector<int> adj[N];
int n, q;

// Creating Query DS
void dfs(int u, int p) {
    up[u][0] = p;
    for (int j = 1; j < LOG; j++) {
        up[u][j] = up[ up[u][j-1] ][j-1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

// Binary Lifting
int lift(int u, int k) {
    for (int j = 0; j < LOG; j++) {
        if (k & (1 << j)) u = up[u][j];
        if (u == 0) break; 
    }
    return u;
}

// Core LCA
int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
 
    a = lift(a, depth[a] - depth[b]);
    if (a == b) return a;
 
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
 
    return up[a][0];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> q;
 
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        adj[i].push_back(boss);
        adj[boss].push_back(i);
    }
 
    depth[1] = 0;
    dfs(1, 0); 

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
