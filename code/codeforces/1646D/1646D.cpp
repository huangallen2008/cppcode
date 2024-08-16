#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii& operator+=(pii &a,pii b) {
    a.f+=b.f,a.s+=b.s;
}
Graph g;
vector<pii> dp[2];
vector<bool> use;
void dfs(int u,int pa) {
    ope(u)
    for(int v:g[u]) {
        if(v==pa) continue;
        dfs(v,u);
        dp[1][u]+=dp[0][v];
        dp[0][u]+=max(dp[0][v],dp[1][v]);
    }
    ope("uu")
    ope(dp[0].size())
    dp[0][u].s--;
    dp[1][u].f++,dp[1][u].s-=g[u].size();
    ope(u)
    op(dp[0][u].f)op(dp[0][u].s)
}
void dfs2(int u,int pa,int ty) {
    use[u]=ty;
    for(int v:g[u]) {
        if(v==pa) continue;
        if(ty) dfs2(v,u,0);
        else dfs2(v,u,dp[1][v]>dp[0][v]);
    }
}
signed main() {
    IOS();
    int n;
    cin>>n;
    dp[0]=vector<pii>(n);
    dp[1]=vector<pii>(n);
    use=vector<bool>(n);
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    ope("ok")
    pii an=max(dp[0][0],dp[1][0]);
    cout<<an.f<<' '<<an.s<<'\n';
    if(dp[0][0]==an) dfs2(0,-1,0);
    else dfs2(0,-1,1);
    REP(i,n) {
        if(use[i]) cout<<g[i].size()<<' ';
        else cout<<1<<'\n';
    }
    return 0;
}