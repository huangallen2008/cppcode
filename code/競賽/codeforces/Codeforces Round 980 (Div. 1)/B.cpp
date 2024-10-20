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
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1,inf);
    }
    void ud(int u,int v) {
        u++;
        for(;u<=n;u+=u&-u) chmin(b[u],v);
    }
    int qu(int u) {
        u++;
        int r=inf;
        for(;u>0;u-=u&-u) chmin(r,b[u]);
        return r;
    }
}bit;
void solve() {
    int n;
    cin>>n;
    bit.init(n);
    Vi a(n);
    REP(i,n) cin>>a[i];
    reverse(ALL(a));
    Vi b(n);
    REP(i,n) cin>>b[i],b[i]=n-b[i];
    reverse(ALL(b));
    bit.ud(n-1,0);
    RREP(i,n) {
        bit.ud(b[i],bit.qu(i)+a[i]);
    }
    Vi p=a;
    RREP(i,n-1) p[i]+=p[i+1];
    int an=0;
    REP(i,n )chmax(an,p[i]-bit.qu(i));
    cout<<an<<'\n';
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}