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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Graph g;
vector<int> dp0,dp1,pd0,pd1,pre,suf,an;
void dfs(int u,int fa) {
    int mxv=-inf;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        dp1[u]+=dp0[v];
        pre[v]=mxv;
        chmax(mxv,dp1[v]-dp0[v]);
    }
    mxv=-inf;
    RREP(i,g[u].size()) {
        int v=g[u][i];
        if(v==fa) continue;
        suf[v]=mxv;
        chmax(mxv,dp1[v]-dp0[v]);
    }
    dp0[u]=max(mxv+1,0ll)+dp1[u];
}
void dfs2(int u,int fa) {
    if(fa==-1) {
        pd1[u]=0;
    }
    else {
        pd1[u]=pd0[fa]+dp1[fa]-dp0[u];
        pd0[u]=pd1[u]+max(max({pre[u],suf[u],fa==0?-inf:pd1[fa]-pd0[fa]})+1,0ll);
    }
    an[u]=dp1[u]+pd0[u];
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs2(v,u);
    }
}
signed main() {
    IOS();
    cin>>n;
    g=Graph(n);
    dp0=dp1=pd0=pd1=pre=suf=an=vector<int>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1),dfs2(0,-1);
    int cnt=0;
    REP(i,n) cnt+=dp0[0]==an[i];
    cout<<cnt<<'\n';
    return 0;
}
