#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=3e5+5;
const ll mod=1e9+7;
struct seg {
    int l,r;
    int v=0;
    int t1=0;
    int t2=0;
};
seg s[maxn*4];
void pull(seg &a,seg &b,seg &c) {
    a.v=b.v+c.v;
}
void push(seg &a,seg &b,seg &c) {
    if(a.t2) {
        int r=(1<<a.t2);
        b.v*=r;
        b.t1*=r;
        b.t2+=a.t2;
        c.v*=r;
        c.t1*=r;
        c.t2+=a.t2;
        a.t2=0;
    }
    if(a.t1) {
        b.v+=a.t1*(b.r-b.l+1);
        b.t1+=a.t1;
        c.v+=a.t1*(c.r-c.l+1);
        c.t1+=a.t1;
        a.t1=0;
    }
}
void build(int w,int l,int r) {
    s[w]={l,r,0,0,0};
    if(l==r) return;
    int m=(l+r)/2;
    build(w*2,l,m);
    build(w*2+1,m+1,r);
}
void ud(int w,int ul,int ur) {
    if(ul<=s[w].l&&s[w].r<=ur) {
        s[w].v+=(s[w].r-s[w].l+1);
        s[w].t1++;
        return;
    }
    if(s[w].l>ur||s[w].r<ul) return;
    push(s[w],s[w*2],s[w*2+1]);
    ud(w*2,ul,ur);
    ud(w*2+1,ul,ur);
    pull(s[w],s[w*2],s[w*2+1]);
}
int qu(int w,int ql,int qr) {
    if(ql<=s[w].l&&s[w].r<=qr) return s[w].v;
    if(s[w].l>qr||s[w].r<ql) return 0;
    push(s[w],s[w*2],s[w*2+1]);
    return qu(w*2,ql,qr)+qu(w*2+1,ql,qr);
}
signed main()
{
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<vector<pii>> o(n);
    vector<int> an(n);
    vector<int> nxt(n),nw(n+1,n);
    build(1,0,n-1);
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        l--,r--;
        o[l].pb({r,i});
    }
    RREP(i,n) {
        nxt[i]=nw[a[i]];
        nw[a[i]]=i;
    }
    cout<<"n:";REP(i,n) cout<<nxt[i]<<" ";cout<<endl;
    RREP(i,n) {
        ud(1,i,nxt[i]-1);
        REP(j,o[i].size()) an[o[i][j].s]=qu(1,i,o[i][j].f);
        REP(j,n) cout<<qu(1,j,j)<<" ";cout<<endl;
        s[1].t2++;
        s[1].v*=2;
        s[1].t1*=2;
    }
    REP(i,q) cout<<an[i]<<"\n";
    return 0;
}
/*
3 4
1 2 1
1 3
2 3
1 1
1 3
*/
