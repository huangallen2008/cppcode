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
const int mod=1e9+7;
const int maxn=100+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> dp0(n+1,vector<int>(n+1)),dp1(n+1,vector<int>(n+1));
    dp0[1][0]=1;
    REP1(i,n-1) {
        REP(j,i) {
            if(j>0)dp0[i+1][j-1]=(dp0[i+1][j-1]+dp0[i][j]*j+dp1[i][j]*(j-1))%mod;
            dp0[i+1][j]=(dp0[i+1][j]+dp0[i][j]*(i-1-j)+dp1[i][j]*(i-j))%mod;
            dp1[i+1][j]=(dp1[i+1][j]+dp1[i][j])%mod;
            dp1[i+1][j+1]=(dp1[i+1][j+1]+dp0[i][j]*2+dp1[i][j])%mod;
        }
    }
    cout<<(dp0[n][0]+mod)%mod<<'\n';
    return 0;
}