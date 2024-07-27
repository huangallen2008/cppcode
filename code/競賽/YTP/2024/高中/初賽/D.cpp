#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) chmax(b[u],v);
    } 
    int qu(int u) {
        int r=0;
        for(;u>0;u-=u&-u) chmax(r,b[u]);
        return r;
    }
}bita,bitb;
void solve() {
    int n;
    cin>>n;
    bita.init(n);
    bitb.init(n);
    vector<int> a(n),b(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    // reverse(ALL(a));
    // reverse(ALL(b));
    vector<int> ta,tb;
    REP(i,n) ta.pb(a[i]),tb.pb(b[i]);
    sort(ALL(ta));
    sort(ALL(tb));
    REP(i,n) a[i]=lower_bound(ALL(ta),a[i])-ta.begin()+1;
    REP(i,n) b[i]=lower_bound(ALL(tb),b[i])-tb.begin()+1;
    // REP(i,n) a[i]=n-a[i],b[i]=n-b[i];
    // oparr(a)oparr(b)
    vector<int> dp(n);
    REP(i,n) {
        dp[i]=max(bita.qu(a[i]-1),bitb.qu(b[i]-1))+1;
        bita.ud(a[i],dp[i]);
        bitb.ud(b[i],dp[i]);
    }
    int an=0;
    REP(i,n) chmax(an,dp[i]);
    cout<<an<<'\n';
    // entr
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}