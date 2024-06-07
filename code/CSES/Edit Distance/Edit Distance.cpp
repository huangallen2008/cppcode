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
    string a,b;
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    a="$"+a;
    b="$"+b;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    REP1(i,m) dp[0][i]=i;
    REP1(i,n) dp[i][0]=i;
    REP1(i,n) {
        REP1(j,m) {
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            if(a[i]==b[j]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    cout<<dp[n][m]<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
