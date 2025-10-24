#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<vector<int>> adj;
vector<int> dp;
 
int solve(int node, int parent) {
    if (adj[node].size() == 0) return 1;
    int cnt = 0;
    for (int nr : adj[node]) {
        if (nr == parent) continue;
        cnt += 1 + solve(nr, node);
    }
    return dp[node] = cnt;
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1);
 
    for (int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    solve(1, -1);
    for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
    cout << "\n";
 
    return 0;
}
