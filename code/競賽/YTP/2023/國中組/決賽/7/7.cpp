#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
//#define int long long
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
const ll inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+9;
ll f(const int x) {
    const ll t=x>>1;
    if(x&1) return t*t+(ll)x;
    else return t*t+t;
}
struct seg {
    ll v;
    int p,s;
    bool a;
    int t;
    int len;
};
seg s[maxn<<2];
//vector<seg> s(maxn<<2);
void pull(seg &a,seg &b,seg &c) {//a=b+c;
    if(b.a) {
        if(c.a) {
            a.v=0;
            a.p=0;
            a.s=0;
            a.a=1;
        }
        else {
            a.v=c.v;
            a.p=b.len+c.p;
            a.s=c.s;
            a.a=0;
        }
    }
    else {
        if(c.a) {
            a.v=b.v;
            a.p=b.p;
            a.s=b.s+c.len;
            a.a=0;
        }
        else {
            a.v=b.v+c.v+f(b.s+c.p);
            a.p=b.p;
            a.s=c.s;
            a.a=0;
        }
    }
}
void push(seg &a,seg &b,seg &c) {
    if(a.t!=-1) {
        if(a.t==0) {
            b.v=0;
            b.p=0;
            b.s=0;
            b.a=0;
            b.t=a.t;
            c.v=0;
            c.p=0;
            c.s=0;
            c.a=0;
            c.t=a.t;
        }
        else {
            b.v=0;
            b.p=0;
            b.s=0;
            b.a=1;
            b.t=a.t;
            c.v=0;
            c.p=0;
            c.s=0;
            c.a=1;
            c.t=a.t;
        }
        a.t=-1;
    }
}
void build(const int w,const int l,const int r) {
    s[w]={0,0,0,0,-1,r-l+1};
    if(l==r) return;
    int m=(l+r)>>1;
    build(w<<1,l,m);
    build(w<<1|1,m+1,r);
}
void ud(const int w,const int l,const int r,const int ul,const int ur,const bool v) {
    if(ul<=l&&r<=ur) {
        if(v) {
            s[w].v=0;
            s[w].p=0;
            s[w].s=0;
            s[w].a=1;
            s[w].t=1;
        }
        else {
            s[w].v=0;
            s[w].p=0;
            s[w].s=0;
            s[w].a=0;
            s[w].t=0;
        }
        return;
    }
    if(ul>r||ur<l) return;
    int m=(l+r)>>1;
    push(s[w],s[w<<1],s[w<<1|1]);
    ud(w<<1,l,m,ul,ur,v);
    ud(w<<1|1,m+1,r,ul,ur,v);
    pull(s[w],s[w<<1],s[w<<1|1]);
}
ll qu() {
    return s[1].v;
}
signed main()
{
    IOS();
    int n,q;
    cin>>n>>q;
    build(1,0,n-1);
    REP(i,q) {
        int x,y,z;
        cin>>x>>y>>z;
        y--,z--;
        ud(1,0,n-1,y,z,x&1);
        cout<<qu()<<'\n';
    }
    return 0;
}
