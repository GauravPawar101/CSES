// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

map<int, int> freq;
set<pair<int, int>> st;

void add(int val) {
    int prev = freq[val];
    if (prev > 0) {
        st.erase({-prev, val});
    }
    int cur = ++freq[val];
    st.insert({-cur, val});
}

void remove(int val) {
    int prev = freq[val];
    st.erase({-prev, val});
    int cur = --freq[val];
    if (cur > 0) {
        st.insert({-cur, val});
    } else {
        freq.erase(val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; ++i) {
        add(arr[i]);
    }
    cout << st.begin()->second;

    for (int i = 1; i <= n - k; ++i) {
        remove(arr[i - 1]);
        add(arr[i + k - 1]);
        cout << " " << st.begin()->second;
    }

    cout << "\n";
    return 0;
}
