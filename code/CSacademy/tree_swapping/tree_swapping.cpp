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
#define Vi vector<int>
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
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Vi col,bc,sz;
int cnt0=0,cnt1=0;
Graph g;
void dfs(int u,int fa) {
    for(int v:g[u]) {
        if(v==fa) continue;
        bc[v]=bc[u]^1;
        dfs(v,u);
    }
}
void dfs0(int u,int fa) {
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs0(v,u);
        col[u]+=col[v];
        bc[u]+=bc[v];
        sz[u]+=sz[v];
    }
}
int dfs1(int u,int fa) {
    int r=0;
    for(int v:g[u]) {
        if(v==fa) continue;
        r+=dfs1(v,u)+abs(col[v]-bc[v]);
    }
    return r;
}
int dfs2(int u,int fa) {
    int r=0;
    for(int v:g[u]) {
        if(v==fa) continue;
        r+=dfs2(v,u)+abs(sz[v]-col[v]-bc[v]);
    }
    return r;
}
signed main() {
    IOS(); 
    cin>>n;
    g=Graph(n);
    col=bc=Vi(n);
    sz=Vi(n,1);
    REP(i,n) {
        char c;
        cin>>c;
        col[i]=c=='R';
    }
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    REP(i,n) (bc[i]?cnt1:cnt0)++;
    int cntR=0;
    REP(i,n) cntR+=col[i];
    dfs0(0,-1);
    int an=inf;
    if(cntR==cnt1) {
        chmin(an,dfs1(0,-1));
    }
    if(cntR==cnt0) {
        chmin(an,dfs2(0,-1));
    }
    if(an==inf) cout<<"-1\n";
    else cout<<an<<'\n';
    return 0;
}