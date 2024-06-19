#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
Graphw g;
int n,k,t;
bitset<maxn> vis;
vector<pii> edges;
vector<int> w;
int dfs(int id,int x) {
    if(id>=edges.size()) return 1;
    auto [u,v]=edges[id];
    int an=0;
    if(!vis[u]&&!vis[v]&&x>=w[id]) {
        vis[u]=vis[v]=1;
        an+=dfs(id+1,x-w[id]);
        vis[u]=vis[v]=0;
    }
    an+=dfs(id+1,x);
    return an;
}
signed main() {
    IOS();
    cin>>n>>k>>t;
    g=Graphw(n);
    REP(i,k) {
        int u,v,ww;
        cin>>u>>v>>ww;
        u--,v--;
        edges.pb({u,v});
        w.pb(ww);
        // g[u].pb({v,w});
    }
    int l=0,r=20005,m;
    while(l<r) {
        m=l+r>>1;
        int ret=dfs(0,m);
        if(ret>=t) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
    return 0;
}