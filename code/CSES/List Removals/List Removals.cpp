#include <bits/stdc++.h>
using namespace std;
int n,x,a[200001]={},s[8000001]={};
void u(int l,int r,int x,int w) {
    if(l<=x && x<=r) {
        s[w]++;
        if(l==r) return;
        int m=(l+r)/2;
        u(l,m,x,w*2);
        u(m+1,r,x,w*2+1);
    }
}
int q(int l,int r,int x,int w,int su) {
    if(l==r) return l;
    int m=(l+r)/2;
    if(m+1-su-s[w*2]>=x) return q(l,m,x,w*2,su);
    else return q(m+1,r,x,w*2+1,su+s[w*2]);
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) {
        cin>>x;
        int an=q(0,n-1,x,1,0);
        cout<<a[an]<<" ";
        u(0,n-1,an,1);
    }
    return 0;
}
