#include <bits/stdc++.h>
using namespace std;
int n,q,x,y,a[200001]={};
long long s[800001]={};
void d(int l,int r,int w) {
    if(l==r) {
        s[w]=a[l];
        return;
    }
    int m=(l+r)/2;
    d(l,m,w*2); d(m+1,r,w*2+1);
    s[w]=min(s[w*2],s[w*2+1]);
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
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    d(0,n-1,1);
    for(int i=0;i<q;i++) {
        cin>>x>>y;
        cout<<f(0,n-1,x-1,y-1,1)<<"\n";
    }
    return 0;
}
