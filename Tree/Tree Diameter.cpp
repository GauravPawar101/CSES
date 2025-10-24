#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
 
pair<int, int> dfs(int u, int parent) {
    pair<int, int> farthest = {0, u};
    for (int v : adj[u]) {
        if (v == parent) continue;
        auto temp = dfs(v, u);
        temp.first += 1;
        if (temp.first > farthest.first) farthest = temp;
    }
    return farthest;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    adj.assign(n + 1, {});
 
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    auto first = dfs(1, -1);
    auto second = dfs(first.second, -1);
    cout << second.first << "\n";
 
    return 0;
}
