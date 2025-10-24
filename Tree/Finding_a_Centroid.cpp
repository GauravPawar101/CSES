// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
 
static const int MAXN = 200000 + 5;
int n; 
vector<int> adj[MAXN];
int val[MAXN], sub[MAXN];
 
void dfs_size(int u, int p) {
    sub[u] = 1;
    for (int v: adj[u]) {
        if (v == p) continue; 
        
        dfs_size(v, u);    
        sub[u] += sub[v];
    }
}

// Any Node with subtree size <= n/2 
int find_centroid(int u, int p) {
    for (int v: adj[u]) {
        if (v == p) continue; 
        if (sub[v] > n / 2) {
            return find_centroid(v, u);
        }
    }
    return u;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n; 
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs_size(1, 0); 
    cout << find_centroid(1, 0);
    cout << '\n';
}
    return 0;
