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
const int maxn=17;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
bitset<maxn> vis;
Vi col;
int cnt[4];
bool ok=1;
Vi dfn;
void dfs0(int u) {
    dfn.pb(u);
    vis[u]=1;
    for(int v:g[u]) {
        if(vis[v]) continue;
        dfs0(v);
    }
}
int n,m;
int an=inf;
void dfs(int id) {
    if(id==n) {
        chmin(an,max({cnt[1],cnt[2],cnt[3]})-min({cnt[1],cnt[2],cnt[3]}));
        return;
    }
    int u=dfn[id];
    REP1(nc,3) {
        col[u]=nc;
        bool ok=1;
        for(int v:g[u]) {
            if(col[v]&&col[v]==col[u]) {
                ok=0;
                break;
            }
        }
        if(!ok) continue;
        cnt[nc]++;
        dfs(id+1);
        cnt[nc]--;
    }
    col[u]=0;
}
signed main() {
    IOS();
    // int n,m;
    cin>>n>>m;
    g=Graph(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i,n) if(!vis[i]) dfs0(i);
    col=Vi(n);
    dfs(0);
    if(an==inf) cout<<"-1\n";
    else cout<<an<<'\n';
    return 0;
}