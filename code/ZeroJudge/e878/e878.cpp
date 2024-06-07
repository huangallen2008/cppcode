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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n)),d(m,vector<int>(n));
    REP(i,m) REP(j,n) cin>>a[i][j];
    int an=0;
    REP(i,m) {
        REP(j,n) {
            d[i][j]=a[i][j];
            if(i>0) d[i][j]=max(d[i][j],d[i-1][j]+a[i][j]);
            if(j>0) d[i][j]=max(d[i][j],d[i][j-1]+a[i][j]);
            an=max(an,d[i][j]);
        }
    }
    cout<<an<<"\n";
    return 0;
}
