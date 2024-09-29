#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
const int ii=inv(10000);
void solve() {
    int n;
    cin>>n;
    Vi a(n+1),p(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) cin>>p[i];
    vector<Vi> dp(n+1,Vi(1024));
    dp[0][0]=1;
    REP1(i,n) {
        REP(j,1024) {
            dp[i][j]=(dp[i-1][j]*(10000-p[i])%mod*ii%mod+dp[i-1][j^a[i]]*(p[i])%mod*ii%mod)%mod;
        }
    }
    int an=0;
    REP(i,1024) {
        an=(an+dp[n][i]*i*i%mod)%mod;
    }
    cout<<an<<'\n';
}
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}