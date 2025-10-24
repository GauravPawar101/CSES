// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
 
static const int MAXN = 200000 + 5;
int n, k;
vector<int> adj[MAXN];
int sub[MAXN];
bool dead[MAXN];
int64 ans = 0;
 
int64 freq[MAXN];
vector<int> temp_paths;
vector<int> all_paths; 
 
void dfs_size(int u, int p) {
    sub[u] = 1;
    for (int v : adj[u]) {
        if (v == p || dead[v]) continue;
        dfs_size(v, u);
        sub[u] += sub[v];
    }
}
 
int find_centroid(int u, int p, int n) {
    for (int v : adj[u]) {
        if (v == p || dead[v]) continue;
        if (sub[v] > n / 2) {
            return find_centroid(v, u, n);
        }
    }
    return u;
}
 
void get_paths(int u, int p, int len) {
    if (len > k) return;
    temp_paths.push_back(len);
    for (int v : adj[u]) {
        if (v == p || dead[v]) continue;
        get_paths(v, u, len + 1);
    }
}
 
void solve(int c) {
    freq[0] = 1;
    all_paths.clear();
 
    for (int v : adj[c]) {
        if (dead[v]) continue;
        
        temp_paths.clear();
        get_paths(v, c, 1);
        
        for (int len : temp_paths) {
            if (k - len >= 0) {
                ans += freq[k - len];
            }
        }
        
        for (int len : temp_paths) {
            freq[len]++;
            all_paths.push_back(len);
        }
    }
 
    for (int len : all_paths) {
        freq[len] = 0;
    }
    freq[0] = 0;
}

// Solve for each centroid troubling at first sight takes time to grasp
void decompose(int u) {
    dfs_size(u, -1);
    int c = find_centroid(u, -1, sub[u]);
    
    dead[c] = true;
    solve(c);
 
    for (int v : adj[c]) {
        if (!dead[v]) {
            decompose(v);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    decompose(1);
    cout << ans << "\n";
 
    return 0;
