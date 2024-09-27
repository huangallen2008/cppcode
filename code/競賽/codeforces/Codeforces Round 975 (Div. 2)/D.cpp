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
const int mod=998244353;
const int modm=mod-1;
const int maxn=5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i],a[i]--;
    Vi mx(n+1);
    Vi mn(n+1,inf);
    REP(i,n) {
        chmax(mx[a[i]],i);
        chmin(mn[a[i]],i);
        // op(i)op(mx[a[i]])ope(mn[a[i]])
    }
    // oparr(mx)oparr(mn)
    bool ok=1;
    // int an=-1;
    int tx=0,tn=inf;
    pii an={0,n-1};
    auto upd=[&](int l,int r) {
        chmax(an.f,l);
        chmin(an.s,r);
    };
    REP(i,n) {
        chmax(tx,mx[i]);
        chmin(tn,mn[i]);
        if(tx-tn>i) an.f=inf;
        int dif=i-(tx-tn);
        upd(tn-dif,tx+dif);
        cout<<an.f<<' '<<an.s<<'\n';
    }
    int ans=max(0ll,an.s-an.f+1);
    cout<<ans<<'\n';
    entr
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}