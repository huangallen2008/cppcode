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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
int dp[81][81][81][81];
signed main() {
    IOS();
    int n,m;
    string a,b;
    cin>>n>>m>>a>>b;
    REP(pi,n) {
        REP(i,n-pi) {
            REP(pj,m) {
                REP(j,m-pj) {
                    if(a[i]==a[i+pi]&&b[j]==b[j+pj]&&a[i]==b[j]) dp[i][i+pi][j][j+pj]=(i+pi>1&&j+pj>1?dp[i+1][i+pi-1][j+1][j+pj-1]:0)+1+(pi>0&&pj>0);
                    dp[i][i+pi][j][j+pj]=max(dp[i][i+pi][j][j+pj],max(max(dp[i+1][i+pi][j][j+pj],i+pi>1?dp[i][i+pi-1][j][j+pj]:0),max(dp[i][i+pi][j+1][j+pj],j+pj>1?dp[i][i+pi][j][j+pj-1]:0)));
                }
            }
        }
    }
    cout<<dp[0][n-1][0][m-1]<<"\n";
    return 0;
}
