#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
struct SEG {
    struct Seg {
        int l,r,t,mx;
        ll v;
        Seg() {}
        Seg(int _l,int _r,int _v,int _t,int _mx):l(_l),r(_r),v(_v),t(_v),mx(_mx) {}
    };
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t==-1) return;
        b.t=a.t;
        b.v=(ll)a.v*(b.r-b.l+1);
        b.mx=a.t;
        c.t=b.t;
        c.v=(ll)a.v*(c.r-c.l+1);
        c.mx=a.t;
        a.t=-1;
    }
    vector<Seg> s;
    void init(int n) {
        s=vector<Seg>(n<<2);
    }
    void build(int w,int l,int r) {
        s[w]=Seg(l,r,0,-1,0);
        if(l==r) return;
        int m=(l+r)>>1;
        build(w<<1,l,m);
        build((w<<1)|1,m+1,r);
    }
    void ud(int w,int l,int r,int ul,int ur,int v) {
        if(ul<=l&&r<=ur) {
            s[w].t=v;
            s[w].v=(ll)v*(r-l+1);
            s[w].mx=v;
            return;
        }
        if(ul>r||ur<l) return;
        push(s[w],s[w<<1],s[(w<<1)|1]);
        int m=(l+r)>>1;
        ud(w<<1,l,m,ul,ur,v);
        ud((w<<1)|1,m+1,r,ul,ur,v);
        s[w].v=s[w<<1].v+s[(w<<1)|1].v;
        s[w].mx=max(s[w<<1].mx,s[(w<<1)|1].mx);
    }
    int lb(int w,int l,int r,int v) {
        if(l==r) return l;
        int m=(l+r)>>1;
        push(s[w],s[w<<1],s[(w<<1)|1]);
        if(s[w<<1].mx>v) return lb(w<<1,l,m,v);
        else return lb((w<<1)|1,m+1,r,v);
    }
    ll get_sum() {
        return s[1].v;
    }
};
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    SEG seg;
    seg.init(n<<1);
    seg.build(1,0,(n<<1)-1);
    int mex=0;
    vector<bool> cnt(n+1);
    REP(i,n) {
        cnt[a[i]]=1;
        while(cnt[mex]) mex++;
        seg.ud(1,0,(n<<1)-1,i,i,mex);
    }
    ll an=seg.get_sum();
    REP(i,n-1) {
        int id=seg.lb(1,0,(n<<1)-1,a[i]);
        seg.ud(1,0,(n<<1)-1,id,i+n-1,a[i]);
        seg.ud(1,0,(n<<1)-1,i,i,0);
        seg.ud(1,0,(n<<1)-1,i+n,i+n,n);
        an=max(an,seg.get_sum());
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
