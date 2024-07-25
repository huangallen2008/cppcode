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
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
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
const int mod=1e9+7;
const int maxn=500+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int C[maxn][maxn];
void init() {
    C[0][0]=1;
    for(int i=1;i<maxn;i++) {
        C[i][0]=1;
        for(int j=1;j<=i;j++) {
            addmod(C[i][j],C[i-1][j]+C[i-1][j-1]);
        }
    }
}
signed main() {
    IOS();
    init();
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    REP(i,n) dp[i+1][i]=1;
    REP(r,n) {
        RREP(l,r) {
            for(int i=l+1;i<=r;i++) {
                if(s[l]==s[i]) addmod(dp[l][r],(dp[l+1][i-1]*dp[i+1][r]%mod)*C[r-l+1>>1][i-l+1>>1]%mod);
            }
        }
    }
    cout<<dp[0][n-1]<<'\n';
    return 0;
}