// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 5;
vector<int> adj[N];
vector<long long> ans(N), sub(N);
int n;
 
void dfs1(int u, int p, int d) {
    ans[1] += d;
    sub[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u, d + 1);
        sub[u] += sub[v];
    }
}
 
void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] + n - 2 * sub[v];  // ans(i) = ans(parent(i)) - subtree(i) + n - subtree(i)
        dfs2(v, u);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs1(1, 0, 0);  // Calculate subtree sizes
    dfs2(1, 0);     // Calculate ans
 
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}
