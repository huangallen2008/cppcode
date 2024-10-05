#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        vector<int> a;
        REP(i,n) {
            int x;
            cin>>x;
            if(a.size()==0) a.pb(x);
            else if(x!=a.back()) a.pb(x);
        }
        n=a.size();
        vector<vector<int>> dp(n,vector<int>(n));
        REP(i,n) dp[i][i]=1;
        REP1(i,n-1) {
            for(int j=0;i+j<n;j++) {
                dp[j][j+i]=inf;
                if(a[j]==a[j+i]) dp[j][j+i]=min(dp[j][j+i],dp[j][j+i-1]);
                for(int k=j;k<j+i;k++) dp[j][j+i]=min(dp[j][j+i],dp[j][k]+dp[k+1][j+i]);
            }
        }
        cout<<dp[0][n-1]<<"\n";
    }
    return 0;
}
