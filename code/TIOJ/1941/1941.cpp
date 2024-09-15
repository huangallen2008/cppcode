#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=8e5+5;
const int mod=1e9+9;
struct seg {
    int m=0,t=0;
};
vector<seg> s(maxn*4);
void push(seg &a,seg &b,seg &c) {
    if(a.t) {
        b.t+=a.t;
        b.m+=a.t;
        c.t+=a.t;
        c.m+=a.t;
        a.t=0;
    }
}
void ud(int w,int l,int r,int ul,int ur,int v) {
    if(ul<=l&&r<=ur) {
        s[w].t+=v;
        s[w].m+=v;
        return;
    }
    if(ul>r||ur<l) return;
    push(s[w],s[w*2],s[w*2+1]);
    int m=(l+r)/2;
    ud(w*2,l,m,ul,ur,v);
    ud(w*2+1,m+1,r,ul,ur,v);
    s[w].m=max(s[w*2].m,s[w*2+1].m);
}
void us(int w,int l,int r,int u,int v) {
    if(l==r) {
        s[w].m=v;
        return;
    }
    push(s[w],s[w*2],s[w*2+1]);
    int m=(l+r)/2;
    if(u<=m) us(w*2,l,m,u,v);
    else us(w*2+1,m+1,r,u,v);
    s[w].m=max(s[w*2].m,s[w*2+1].m);
}
int qu(int w,int l,int r,int ql,int qr) {
    if(ql<=l&&r<=qr) return s[w].m;
    if(ql>r||qr<l) return 0;
    push(s[w],s[w*2],s[w*2+1]);
    int m=(l+r)/2;
    return max(qu(w*2,l,m,ql,qr),qu(w*2+1,m+1,r,ql,qr));
}
signed main()
{
    IOS();
    int n;
    cin>>n;
    REP(i,n) {
        int l,r;
        cin>>l>>r;
        if(i<n-1) {
            ud(1,0,n-1,l,r,1);
            us(1,0,n-1,l,max(qu(1,0,n-1,0,l-1)+1,qu(1,0,n-1,l,l)));
        }
        else {
            int an=max(qu(1,0,n-1,0,r)+1,qu(1,0,n-1,r+1,n-1));
            cout<<an<<"\n";
        }
    }
    return 0;
}
