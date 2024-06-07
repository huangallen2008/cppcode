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
const int maxn=3e5+5;
const int maxv=5000+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int dp[105][55][10010];//dp[i][j][k]
signed main() {
    IOS();
    int n,x;
    cin>>n>>x;
    vector<int> t(n);
    REP(i,n) cin>>t[i];
    sort(ALL(t));
    dp[0][0][maxv]=1;
    REP(i,n) {
        for(int j=0;j*2<=n;j++) {
            for(int k=t[i];k+t[i]<10010;k++) {
                if(j<n-1)addmod(dp[i+1][j+1][k-t[i]],dp[i][j][k]);
                addmod(dp[i+1][j][k],dp[i][j][k]*(j+1));
                if(j>0)addmod(dp[i+1][j-1][k+t[i]],dp[i][j][k]*j);
            }
        }
    }
    int an=0;
    for(int i=maxv;i<=maxv+x;i++) addmod(an,dp[n][0][i]);
    cout<<an<<'\n';
    return 0;
}