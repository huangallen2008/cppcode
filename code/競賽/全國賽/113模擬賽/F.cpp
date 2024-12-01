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
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct E {
    int u,v,w;
};
Graphw g;
Graphw g2;
Vi vis;
void dfs(int u) {
    vis[u]=1;
    for(auto [v,w]:g[u]) {
        if(vis[v]) continue;
        g2[u].pb({v,w});
        dfs(v,u);
    }
}
Vi c;
Vi an,is0,sis0;
void dfs1(int u) {
    int co=c[u]^1;
    for(auto [v,w]:g2[u]) {
        an[w]=co;
        c[v]=co;
        dfs1(v);
        co=co^1;
    }
}
void dfs2(int u) {
    for(auto [v,w]:g2[u]) {
        
    }
}
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    an=Vi(m);
    g=Graphw(n);
    vis=c=is0=Vi(n);
    vector<E> edge;
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        edge.pb({u,v,i});
        g[u].pb({v,i});
        g[v].pb({u,i});
    }
    dfs(0);
    if(g[0].size()==1) {
        for(auto [u,v,w]:edge) {
            if(v==0) swap(u,v);
            if(u!=0) continue;
            is0[u]=1;
        }
    }else {
        dfs1(0);
        for(auto [u,v,w]:edge) {
            if(g2[v].size()==0) swap(u,v);
            if(g2[u].size()!=0) {
                an[w]=0;
                continue;
            }
            an[w]=c[u]^1;
        }
    }

    // Vi nf(n);
    // REP(i,n) if(g[i].size()==0||(i==0&&g[i].size()==1)) nf[i]=1;
    // for(auto [u,v]:edge) {
    //     if(g2[v].size()==0) swap(u,v);
    //     if(g2[u].size()!=0) continue;
    //     if(v==0) {
    //         bool is=1;
    //         REP(i,n) {
    //             if(i!=u&&g[i].size()!=1) is=0;
    //         }
    //         if(is) nf[u]=0;
    //         else nf[u]=nf[0]=0;
    //     }else {
    //         nf[u]=0;
    //     }
    // }
    // int an=0;

    return 0;
}