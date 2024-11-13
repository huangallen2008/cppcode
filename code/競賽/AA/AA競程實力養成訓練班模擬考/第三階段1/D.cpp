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
Vi dp0(100);
int dp(int n) {
    return n<=84?dp0[n]:inf;
}
void f(int n,int l,int r) {
    if(n<=2) {
        for(int i=l;i<=r;i++) cout<<i<<'\n';
        return;
    }
    if(dp(n-2)>=r) f(n-2,l,r);
    else if(dp(n-2)<l) {
        if(r>dp(n-1)+dp(n-2)) {
            f(n-1,l-dp(n-2),dp(n-1));
            REP1(i,r-dp(n-1)-dp(n-2)) cout<<i<<'\n';
        }
        else f(n-1,l-dp(n-2),r-dp(n-2));
    }
    else {
        f(n-2,l,dp(n-2));
        if(r>dp(n-1)+dp(n-2)) {
            f(n-1,1,dp(n-1));
            REP1(i,r-dp(n-1)-dp(n-2)) cout<<i<<'\n';
        }
        else f(n-1,1,r-dp(n-2));
    }
}
signed main() {
    IOS(); 
    dp0[1]=1,dp0[2]=2;
    for(int i=3;i<100;i++) dp0[i]=i+dp0[i-1]+dp0[i-2];
    oparr(dp0)
    int n,l,r;
    cin>>n>>l>>r;
    if(n>=85) n=84+(n&1);
    f(n,l,r);
    // oparr(dp)
    // REP(i,100) {
    //     op(i)op(dp[i])ope(dp[i]>(1e18))
    // }
    return 0;
}