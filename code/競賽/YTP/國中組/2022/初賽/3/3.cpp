#include<bits/stdc++.h>
using namespace std;
int n,a[500001]={},q,l,r;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cin>>q;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=0;i<q;i++) {
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<"\n";
    }
    return 0;
}
