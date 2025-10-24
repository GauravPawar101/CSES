#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
vector<int> dp0, dp1;
// dp0 - i is included
// dp1 - i is not included

int dfs(int u, int parent) {
    int sum1 = 0;
 
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        sum1 += max(dp0[v], dp1[v]);
    }
 
    dp1[u] = sum1;
    dp0[u] = 0;
 
    for (int v : adj[u]) {
        if (v == parent) continue;
        int tmp = 1 + dp1[v]; 
        tmp += sum1 - max(dp0[v], dp1[v]);
        dp0[u] = max(dp0[u], tmp);
    }
 
    return 0;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    dp0.assign(n + 1, 0);
    dp1.assign(n + 1, 0);
 
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    dfs(1, -1);
 
    cout << max(dp0[1], dp1[1]) << "\n";
    return 0;
}
