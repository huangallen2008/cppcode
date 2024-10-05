#include <bits/stdc++.h>
using namespace std;
int n,q,x,y,z,a[200001]={},s[800001]={};
void d(int l,int r,int w) {
    if(l==r) {
        s[w]=a[r];
        return;
    }
    int m=(l+r)/2;
    d(l,m,w*2); d(m+1,r,w*2+1);
    s[w]=min(s[w*2],s[w*2+1]);
}
void u(int w,int z) {
    if(w==1) return;
    if(min(s[w],s[w-((w%2)*2-1)])!=s[w/2]) {
        s[w/2]=min(s[w],s[w-((w%2)*2-1)]);
        u(w/2,z);
    }
}
int ii(int t) {
    int l=0,r=n-1,m,an=1;
    while(l<r) {
        m=(l+r)/2;
        an*=2;
        if(t<=m) r=m;
        else {
            an++;
            l=m+1;
        }
    }
    return an;
}
int f(int l,int r,int x,int y,int w) {
    int m=(l+r)/2;
    if(x<=l && y>=r) return s[w];
    if(x<=m && y>m) return min(f(l,m,x,y,w*2),f(m+1,r,x,y,w*2+1));
    if(y<=m) return f(l,m,x,y,w*2);
    if(x>m) return f(m+1,r,x,y,w*2+1);
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    d(0,n-1,1);
    for(int i=0;i<q;i++) {
        cin>>x>>y>>z;
        if(x==1) {
            int in=ii(y-1); s[in]=z;
            u(in,z);
            a[y-1]=z;
        }
        else cout<<f(0,n-1,y-1,z-1,1)<<"\n";
    }
    return 0;
}
