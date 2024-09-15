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
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<int> x(n+2),sz(n+2);
    x[0]=-inf,x[n+1]=inf;
    REP1(i,n) cin>>x[i];
    int mn=0,mx=0,nw=0;
    REP(i,m) {
        int w;
        cin>>w;
        nw+=w;
        if(nw>mx) {
            REP1(j,n) {
                sz[j]+=max(min(nw,x[j+1]-x[j]+mn)-max(nw-w,mx),(int)0);
            }
            mx=nw;
        }
        if(nw<mn) {
            REP1(j,n) {
                sz[j]+=max(min(nw-w,mn)-max(nw,x[j-1]-x[j]+mx),(int)0);
            }
            mn=nw;
        }
//        REP1(i,n) cout<<sz[i]<<" ";cout<<"\n";
    }
    REP1(i,n) cout<<sz[i]<<"\n";
    return 0;
}
