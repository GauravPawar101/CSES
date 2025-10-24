// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
 
static const int MAXN = 200000 + 5;
int n; 
vector<int> adj[MAXN];
int val[MAXN], sub[MAXN];
 
vector<unordered_set<int>> color_sets;

// Small to large merging - turns out if we just copy light children it degrades to log n instead of n
void dfs_merge(int u, int p) {
    int heavy_child = -1;
    int max_size = 0;
 
    for (int v : adj[u]) {
        if (v == p) continue;
        
        dfs_merge(v, u); 
 
        if (color_sets[v].size() > max_size) {
            max_size = color_sets[v].size();
            heavy_child = v;
        }
    }
 
    if (heavy_child != -1) {
        color_sets[u].swap(color_sets[heavy_child]);
    }
 
    for (int v : adj[u]) {
        if (v == p || v == heavy_child) continue;
 
        color_sets[u].insert(color_sets[v].begin(), color_sets[v].end());
    }
 
    color_sets[u].insert(val[u]);
 
    sub[u] = color_sets[u].size();
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n; 
    color_sets.resize(n + 1); 
 
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
 
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs_merge(1, 0); 
 
    for (int i = 1; i <= n; ++i) {
        cout << sub[i] << " ";
    }
    cout << '\n';
 
    return 0;
}
