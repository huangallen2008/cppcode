#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#ifdef LOCAL
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
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int p;
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]=(b[u]+v)%p;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r=(r+b[u])%p;
        return r;
    }
    int qu(int l,int r) {
        int ret=(pre(r)-pre(l-1))%p;
        return (ret+p)%p;
    }
}bit;
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m>>p;
    Vi t;
    bit.init(n*2+5);
    bit.ud(1,1);
    t.pb(-1);
    t.pb(0);
    t.pb(m);
    vector<pii> a(n);
    REP(i,n) cin>>a[i].f,t.pb(a[i].f);
    REP(i,n) cin>>a[i].s,t.pb(a[i].s);
    sort(ALL(t));
    REP(i,n) {
        a[i].f=lower_bound(ALL(t),a[i].f)-t.begin();
        a[i].s=lower_bound(ALL(t),a[i].s)-t.begin();
    }
    sort(ALL(a),[&](pii a,pii b){
        return a.s<b.s;
    });
    for(auto [l,r]:a) {
        bit.ud(r,bit.qu(l,r-1));
    }
    int id=lower_bound(ALL(t),m)-t.begin();
    int an=bit.qu(id,id);
    cout<<an<<'\n';
    return 0;
}