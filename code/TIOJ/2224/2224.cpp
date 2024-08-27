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
const int maxn=6e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> g(n),g2(n);
    vector<int> in(n),ts,d(n,inf);
    int an=0;
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w});
        g2[v].pb({u,w});
        in[v]++;
    }
    queue<int> q;
    q.push(0);
    while(q.size()) {
        int u=q.front();
        ts.pb(u);
        q.pop();
        REP(i,g[u].size()) {
            in[g[u][i].f]--;
            if(in[g[u][i].f]==0) q.push(g[u][i].f);
        }
    }
    d[0]=0;
    REP(i,n) {
        int u=ts[i];
        REP(j,g2[u].size()) d[u]=min(d[u],d[g2[u][j].f]+g2[u][j].s);
        an+=d[u];
    }
    cout<<an<<"\n";
    return 0;
}
