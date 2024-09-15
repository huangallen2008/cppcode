#include <bits/stdc++.h>
using namespace std;
int n,q,x,y;
long long s[200001]={};
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>x;
        s[i]=s[i-1]+x;
    }
    for(int i=0;i<q;i++) {
        cin>>x>>y;
        cout<<s[y]-s[x-1]<<"\n";
    }
    return 0;
}
