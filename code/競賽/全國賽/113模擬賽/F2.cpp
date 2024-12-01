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
Vi vis,ong2;
// void dfs(int u) {
//     vis[u]=1;
//     for(auto [v,w]:g[u]) {
//         if(vis[v]) continue;
//         g2[u].pb({v,w});
//         ong2[w]=1;
//         dfs(v);
//     }
// }
Vi c;
Vi an,is0,sis0;
void dfs(int u) {
    vis[u]=1;
    int co=c[u]^1;
    for(auto [v,w]:g[u]) {
        if(vis[v])continue;
        an[w]=co;
        c[v]=co;
        dfs(v);
        co=co^1;
    }
}
// void dfs2(int u) {
//     for(auto [v,w]:g2[u]) {
//         dfs(v);
//         sis0[u]+=sis0[v];
//     }
// }
// void dfs3(int u) {
//     // for(auto [v,])
// }
signed main() {
    IOS(); 
    //two nodes ///////////////////
    int n,m;
    cin>>n>>m;
    an=Vi(m);
    g=Graphw(n);
    vis=c=is0=ong2=Vi(n);
    vector<E> edge;
    Vi deg(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v,u--,v--;
        edge.pb({u,v,i});
        g[u].pb({v,i});
        g[v].pb({u,i});
        deg[u]++,deg[v]++;
    }
    Vi inc(n,1);
    queue<int> q;
    REP(i,n) if(deg[i]==1) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        inc[u]=0;
        for(auto [v,w]:g[u]) {
            deg[v]--;
            if(deg[v]==0) q.push(v);
        }
    }
    int cycs=0;
    REP(i,n) cycs+=inc[i];
    if(cycs==n) {
        dfs(0);
    }
    else {
        REP(i,n) {
            if(g[i].size()>1&&inc[i]) {
                dfs(i);
                break;
            }
        }
    }
    REP(i,m) cout<<(an[i]?'R':'B');
    cout<<'\n';
    return 0;

}