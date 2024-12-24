#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vpii vector<pii>
#ifdef LOCAL_
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define pVi pair<Vi,Vi>
const Vpii zero = Vpii(maxb,{0,inf});
struct SEG {
    int n;
    vector<Vpii> s;
    Vpii merge(Vpii b,Vpii c) {
        Vpii a=zero;
        REP(i,maxb) chmin(a[i].s,b[i].s),chmin(a[i].s,c[i].s);
        REP(i,maxb) REP(j,maxb) if(b[i].f&&c[j].f)chmin(a[i^j].s,b[i].s+c[j].s);
        oparr(a)oparr(b)oparr(c)
        REP(i,maxb) REP(j,maxb) if(b[i].f&&c[j].f)if(b[i].s+c[j].s==a[i^j].s) (a[i^j].f+=b[i].f*c[j].f)%=mod;
        REP(i,maxb) (a[i].f+=b[i].f+c[i].f)%=mod;
        return a;
    }
    void pull(Vpii &a,Vpii b,Vpii c) {
        a=merge(b,c);
    }
    void build(int w,int l,int r,Vi &a) {
        if(l==r) {
            s[w][a[l]]={1,1};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
        op(w)oparr(s[w])
    }
    void init(int _n,Vi a) {
        n=_n;
        s=vector<Vpii>(n<<2,zero);
        build(1,0,n-1,a);
    }
    Vpii _qu(int w,int l,int r,int ql,int qr) {
        op(l)op(r)op(ql)ope(qr)
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return zero;
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    pii qu(int l,int r) {
        return _qu(1,0,n-1,l,r)[0];
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    Vi a(n);
    REP(i,n) cin>>a[i];
    seg.init(n,a);
    REP(i,q) {
        int l,r;
        cin>>l>>r,l--,r--;
        auto [r1,r2]=seg.qu(l,r);
        op(r1)ope(r2)
        if(r2==inf) cout<<"-1\n";
        else cout<<r-l+1-r2<<' '<<r1<<'\n';
    }

    return 0;
}