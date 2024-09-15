#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
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
//shuffle(a,a+n,rng)
int n,b,d;
signed main() {
    IOS();
    cin>>n>>b>>d;
    vector<vector<int>> dp(n+1,vector<int>(b));
    vector<vector<int>> dpp(n+1,vector<int>(b));
    vector<vector<int>> wa(n+1,vector<int>(b));
    vector<vector<int>> wap(n+1,vector<int>(b));
    REP(i,b) {
        wa[0][i]=1;
        wap[0][i]=1;
        dpp[0][i]=i;
    }
    REP1(i,n) {
        REP(j,b) {
            int lr=max(j-d+1,(int)0),rl=j+d;
            wa[i][j]=md(wap[i][0]-(i-lr>=0?wap[i-lr][lr]:0)+(i-rl>=0&&rl<b?wap[i-rl][rl]:0));
            wap[i][j]=md((j+1<b?wap[i-1][j+1]:0)+wa[i][j]);
            dp[i][j]=md(dpp[i][0]-(i-lr>=0?dpp[i-lr][lr]:0)+(i-rl>=0&&rl<b?dpp[i-rl][rl]:0));
            dpp[i][j]=md((j+1<b?dpp[i-1][j+1]:0)+md(dp[i][j]*b)+md(wa[i][j]*j));
        }
    }
    int an=0;
    REP(i,b) {
        if(n-i<0) continue;
        an=md(an+md(dp[n-i][i]*b)+md(wa[n-i][i]*i));
    }
    cout<<an<<'\n';
    return 0;
}
