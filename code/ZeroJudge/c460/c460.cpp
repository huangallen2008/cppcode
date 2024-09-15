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
const int maxn=2e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<vector<int>> a(3,vector<int>(8));
    REP(i,n) {
        int t,x,y,z;
        cin>>t>>x>>y>>z;
        a[t-1][x*4+y*2+z]++;
    }
    int an=0;
    REP(i,8) REP(j,8) REP(k,8) if(((i|j)|k)==7) an+=a[0][i]*a[1][j]*a[2][k];
    cout<<an<<"\n";
    return 0;
}
