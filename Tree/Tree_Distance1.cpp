// Author - Gaurav Pawar 

#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> adj;
 
pair<int, int> find_farthest_node(int u, int parent) {
    pair<int, int> farthest = {0, u}; 
    for (int v : adj[u]) {
        if (v == parent) continue;
        auto temp = find_farthest_node(v, u);
        temp.first += 1; 
        if (temp.first > farthest.first) {
            farthest = temp; 
        }
    }
    return farthest;
}

// Calculates distance to each root
void solve(int u, int parent, int dist, vector<int>& dist_array) {  
    dist_array[u] = dist;
    for (int v : adj[u]) {
        if (v == parent) continue;
        solve(v, u, dist + 1, dist_array);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    vector<int> dist_from_x(n + 1);
    vector<int> dist_from_y(n + 1);
 
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    pair<int, int> farthest_from_1 = find_farthest_node(1, -1);
    int x = farthest_from_1.second;
 
    pair<int, int> farthest_from_x = find_farthest_node(x, -1);
    int y = farthest_from_x.second;
    
    solve(x, -1, 0, dist_from_x);
    solve(y, -1, 0, dist_from_y);
 
    for (int i = 1; i <= n; ++i) {
        cout << max(dist_from_x[i], dist_from_y[i]) << " ";
    }
    cout << "\n";
 
    return 0;
}
