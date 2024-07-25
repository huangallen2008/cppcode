#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,x,y,z,a[200001]={};
int b[200001]={};
int f(int r) {
    int an=0;
    while(r>0) {
        an+=b[r];
        r-=r&-r;
    }
    return an;
}
void u(int r,int t) {
    while(r<=n) {
        b[r]+=t;
        r+=r&-r;
    }
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        u(i,a[i]);
    }
    for(int i=0;i<q;i++) {
        cin>>x>>y>>z;
        if(x==1) {
            u(y,z-a[y]);
            a[y]=z;
        }
        else cout<<f(z)-f(y-1)<<"\n";
    }
    return 0;
}
