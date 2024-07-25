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
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<vector<int>> dp(n,vector<int>(n));
    if(n%2==1) REP(i,n) dp[i][i]=a[i];
    REP1(i,n-1) {
        REP(j,n-i) {//j~j+i
            if((n-i)%2==1) dp[j][j+i]=max(dp[j+1][j+i]+a[j],dp[j][j+i-1]+a[j+i]);
            else dp[j][j+i]=min(dp[j+1][j+i],dp[j][j+i-1]);
        }
    }
    cout<<dp[0][n-1]<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
