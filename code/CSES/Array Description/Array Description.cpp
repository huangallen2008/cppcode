#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<vector<int>> dp(n,vector<int>(m+2));
    if(a[0]==0) REP1(i,m) dp[0][i]=1;
    else dp[0][a[0]]=1;
    REP1(i,n-1) {
        REP1(j,m) {
            if(a[i]!=0&&a[i]!=j) dp[i][j]=0;
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
//            cout<<dp[i][j]<<" ";
        }
//        cout<<"\n";
    }
    int an=0;
    if(a[n-1]==0) REP1(i,m) an=(an+dp[n-1][i])%mod;
    else an=dp[n-1][a[n-1]];
    cout<<an<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
