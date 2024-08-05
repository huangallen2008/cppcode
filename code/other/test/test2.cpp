#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int mx=a[0];
    vector<int> d(n);
    d[0]=-2e9;
    for(int i=1;i<n;i++) {
        d[i]=max(d[i-1],mx-a[i]);
        mx=max(mx,a[i]);
    }
    while(q--) {
        int k;
        cin>>k;
        k--;
        cout<<d[k]<<' ';
    }
    return 0;
}