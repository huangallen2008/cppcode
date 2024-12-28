#include <bits/stdc++.h>
using namespace std;

signed main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    .
    .
    .
}
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ve;
    for (int i=0;i<n;i++) {
        int x;
        cin >> x;
        ve.push_back({x, i});
    }
    sort(ve.begin(), ve.end());
    reverse(ve.begin(), ve.end());
    cout << ve[k-1].first << "\n";
    vector<int> idx;
    for (int i=0;i<k;i++) {
        idx.push_back(ve[i].second);
    }
    sort(idx.begin(), idx.end());
    for (int i:idx) {
        cout << i+1 << " ";
    }
    cout << "\n";
}