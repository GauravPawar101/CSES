// Author - Gaurav Pawar 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

struct LiChao {
    struct Node { ll m, b; int L=-1, R=-1; Node():m(0),b(NEG_INF),L(-1),R(-1){} };
    vector<Node> pool;
    int root;
    int DL, DR;

    LiChao(int dl, int dr, size_t reserve_nodes = 0) : DL(dl), DR(dr) {
        if (reserve_nodes) pool.reserve(reserve_nodes);
        root = newNode();
    }

    inline int newNode() { pool.emplace_back(); return (int)pool.size() - 1; }

    inline ll eval_line(const Node &nd, ll x) const {
        if (nd.b == NEG_INF) return NEG_INF;
        return (ll)((__int128)nd.m * x + nd.b);
    }

    void insert_line(int idx, int l, int r, ll m, ll b) {
        if (idx == -1) return;
        int mid = (l + r) >> 1;
        Node &cur = pool[idx];

        ll curMid = eval_line(cur, mid);
        ll newMid = (__int128)m * mid + b;
        if (newMid > curMid) {
            swap(cur.m, m);
            swap(cur.b, b);
        }
        if (l == r) return;

        ll curL = eval_line(cur, l);
        ll newL = (__int128)m * l + b;
        if (newL > curL) {
            if (cur.L == -1) cur.L = newNode();
            insert_line(cur.L, l, mid, m, b);
        } else {
            ll curR = eval_line(cur, r);
            ll newR = (__int128)m * r + b;
            if (newR > curR) {
                if (cur.R == -1) cur.R = newNode();
                insert_line(cur.R, mid + 1, r, m, b);
            }
        }
    }

    void insert_segment(int &node, int l, int r, int ql, int qr, ll m, ll b) {
        if (qr < l || ql > r) return;
        if (node == -1) node = newNode();
        if (ql <= l && r <= qr) {
            insert_line(node, l, r, m, b);
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) insert_segment(pool[node].L, l, mid, ql, qr, m, b);
        if (qr  > mid) insert_segment(pool[node].R, mid + 1, r, ql, qr, m, b);
    }

    void addLine(ll m, ll b, int ql, int qr) {
        if (ql > qr) return;
        if (ql < DL) ql = DL;
        if (qr > DR) qr = DR;
        insert_segment(root, DL, DR, ql, qr, m, b);
    }

    ll query_rec(int node, int l, int r, int x) const {
        if (node == -1) return NEG_INF;
        const Node &nd = pool[node];
        ll res = eval_line(nd, x);
        if (l == r) return res;
        int mid = (l + r) >> 1;
        if (x <= mid) {
            return max(res, nd.L == -1 ? NEG_INF : query_rec(nd.L, l, mid, x));
        } else {
            return max(res, nd.R == -1 ? NEG_INF : query_rec(nd.R, mid + 1, r, x));
        }
    }

    ll queryMax(int x) const {
        if (x < DL || x > DR) return NEG_INF;
        return query_rec(root, DL, DR, x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    map<int, vector<int>> value_positions;
    for (int i = 0; i < n; ++i) value_positions[arr[i]].push_back(i);

    size_t estimate = (size_t)n * 6;
    LiChao tree(0, n, estimate);

    set<int> occupied;
    for (int i = -1; i <= n; ++i) occupied.insert(i);

    for (auto it = value_positions.rbegin(); it != value_positions.rend(); ++it) {
        int value = it->first;
        vector<int>& positions = it->second;

        for (int pos : positions) occupied.erase(pos);

        for (int pos : positions) {
            auto upper_it = occupied.upper_bound(pos);
            int rightOccupied = *upper_it;
            int leftOccupied = *prev(upper_it);
            int left = leftOccupied + 1;
            int right = rightOccupied - 1;

            int L1 = max(0, left - k + 1);
            int R1 = min(left, right - k + 1);
            if (R1 >= L1) tree.addLine(value, (ll)(k - left) * value, L1, R1);

            if (right - left + 1 >= k) {
                int L2 = left;
                int R2 = right - k + 1;
                tree.addLine(0, (ll)k * value, L2, R2);
            }

            int L3 = max(left, right - k + 1);
            int R3 = right;
            if (R3 >= L3) tree.addLine(-value, (ll)(right + 1) * value, L3, R3);

            int L4 = right - k + 1;
            int R4 = left;
            if (L4 <= R4) tree.addLine(0, (ll)(right - left + 1) * value, L4, R4);
        }
    }

    for (int i = 0; i + k - 1 < n; ++i) {
        if (i) cout << ' ';
        cout << tree.queryMax(i);
    }
    cout << '\n';
    return 0;
}
