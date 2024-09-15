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
    int n,m;
    cin>>n>>m;
    vector<pii> an;
    vector<vector<int>> a(n,vector<int>(m));
    REP(i,n) REP(j,m) cin>>a[i][j];
    REP(i,n) {
        REP(j,m) {
            int r=0;
            REP(ni,n) {
                REP(nj,m) {
                    int d=abs(i-ni)+abs(j-nj);
                    if(d<=a[i][j]) r+=a[ni][nj];
                }
            }
            if(r%10==a[i][j]%10) an.pb({i,j});
        }
    }
    cout<<an.size()<<"\n";
    for(auto [x,y]:an) cout<<x<<" "<<y<<"\n";
    return 0;
}
