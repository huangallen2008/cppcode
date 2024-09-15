#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}

vector<int> fac(55),infac(55);
int C(int n,int k) {
    return (fac[n]*infac[k]%mod)*infac[n-k]%mod;
}
int dp[55][55][55];
signed main() {
    IOS();
    memset(dp,0,sizeof(dp));
    fac[0]=1,infac[0]=1;
    REP1(i,54) fac[i]=(fac[i-1]*i)%mod;
    REP1(i,54) infac[i]=inv(fac[i]);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> w(n+1);
    int wsum=0;
    REP1(i,n) cin>>w[i];
    REP1(i,n) wsum+=w[i];
    dp[0][0][0]=1;
    REP1(i,n) {
        REP(j,m+1) {
            REP(l,k+1) {
                dp[i][j][l]=dp[i-1][j][l];
                if(j>0) {
                    REP1(o,l) {
                        dp[i][j][l]=(dp[i][j][l]+(dp[i-1][j-1][l-o]*C(l,o))%mod*pw(w[i],o)%mod)%mod;
                    }
                }
            }
        }
    }
    int an=md(dp[n][m][k]*inv(pw(wsum,k)));
    cout<<an<<'\n';
    return 0;
}