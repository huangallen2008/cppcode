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
int n,m;
vector<int> a,b;
vector<vector<int>> dp1,dp2;
int an=-inf;
signed main()
{
    IOS();
    cin>>n>>m;
    a=vector<int>(n+2);
    b=vector<int>(m+2);
    REP1(i,n) cin>>a[i];
    REP1(i,m) cin>>b[i];
    dp1=vector<vector<int>>(n+2,vector<int>(m+2));
    dp2=vector<vector<int>>(n+2,vector<int>(m+2));
    REP1(i,n) {
        REP1(j,m) {
            dp1[i][j]=max(dp1[i-1][j-1]+a[i]*b[j],a[i]*b[j]);
            an=max(an,dp1[i][j]);
        }
    }
    REP1(i,n) {
        for(int j=m;j>0;j--) {
            dp2[i][j]=max(dp2[i-1][j+1]+a[i]*b[j],a[i]*b[j]);
            an=max(an,dp2[i][j]);
        }
    }
    cout<<an<<"\n";
    return 0;
}
