#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll inf=(1ll<<63)-1;
const int maxn=1e5+5;
const ll mod=1e9+7;
int m,n;
vector<vector<int>> a,dl,dr,dp;
signed main() {
    IOS();
    cin>>m>>n;
    a=vector<vector<int>>(m+1,vector<int>(n));
    dl=vector<vector<int>>(m+1,vector<int>(n));
    dr=vector<vector<int>>(m+1,vector<int>(n));
    dp=vector<vector<int>>(m+1,vector<int>(n));
    REP1(i,m)
        REP(j,n)
            cin>>a[i][j];
    REP1(i,m) {
        REP(j,n) {
            if(j==0) dr[i][j]=dp[i-1][j]+a[i][j];
            else dr[i][j]=max(dp[i-1][j],dr[i][j-1])+a[i][j];
        }
        RREP(j,n) {
            if(j==n-1) dl[i][j]=dp[i-1][j]+a[i][j];
            else dl[i][j]=max(dp[i-1][j],dl[i][j+1])+a[i][j];
        }
        REP(j,n) dp[i][j]=max(dl[i][j],dr[i][j]);
    }
    cout<<*max_element(ALL(dp[m]))<<"\n";
    return 0;
}
