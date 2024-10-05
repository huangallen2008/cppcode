#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=20+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
vector<int> col;
vector<int> dfsn;
bitset<maxn> vis;
void build_dfsn(int u) {
    dfsn.pb(u);
    vis[u]=1;
    for(int v:g[u]) {
        if(!vis[v]) build_dfsn(v);
    }
}
int dfs(int id) {
    if(id==dfsn.size()) return 1;
    int u=dfsn[id];
    int an=0;
    for(int new_col:{1,2,3}) {
        col[u]=new_col;
        bool ok=1;
        for(int v:g[u]) {
            if(col[v]) {
                if(col[u]==col[v]) {
                    ok=0;
                    break;
                }
            }
        }
        if(!ok) continue;
        an+=dfs(id+1);
    }
    col[u]=0;
    return an;
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    g=Graph(n);
    col=vector<int>(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int an=1;
    REP(i,n) {
        if(!vis[i]) {
            dfsn.clear();
            build_dfsn(i);
            int ret=dfs(0);
            an*=ret;
        }
    }
    cout<<an<<'\n';
    return 0;
}
