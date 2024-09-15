#include<bits/stdc++.h>
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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int k,m,n;
    cin>>k;
    cin>>m>>n;
    int an=0;
    vector<vector<int>> a(m+1,vector<int>(n+1)),p(m+1,vector<int>(n+1));
    REP1(i,m) REP1(j,n) cin>>a[i][j];
    REP1(i,m) REP1(j,n) p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
    REP1(i,m) REP1(j,n) for(int l=i;l<=m;l++) for(int o=j;o<=n;o++) if(p[l][o]-p[l][j-1]-p[i-1][o]+p[i-1][j-1]<=k) an=max(an,p[l][o]-p[l][j-1]-p[i-1][o]+p[i-1][j-1]);
    cout<<an<<"\n";
    return 0;
}
