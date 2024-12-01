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
Graphw g;
Vi dp,udp,ndp;
void dfs(int u,int fa) {
    for(auto [v,w]:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        chmin(dp[u],dp[v]+w);
    }
    if(g[u].size()==1&&fa!=-1) dp[u]=0;
}
void dfs1(int u,int fa) {
    int mn1=udp[u],mn2=inf;
    for(auto [v,w]:g[u]) {
        if(v==fa) continue;
        int val=dp[v]+w;
        if(val<mn1) mn2=mn1,mn1=val;
        else if(val<mn2) mn2=val;
    }
    Vi hv;
    for(auto [v,w]:g[u]) {
        if(v==fa) hv.pb(inf);
        else hv.pb(dp[v]+w);
    }
    int cc=hv.size();
    Vi p(cc),s(cc);
    //cc=1?
    p=s=hv;
    REP1(i,cc-1) chmin(p[i],p[i-1]);
    RREP(i,cc-1) chmin(s[i],s[i+1]);
    Vi nd(cc);
    REP(i,cc) nd[i]=min(i>0?p[i-1]:inf,i<cc-1?s[i+1]:inf);
    REP(i,cc) {
        auto [v,w]=g[u][i];
        if(v==fa) continue;
        udp[v]=min(udp[u],nd[i])+w;
        dfs(v,u);
    }
}
signed main() {
    IOS(); 
    int n;
    cin>>n;
    g=Graphw(n);
    dp=udp=Vi(n,inf);
    ndp=Vi(n);
    REP(i,n-1) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dfs(0,-1);
    oparr(dp)oparr(ndp)
    if(g[0].size()==1) ndp[0]=0;
    dfs1(0,-1);
    int mna=*min_element(ALL(ndp));
    cout<<mna<<'\n';
    return 0;
}