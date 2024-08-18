#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
#define ll long long
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
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Graph g;
vector<vector<int>> dp0,dp1,dp2;
vector<int> sz;
void dfs(int u,int pa) {
    // vector<int> tt0(n+1),tt1(n+1);
    // tt0[0]=tt1[1]=1;
    dp0[u][0]=dp2[u][1]=1;
    // int cc=1;
    for(int v:g[u]) {
        if(v==pa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        vector<int> t1(n+1),t2(n+1),t0(n+1);
        // op(sz[u])ope(sz[v])
        for(int i=sz[u];i>=0;i--) {
            for(int j=i;j>=i-sz[v]-1&&j>=0;j--) {
                addmod(t0[i],dp0[u][j]*1ll*(dp0[v][i-j]+dp1[v][i-j]));
                addmod(t1[i],dp1[u][j]*1ll*((ll)dp0[v][i-j]+dp1[v][i-j]+dp2[v][i-j])+(i>j?dp0[u][j]*dp2[v][i-j-1]:0));
                addmod(t2[i],dp2[u][j]*1ll*((ll)dp1[v][i-j]+dp2[v][i-j]+(i>j?dp0[v][i-j-1]:0)));
            }
        }
        // oparr(t0)oparr(t1)oparr(t2)entr
        t0.swap(dp0[u]);
        t1.swap(dp1[u]);
        t2.swap(dp2[u]);
        // cc+=sz[v];
    }
    // if(sz[u]!=1) {
    //     for(int i=1;i<=sz[u];i++) dp1[u][i]=(t0[i-1]+t1[i-1])%mod;
    //     for(int i=0;i<=sz[u];i++) dp0[u][i]=(t0[i]+(i>0?t1[i-1]:0))%mod;
    // }
    // else {
    //     dp0[u][0]=dp1[u][1]=1;
    // }
}
signed main() {
    IOS();
    cin>>n;
    g=Graph(n);
    sz=vector<int>(n,1);
    dp0=dp1=dp2=vector<vector<int>>(n,vector<int>(n+1));
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    vector<int> an(n+1);
    // REP(i,n) {REP(j,n+1) cout<<dp0[i][j]<<' ';entr}entr
    // REP(i,n) {REP(j,n+1) cout<<dp1[i][j]<<' ';entr}entr
    // REP(i,n) {REP(j,n+1) cout<<dp2[i][j]<<' ';entr}entr
    REP(i,n+1) an[i]=((ll)dp0[0][i]+dp1[0][i]+dp2[0][i])%mod;
    REP(i,n+1) cout<<an[i]<<'\n';
    return 0;
}