#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxn=1e5+1;
const int maxb=17;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n,k;
    cin>>n>>k;
    vector<Vi> dp(n+1,Vi(k+1)),cnt(n+1,Vi(k+1));
    cnt[0][1]=1;
    REP(i,n+1) {
        REP1(j,k) {
            if(i+j<=n){
                addmod(dp[i+j][j],dp[i][j]+(i*2+j)*cnt[i][j]);
                op(i+j)op(i)op(j)op(cnt[i][j])ope(dp[i+j][j])
                addmod(cnt[i+j][j],cnt[i][j]);
            }
            if(j<k) {
                addmod(dp[i][j+1],dp[i][j]);
                addmod(cnt[i][j+1],cnt[i][j]);
            }
        }
    }
    REP(i,n+1 ){
        REP(j,k+1) cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    REP(i,n+1 ){
        REP(j,k+1) cout<<cnt[i][j]<<' ';
        cout<<'\n';
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}