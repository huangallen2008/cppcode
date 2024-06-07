#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[200001]={};
long long s[800001]={};
void d(int l,int r,int w) {
    if(l==r) {
        s[w]=a[l];
        return;
    }
    int m=(l+r)/2;
    d(l,m,w*2); d(m+1,r,w*2+1);
    s[w]=max(s[w*2],s[w*2+1]);
}
int f(int l,int r,int x,int w) {
    if(l==r) {
        if(a[l]>=x) return l+1;
        else return 0;
    }
    int m=(l+r)/2;
    if(s[2*w]<x) return f(m+1,r,x,w*2+1);
    else return f(l,m,x,w*2);
}
void u(int w) {
    if(w==1) return;
    if(max(s[w],s[w-((w%2)*2-1)])!=s[w/2]) {
        s[w/2]=max(s[w],s[w-((w%2)*2-1)]);
        u(w/2);
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
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    d(0,n-1,1);
    for(int i=0;i<m;i++) {
        cin>>x;
        int an=f(0,n-1,x,1);
        cout<<an<<" ";
        if(an) {
            an--;
            int in=ii(an);
            s[in]-=x;
            a[an]-=x;
            u(in);
        }
    }
    return 0;
}
