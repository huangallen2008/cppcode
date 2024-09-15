#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
const int maxn=1e5+5;
const int mod=1e9+9;
struct seg {
    int l,r;
    int v=0;
    int t1=0;//t1:+ t2:=
    int t2=-1;
};
void push(seg &a,seg &b,seg &c) {
    if(a.t2!=-1) {
        b.v=(b.r-b.l+1)*a.t2;
        b.t1=0,b.t2=0;
        c.v=(c.r-c.l+1)*a.t2;
        c.t1=0,c.t2=0;
        a.t2=-1;
    }
    else if(a.t1) {
        if(b.t2!=-1) b.t2+=a.t1;
        else b.t1+=a.t1;
        b.v+=a.t1*(b.r-b.l+1);
        if(c.t2!=-1) c.t2+=a.t1;
        else c.t1+=a.t1;
        c.v+=a.t1*(c.r-c.l+1);
        a.t1=0;
    }
}
vector<seg> s(maxn*4);
void build(int w,int l,int r) {
    s[w]={l,r,0,0,-1};
    if(l==r) return;
    int m=(l+r)/2;
    build(w*2,l,m);
    build(w*2+1,m+1,r);
}
void ad(int w,int ul,int ur) {
    if(ul<=s[w].l&&s[w].r<=ur) {
        if(s[w].t2!=-1) s[w].t2++;
        else s[w].t1++;
        s[w].v+=s[w].r-s[w].l+1;
        return;
    }
    if(ul>s[w].r||ur<s[w].l) return;
    if(ul>ur) return;
    push(s[w],s[w*2],s[w*2+1]);
    ad(w*2,ul,ur);
    ad(w*2+1,ul,ur);
    s[w].v=s[w*2].v+s[w*2+1].v;
}
void ud(int w,int ul,int ur) {
    if(ul<=s[w].l&&s[w].r<=ur) {
        s[w].t1=0;
        s[w].t2=0;
        s[w].v=0;
        return;
    }
    if(ul>s[w].r||ur<s[w].l) return;
    if(ul>ur) return;
    push(s[w],s[w*2],s[w*2+1]);
    ud(w*2,ul,ur);
    ud(w*2+1,ul,ur);
    s[w].v=s[w*2].v+s[w*2+1].v;
}
int qu() {
    return s[1].v;
}
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> o(n);
    REP(i,n) {
        REP(j,n) {
            char c;
            cin>>c;
            if(c=='#') o[i].pb(j);
        }
        o[i].pb(n);
    }
    int an=0;
    REP(i,n) {
        build(1,0,n-1);
        REP(j,n) {
            int id=*lower_bound(ALL(o[j]),i);
            ad(1,i,id-1);
            ud(1,id,n-1);
            an+=qu();
        }
    }
    cout<<an<<"\n";
    return 0;
}
