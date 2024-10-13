#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,sse4,sse4.1,sse4.2,bmi,bmi2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#ifdef LOCAL_
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=1ll<<62;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int x1,x2,c0,y0;
        pii cal(int y) {
            if(y<x1) return {c0-y,y0};
            if(y<x2) return {c0-x1,y0+y-x1};
            return {c0-x1,y0+x2-x1};
        }
    };
    int n,m;
    vector<Seg> s;
    Seg merge(Seg b,Seg c) {
        Seg a;
        pii ret0=b.cal(0);
        pii ret=c.cal(ret0.s);
        a.c0=ret0.f+ret.f,a.y0=ret.s;
        a.x1=min(b.x1,max(0ll,c.x1-ret0.s));
        a.x2=b.x2-max(b.cal(b.x2).s-c.x2,0ll);
        op(b.x1)op(b.x2)op(b.c0)ope(b.y0)
        op(c.x1)op(c.x2)op(c.c0)ope(c.y0)
        op(a.x1)op(a.x2)op(a.c0)ope(a.y0)
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    void build(int w,int l,int r,Vi &a) {
        if(l==r) {
            if(a[l]<0) s[w]={-a[l],m+1,-a[l],0};
            else s[w]={0,m-a[l],0,a[l]};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        op(l)ope(r)
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,int _m,vector<int> &a) {
        n=_n,m=_m;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,a);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            if(v<0) s[w]={-v,m+1,-v,0};
            else s[w]={0,m-v,0,v};
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return Seg({0,m+1,0,0});
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    pii qu(int l,int r,int y) {
        Seg ret=_qu(1,0,n-1,l,r);
        op(ret.x1)op(ret.x2)op(ret.c0)ope(ret.y0)
        return ret.cal(y);
    }
}seg;
signed main() {
    IOS(); 
    int n,m,q;
    cin>>n>>q>>m;
    Vi a(n);
    REP(i,n) cin>>a[i],a[i]=-a[i];
    seg.init(n,m,a);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int p,x;
            cin>>p>>x,p--;
            seg.ud(p,-x);
        }
        else {
            int l,r,y;
            cin>>l>>r>>y,l--,r--;
            pii ret=seg.qu(l,r,y);
            cout<<ret.f<<' '<<ret.s<<'\n';
        }
    }
    return 0;
}