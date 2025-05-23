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
const int maxn=2e4+5;
const int maxb=18;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<int> dep,low;
bitset<maxn> vis,ap;
Graph g;
void dfs(int u,int fa) {
    low[u]=dep[u];
    vis[u]=1;
    int ch=0;
    for(int v:g[u]) {
        if(v==fa) continue;
        if(vis[v]) {
            chmin(low[u],dep[v]);
        }
        else {
            ch++;
            dep[v]=dep[u]+1;
            dfs(v,u);
            chmin(low[u],low[v]);
            if(fa!=-1&&low[v]>=dep[u]) {
                ap[u]=1;
            }
        }
    }
    if(fa==-1&&ch>=2) {
        ap[u]=1;
    }
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    g=Graph(n);
    dep=low=vector<int>(n);
    vis.reset();
    ap.reset();
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i,n) if(!vis[i]) dfs(i,-1);
    int s=0;
    REP(i,n) s+=ap[i];
    cout<<s<<'\n';
    REP(i,n) {
        if(ap[i]) cout<<i+1<<' ';
    }
    cout<<'\n';
    return 0;
}