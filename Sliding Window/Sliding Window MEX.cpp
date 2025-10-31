// Author - Gaurav Pawar
 
#include <bits/stdc++.h>
 
using namespace std;
 
map<int, int> freq;
set<int> st;
 
void add(int val, int k) {
    freq[val]++;
    if (freq[val] == 1 && val <= k) {
        st.erase(val);
    }
}
 
void remove(int val, int k) {
    freq[val]--;
    if (freq[val] == 0 && val <= k) {
        st.insert(val);
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
 
    for (int i = 0; i <= k; ++i) {
        st.insert(i);
    }
 
    for (int i = 0; i < k; ++i) {
        add(arr[i], k);
    }
 
    cout << *st.begin();
 
    for (int i = k; i < n; ++i) {
        remove(arr[i - k], k);
        add(arr[i], k);
        cout << " " << *st.begin();
    }
 
    cout << "\n";
    return 0;
}
