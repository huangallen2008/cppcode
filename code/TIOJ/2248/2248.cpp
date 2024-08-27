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
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+9;
vector<int> w,sz,su;
vector<bool> vis;
vector<vector<pii>> g;
int n,k;
int an=0;
void dfs(int u) {
    vis[u]=1;
    int si=0,sm=0;
    for(auto [v,d]:g[u]) {
        if(vis[v]) continue;
        dfs(v);
        sm+=su[v];
        si+=sz[v];
        an+=d*abs(sz[v]*k-su[v]);
    }
    su[u]=sm+w[u];
    sz[u]=si+1;
}
signed main()
{
    IOS();
    cin>>n>>k;
    w=vector<int>(n);
    sz=vector<int>(n);
    su=vector<int>(n);
    vis=vector<bool>(n);
    g=vector<vector<pii>>(n);
    REP(i,n) cin>>w[i];
    REP(i,n-1) {
        int u,v,d;
        cin>>u>>v>>d;
        u--,v--;
        g[u].pb({v,d});
        g[v].pb({u,d});
    }
    dfs(0);
    cout<<an<<"\n";
    return 0;
}
