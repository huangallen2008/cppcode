#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005]={};
struct d {
    int an=0,mf=0,mb=0,s=0;
    d(int an2,int mf2,int mb2,int s2) {
        an=an2; mf=mf2; mb=mb2; s=s2;
    }
};
d ll(0,0,0,0);
d f(int l,int r) {
    if(l==r) {
        ll.an=a[l]; ll.mf=a[l]; ll.mb=a[l]; ll.s=a[l];
        return ll;
    }
    int m=(l+r)/2;
    d x=f(l,m),y=f(m+1,r),t(0,0,0,0);
    t.an=max(max(x.an,y.an),x.mb+y.mf),t.mf=max(x.s+y.mf,x.mf),t.mb=max(y.s+x.mb,y.mb),t.s=x.s+y.s;
    return t;
}
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<f(0,n-1).an<<"\n";
    return 0;
}
