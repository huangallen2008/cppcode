#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,m,s;
int jp[maxb][maxn];
vector<int> dep;
Graph g;
void dfs(int u,int pa) {
    for(int v:g[u]) {
        if(v==pa) continue;
        dep[v]=dep[u]+1;
        jp[0][v]=u;
        dfs(v,u);
    }
}
void init() {
    REP1(i,maxb-1) {
        REP(j,n) jp[i][j]=jp[i-1][jp[i-1][j]];
    }
}
int lca(int a,int b) {
    if(dep[a]>dep[b]) swap(a,b);
    int dif=dep[b]-dep[a];
    REP(i,maxb) {
        if((dif>>i)&1) b=jp[b][i];
    }

    if(a==b) return a;
    RREP(i,maxb) {
        if(jp[i][a]!=jp[i][b]) {
            a=jp[i][a];
            b=jp[i][b];
        }
    }
    return jp[0][a];
}
signed main() {
    IOS();
    cin>>n>>m>>s,s--;
    g=Graph(n);
    dep=vector<int>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    jp[0][s]=s;
    dfs(s,-1);
    init();
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        cout<<lca(u,v)+1<<'\n';
    }
    return 0;
}