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
const int mod=19260817;
const int maxn=5e5+5;
const int maxb=18;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graphw g;
vector<int> dep,low,dfn;
bitset<maxn> vis;
void dfs(int u,int fa) {
    low[u]=dep[u];
    ope(u)
    dfn.pb(u);
    vis[u]=1;
    for(auto &[v,w]:g[u]) {
        if(v==fa) continue;
        if(vis[v]) {
            chmin(low[u],dep[v]);
        }
        else {
            op(u)ope(v)
            dep[v]=dep[u]+1;
            dfs(v,u);
            chmin(low[u],low[v]);
            if(low[v]<dep[v]) w=1;
        }
    }
}
Graph an;
void dfs2(int u,int id) {
    ope(id)
    vis[u]=1;
    an[id].pb(u);
    for(auto [v,w]:g[u]) {
        if(vis[v]) continue;
        if(!w)dfs2(v,id);
    }
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    g=Graphw(n);
    dep=low=vector<int>(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb({v,0});
        g[v].pb({u,0});
    }
    dfs(0,-1);
    oparr(dep)oparr(low)
    int cntb=0;
    REP(u,n) for(auto [v,w]:g[u]) if(w) cntb++;
    REP(u,n) for(auto [v,w]:g[u]) {op(u)op(v)ope(w)}
    an=Graph(cntb);
    int it=0;
    vis.reset();
    for(int u:dfn) {
        ope(u)
        if(!vis[u]) {
            dfs2(u,it++);
        }
    }
    cout<<cntb<<'\n';
    REP(i,cntb) {
        for(int u:an[i]) cout<<u<<' ';
        cout<<'\n';
    }
    return 0;
}