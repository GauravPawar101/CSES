// Author - Gaurav Pawar

#include <bits/stdc++.h>

using namespace std;

multiset<int> lower;
multiset<int> upper;

void fix() {
    while (lower.size() > upper.size() + 1) {
        int val = *lower.rbegin(); 
        lower.erase(prev(lower.end())); 
        upper.insert(val); 
    }
    
    while (lower.size() < upper.size()) {
        int val = *upper.begin(); 
        upper.erase(upper.begin()); 
        lower.insert(val); 
    }
}

void add(int val) {
    if (lower.empty() || val <= *lower.rbegin()) {
        lower.insert(val);
    } else {
        upper.insert(val);
    }    
    fix();
}

void remove(int val) {
    auto it = lower.find(val);
    if (it != lower.end()) {
        lower.erase(it);
    } else {
        it = upper.find(val);
        if (it != upper.end()) {
            upper.erase(it);
        }
    }
    fix();
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
    
    cout << *lower.rbegin();
    
    for (int i = k; i < n; ++i) {
        remove(arr[i - k]);
        add(arr[i]);
        cout << " " << *lower.rbegin();
    }

    cout << "\n";
    return 0;
}
