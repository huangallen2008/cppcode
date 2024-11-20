#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
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
// Vi vis;
// Graph g;
struct DSU {
    Vi p,sz,is;
    int n;
    void init(int _n) {
        n=_n;
        p=is=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) {
            is[x]=1;
            return;
        }
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        is[y]|=is[x];
    }
}dsu;
// bool dfs(int u,int fa) {
//     vis[u]=1;
//     bool an=0;
//     for(int v:g[u]) {
//         if(v==fa) continue;
//         if(vis[v]) {
//             return 1;
//         }
//         an|=dfs(v,u);
//     }
//     return an;
// }
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    dsu.init(n);
    // g=Graph(n);
    // vis=Vi(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        dsu.merge(u,v);
        // if(u==v) continue;
        // g[u].pb(v);
        // g[v].pb(u);
    }
    int an[2]={0,0};
    REP(i,n) if(dsu.p[i]==i) an[dsu.is[i]]++;
    // REP(i,n) if(!vis[i]) an[dfs(i,-1)]++;
    cout<<an[1]<<' '<<an[0]<<'\n';
    return 0;
}