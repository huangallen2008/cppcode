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
const int maxn=3e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),b(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    vector<int> nsum_mx(n+1,-inf);
    vector<int> sum_mx(n+1,-inf);
    vector<int> ndif_mx(n+1,-inf);
    vector<int> dif_mx(n+1,-inf);//a-b
    sum_mx[0]=a[1]+b[1],nsum_mx[0]=-a[1]-b[1];
    dif_mx[0]=a[1]-b[1],ndif_mx[0]=-a[1]+b[1];
    REP1(i,n) {
        REP(j,min(i,k)+1) {
            int dif=i-j;
            dp[i][j]=max({dp[i-1][j],a[i]+b[i]+nsum_mx[dif],sum_mx[dif]-(a[i]+b[i]),a[i]-b[i]+dif_mx[dif],b[i]-a[i]+ndif_mx[dif]});
            if(i==n) continue;
            chmax(sum_mx[dif],dp[i][j]+a[i+1]+b[i+1]);
            chmax(nsum_mx[dif],dp[i][j]-a[i+1]-b[i+1]);
            chmax(dif_mx[dif],dp[i][j]+a[i+1]-b[i+1]);
            chmax(ndif_mx[dif],dp[i][j]-a[i+1]+b[i+1]);
        }
    }
    cout<<dp[n][k]<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}