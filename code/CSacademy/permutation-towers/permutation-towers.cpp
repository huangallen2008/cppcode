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
// const int mod=1e9+7;
const int maxn=100+5;
const int maxx=2e5+5;
const int inf=(1<<25);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// int dp[maxn][maxn*maxn];
// int ndp[maxn][maxn*maxn];
int mod;
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
signed main() {
    IOS(); 
    int n,x;
    cin>>n>>x>>mod;
    Vi fac(maxx),infac(maxx);
    fac[0]=1;
    REP1(i,maxx-1) fac[i]=fac[i-1]*i%mod;
    infac[maxx-1]=inv(fac[maxx-1]);
    RREP(i,maxx-1) infac[i]=infac[i+1]*(i+1)%mod;
    auto C=[&](int n,int k) {
        return (fac[n]*infac[k]%mod)*infac[n-k]%mod;
    };
    auto H=[&](int n,int k) {
        return C(n+k-1,k);
    };
    vector<Vi> dp(n+1,Vi(n*n));
    dp[0][1]=1;
    REP1(i,n) {
        vector<Vi> ndp(n+1,Vi(n*n));
        REP1(j,i) {
            REP(k,(i*(i+1)>>1)+4) {
                if(k>=i&&j>0) addmod(ndp[j][k],dp[j][k-i]*(j<<1));
                addmod(ndp[j][k],dp[j-1][k]*j);
                if(k>=(i<<1)&&j<n) addmod(ndp[j][k],dp[j+1][k-(i<<1)]*j);
            }
        }
        swap(dp,ndp);
    }
    int an=0;
    REP(i,n*n) {
        if(i<=x)addmod(an,H(n+1,x-i)*dp[1][i]);
    }
    an=(an+mod)%mod;
    cout<<an<<'\n';
    return 0;
}