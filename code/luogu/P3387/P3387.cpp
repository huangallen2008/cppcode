#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxb=18;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SCC {
    vector<int> sccid,dfn,val,dis,ind;
    bitset<maxn> vis;
    int sccc=0;
    Graph ng;
    int an=0;
    void init(int n,Graph &g,vector<int> &v) {
        sccid=vector<int>(n);
        dfn.clear();
        sccc=0;
        vis.reset();
        REP(i,n) if(!vis[i]) dfs1(i,g);
        Graph gb(n);
        REP(i,n) for(auto v:g[u]) gb[v].pb(u);
        vis.reset();
        REP(i,n) {
            int u=dfn[i];
            if(!vis[u]) {
                sccid[u]=sccc++;
                dfs2(u,g);
            }
        }
        ng=Graph(sccc);
        ind=val=vector<int>(sccc);
        REP(i,n) val[sccid[i]]+=v[i];
        REP(u,n) {
            for(auto v:g[u]) {
                if(sccid[u]!=sccid[v]) ng[sccid[u]].pb(sccid[v]),ind[sccid[v]]++;
            }
        }
        vis.reset();
        dis=vector<int>(sccc);
        queue<int> q;
        REP(i,sccid) if(ind[i]==0) q.push(i),dis[i]=val[i];
        while(q.size()) {
            int u=q.front();
            q.pop();
            for(int v:g[u]) {
                chmax(dis[v],dis[u]+val[v]);
                ind[v]--;
                if(ind[v]==0) q.push(v);
            }
        }
        an=*max_element(ALL(dis));
    }
    void dfs1(int u,Graph &g) {
        vis[u]=1;
        for(auto v:g[u]) {
            if(vis[v]) continue;
            dfs1(v,g);
        }
        dfn.pb(u);
    }
    void dfs2(int u,Graph &g) {
        vis[u]=1;
        for(auto v:g[u]) {
            if(vis[v]) continue;
            sccid[v]=sccid[u];
            dfs2(v,g);
        }
    }
}scc;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Graph g(n);
    vector<int> v(n);
    REP(i,n) cin>>v[i];
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
    }
    scc.init(n,g,v);
    cout<<scc.an<<'\n';
    return 0;
}