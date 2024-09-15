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
const int maxn=1e3+5;
const int mod=1e9+7;
struct edge {
    int u,v,t;
};
int n,m,k,l;
vector<vector<edge>> g;
int an=0;
vector<int> vis;
int dfs(int u,int t) {
    vis[u]=1;
//    cout<<"["<<u<<"\n";
    int r=0;
    REP(i,g[u].size()) {
        auto [x,v,th]=g[u][i];
        if(th!=t) continue;
        if(vis[v]) continue;
        r=max(r,dfs(v,t^1)+1);
    }
    vis[u]=0;
//    cout<<u<<":"<<r<<"\n";
    return r;
}
//int bfs(int u,int t) {
//    queue<pii> q;
//    q.push({u,t});
//    vector<int> d(n+m,-1);
//    d[u]=0;
//    int r=0;
//    while(q.size()) {
//        auto [nu,nt]=q.front();
//        q.pop();
//        REP(i,g[u].size()) {
//            auto [x,y,th]=g[u][i];
//            if(th!=nt) continue;
//            if(d[y]>d[u]) continue;
//            d[y]=d[u]+1;
//            r=max(r,d[y]);
//            q.push({y,nt^1});
//        }
//    }
//    return r;
//}
signed main()
{
    IOS();
    while(cin>>n>>m>>k>>l) {
        vector<int> x(n),y(m);
        g=vector<vector<edge>>(m+n);
        REP(i,n) x[i]=i;
        REP(i,m) y[i]=i+n;
        bool non=1;
        REP(i,k) {
            int u,v,t;
            cin>>u>>v>>t;
            u--,v--;
            if(t==0) non=0;
            g[x[u]].pb({x[u],y[v],t});
            g[y[v]].pb({y[v],x[u],t});
        }
        if(non) cout<<"-1\n";
        else {
            REP(i,n+m) {
                vis=vector<int>(n+m);
                an=max(an,dfs(i,0));
            }
            if(an%2==0) an--;
            cout<<an<<"\n";
        }
    }
    return 0;
}
