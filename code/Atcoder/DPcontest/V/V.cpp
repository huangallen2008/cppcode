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
// const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
int n,k;
int mod;
vector<int> dp,pre,suf,pd,an;
void dfs(int u,int fa) {
    int p=1,s=1;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        pre[v]=p;
        p=p*(dp[v]+1)%mod;
        dp[u]=dp[u]*(dp[v]+1)%mod;
    }
    RREP(i,g[u].size()) {
        int v=g[u][i];
        if(v==fa) continue;
        suf[v]=s;
        s=s*(dp[v]+1)%mod;
    }
}
void dfs2(int u,int fa) {
    if(fa==-1) pd[u]=1;
    else pd[u]=(pd[fa]*pre[u]%mod)*suf[u]%mod+1;
    an[u]=dp[u]*pd[u]%mod;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs2(v,u);
    }
}
signed main() {
    IOS();
    int 
    cin>>n>>mod;
    g=Graph(n);
    dp=vector<int>(n,1);
    pd=vector<int>(n);
    pre=vector<int>(n);
    suf=vector<int>(n);
    an=vector<int>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    dfs2(0,-1);
    REP(i,n) cout<<an[i]<<'\n';
    return 0;
}
