#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,x,y,z;
struct S {
    int an=0,su=0;
};
S s[800001]={};
void pull(S &s1,S s2,S s3) {
    s1.an=max(s2.an,s2.su+s3.an);
    s1.su=s2.su+s3.su;
}
void u(int l,int r,int k,int g,int w) {
    if(l==r && l==k) {
        s[w]={max(g,(long long)0),g};
        return;
    }
    int m=(l+r)/2;
    if(k<=m) u(l,m,k,g,w*2);
    else u(m+1,r,k,g,w*2+1);
    pull(s[w],s[w*2],s[w*2+1]);
}
S ma(S s1,S s2) {
    return {max(s1.an,s1.su+s2.an),s1.su+s2.su};
}
S qu(int l,int r,int y,int z,int w) {
    if(y<=l && z>=r) return s[w];
    if(z<l || y>r) return {0,0};
    int m=(l+r)/2;
    return ma(qu(l,m,y,z,w*2),qu(m+1,r,y,z,w*2+1));
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>q;
    for(int i=0;i<n;i++) {
        cin>>x;
        u(0,n-1,i,x,1);
    }
    for(int i=0;i<q;i++) {
        cin>>x>>y>>z;
        if(x==1) u(0,n-1,y-1,z,1);
        else cout<<qu(0,n-1,y-1,z-1,1).an<<"\n";
    }
    return 0;
}
