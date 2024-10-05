#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
const int maxn=300+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int dp[maxn][maxn][maxn];
signed main() {
    IOS();
    int n,h;
    cin>>n>>h;
    vector<int> x(n+1);
    REP1(i,n) cin>>x[i];
    vector<int> p(n+1),f(n+1);
    REP1(i,n-1) cin>>p[i]>>f[i];
    REP(i,maxn) REP(j,maxn) REP(k,maxn) dp[i][j][k]=inf;
    REP(i,h+1) dp[0][i][h]=0;
    REP(i,n) {
        REP(j,h+1) {
            REP1(k,h) {
                int dis=x[i+1]-x[i];
                if(j+dis>h||k-dis<0) continue;
                chmin(dp[i+1][j+dis][k-dis],dp[i][j][k]);
                if(j+dis-f[i+1]>=0)chmin(dp[i+1][j+dis-f[i+1]][k-dis],dp[i][j][k]+p[i+1]);
                if(j+dis==h) {
                    for(int l=h-f[i+1];l<=h;l++) chmin(dp[i+1][l][k-dis],dp[i][j][k]+p[i+1]);
                }
                chmin(dp[i+1][j+dis][min(k-dis+f[i+1],h)],dp[i][j][k]+p[i+1]);
            }
        }
    }
    int an=inf;
    REP(i,h+1) chmin(an,dp[n][i][i]);
    if(an>4e7) cout<<"-1\n"; 
    else cout<<an<<'\n';
    return 0;
}