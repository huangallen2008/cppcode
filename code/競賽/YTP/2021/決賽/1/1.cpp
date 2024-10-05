#include<bits/stdc++.h>
using namespace std;
int n,a[1000001]={},an=0;
unordered_map<int,int> m;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        m[a[i]]++;
        an=max(an,m[a[i]]);
    }
    cout<<an;
    return 0;
}
