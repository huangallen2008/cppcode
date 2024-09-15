#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,x,x1,x2,x3,a[200001]={};
struct S {
    int l,r,su=0,t1=0,t2=0;
};
S s[800005]={};
void push(S &s1,S &s2,S &s3) {
    if(s1.t1>0) {
        s2.su+=s1.t1*(s2.r-s2.l+1);
        if(s2.t2>0) s2.t2+=s1.t1;
        else s2.t1+=s1.t1;
        s3.su+=s1.t1*(s3.r-s3.l+1);
        if(s3.t2>0) s3.t2+=s1.t1;
        else s3.t1+=s1.t1;
        s1.t1=0;
    }
    if(s1.t2>0) {
        s2.t2=s1.t2;
        s2.su=s2.t2*(s2.r-s2.l+1);
        s2.t1=0;
        s3.t2=s1.t2;
        s3.su=s3.t2*(s3.r-s3.l+1);
        s3.t1=0;
        s1.t2=0;
    }
}
void d(int l,int r,int w) {
    if(l==r) {
        s[w]={l,r,a[l],0,0};
        return;
    }
    int m=(l+r)/2;
    d(l,m,w*2);
    d(m+1,r,w*2+1);
    s[w].l=l; s[w].r=r;
    s[w].su=s[w*2].su+s[w*2+1].su;
}
void u(int ll,int rr,int g,int w) {
    if(ll<=s[w].l && rr>=s[w].r) {
        if(s[w].t2==0) { s[w].su+=g*(s[w].r-s[w].l+1); s[w].t1+=g;}
        else { s[w].t2+=g; s[w].su=s[w].t2*(s[w].r-s[w].l+1); }
        return;
    }
    if(ll>s[w].r || rr<s[w].l) return;
    push(s[w],s[w*2],s[w*2+1]);
    u(ll,rr,g,w*2);
    u(ll,rr,g,w*2+1);
    s[w].su=s[w*2].su+s[w*2+1].su;
}
void se(int ll,int rr,int g,int w) {
    if(ll<=s[w].l && rr>=s[w].r) {
        s[w].t1=0;
        s[w].t2=g;
        s[w].su=s[w].t2*(s[w].r-s[w].l+1);
        return;
    }
    if(ll>s[w].r || rr<s[w].l) return;
    push(s[w],s[w*2],s[w*2+1]);
    se(ll,rr,g,w*2);
    se(ll,rr,g,w*2+1);
    s[w].su=s[w*2].su+s[w*2+1].su;
}
int qu(int y,int z,int w) {
    if(y<=s[w].l && z>=s[w].r) return s[w].su;
    if(z<s[w].l || y>s[w].r) return 0;
    push(s[w],s[w*2],s[w*2+1]);
    return qu(y,z,w*2)+qu(y,z,w*2+1);
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    d(1,n,1);
    for(int i=0;i<q;i++) {
        cin>>x;
        if(x==1) {
            cin>>x1>>x2>>x3;
            u(x1,x2,x3,1);
        }
        else if(x==2) {
            cin>>x1>>x2>>x3;
            se(x1,x2,x3,1);
        }
        else {
            cin>>x1>>x2;
            cout<<qu(x1,x2,1)<<"\n";
        }
        //for(int i=1;i<=13;i++) cout<<s[i].su<<" "; cout<<"\n";
        //for(int i=1;i<=13;i++) cout<<s[i].t1<<" "; cout<<"\n";
        //for(int i=1;i<=13;i++) cout<<s[i].t2<<" "; cout<<"\n";cout<<"\n";
    }
    return 0;
}
