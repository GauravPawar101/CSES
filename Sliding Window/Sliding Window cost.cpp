// Author - Gaurav Pawar

#include <bits/stdc++.h>
using namespace std;

multiset<long long> lower;
multiset<long long> upper;
long long lower_sum = 0;
long long upper_sum = 0;

void fix() {
    while (lower.size() > upper.size() + 1) {
        long long val = *lower.rbegin(); 
        lower.erase(prev(lower.end())); 
        lower_sum -= val;
        upper.insert(val);
        upper_sum += val;
    }
    
    while (lower.size() < upper.size()) {
        long long val = *upper.begin(); 
        upper.erase(upper.begin()); 
        upper_sum -= val;
        lower.insert(val); 
        lower_sum += val;
    }
}

void add(long long val) {
    if (lower.empty() || val <= *lower.rbegin()) {
        lower.insert(val);
        lower_sum += val;
    } else {
        upper.insert(val);
        upper_sum += val;
    }    
    fix();
}

void remove(long long val) {
    auto it = lower.find(val);
    if (it != lower.end()) {
        lower.erase(it);
        lower_sum -= val;
    } else {
        it = upper.find(val);
        if (it != upper.end()) {
            upper.erase(it);
            upper_sum -= val;
        }
    }
    fix();
}

long long getCost() {
    long long median = *lower.rbegin();
    long long cost = (long long)median * lower.size() - lower_sum;
    cost += upper_sum - (long long)median * upper.size();
    
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < k; ++i) {
        add(arr[i]);
    }
    
    cout << getCost();
    
    for (int i = k; i < n; ++i) {
        remove(arr[i - k]);
        add(arr[i]);
        cout << " " << getCost();
    }

    cout << "\n";
    return 0;
}
