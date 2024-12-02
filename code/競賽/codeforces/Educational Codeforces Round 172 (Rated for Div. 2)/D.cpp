#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define piii pair<pii,int>
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    Vi b;
    int n;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        u=n-u;
        for(;u<=n;u+=u&-u) chmax(b[u],v);
    }
    int qu(int u) {
        u=n-u;
        int r=0;
        for(;u>0;u-=u&-u) chmax(r,b[u]);
        return r;
    }
}bit1;
struct BIT2 {
    Vi b;
    int n;
    void init(int _n) {
        n=_n;
        b=Vi(n+1,inf);
    }
    void ud(int u,int v) {
        u=n-u;
        for(;u<=n;u+=u&-u) chmin(b[u],v);
    }
    int qu(int u) {
        u=n-u;
        int r=inf;
        for(;u>0;u-=u&-u) chmin(r,b[u]);
        return r;
    }
}bit2;
void solve() {
    int n;
    cin>>n;
    vector<piii> a(n);
    REP(i,n) cin>>a[i].f.f>>a[i].f.s,a[i].s=i;
    Vi t;
    REP(i,n) t.pb(a[i].f.f),t.pb(a[i].f.s);
    sort(ALL(t));
    REP(i,n) {
        a[i].f.f=lower_bound(ALL(t),a[i].f.f)-t.begin();
        a[i].f.s=lower_bound(ALL(t),a[i].f.s)-t.begin();
    }
    sort(ALL(a),[&](piii a,piii b) {
        if(a.f.f==b.f.f) return a.f.s>b.f.s;
        return a.f.f<b.f.f;
    });
    oparr(a)
    bit1.init(n*2);
    bit2.init(n*2);
    Vi an(n);
    REP(i,n) {
        int l=a[i].f.f,r=a[i].f.s,id=a[i].s;
        int r1=bit1.qu(r),r2=bit2.qu(r);
        op(i)op(r1)op(r2)ope(id)
        if(r2==inf)an[id]=0;
        else an[id]=t[r2]-t[r1]-(t[r]-t[l]);
        bit1.ud(r,l);
        bit2.ud(r,r);
    }
    REP(i,n) cout<<an[i]<<' ';cout<<'\n';
    entr
    //bit size 2n
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}