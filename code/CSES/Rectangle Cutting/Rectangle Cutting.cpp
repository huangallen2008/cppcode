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
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    vector<vector<int>> dp(a+1,vector<int>(b+1,inf));
    REP1(i,a) {
        REP1(j,b) {
            if(i==j) {
                dp[i][j]=0;
//                cout<<"0 ";
                continue;
            }
            REP1(ni,i-1) {
                dp[i][j]=min(dp[i][j],dp[ni][j]+dp[i-ni][j]+1);
            }
            REP1(nj,j-1) {
                dp[i][j]=min(dp[i][j],dp[i][nj]+dp[i][j-nj]+1);
            }
//            cout<<dp[i][j]<<" ";
        }
//        cout<<endl;
    }
    cout<<dp[a][b]<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
