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
const int inf=(1ll<<61);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graphw g;
Vi mxd,dia,dib,mnd;
void dfs0(int u,int fa) {
    int mx1=0,mx2=0;
    for(auto [v,w]:g[u]) {
        if(v==fa) continue;
        dfs0(v,u);
        int val=mxd[v]+w;
        chmax(dia[u],dia[v]);
        chmax(mxd[u],val);
        if(val>mx1) mx2=mx1,mx1=val;
        else if(val>mx2) mx2=val;
    }
    chmax(dia[u],mx1+mx2);
}
void dfs1(int u,int fa) {
    int mn1=inf,mn2=inf;
    for(auto [v,w]:g[u]) {
        if(v==fa) continue;
        dfs1(v,u);
        int val=mnd[v]+w;
        chmin(dib[u],dib[v]);
        chmin(mnd[u],val);
        if(val<mn1) mn2=mn1,mn1=val;
        else if(val<mn2) mn2=val;
    }
    chmin(dib[u],mn1+mn2);
    if(fa==-1&&g[u].size()==1) chmin(dib[u],mn1);
    if(g[u].size()==1) mnd[u]=0;
}
signed main() {
    IOS(); 
    int n;
    cin>>n;
    g=Graphw(n);
    dib=mnd=Vi(n,inf);
    REP(i,n-1) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dia=mxd=Vi(n);
    dfs0(0,-1);
    dfs1(0,-1);
    cout<<dia[0]<<' '<<dib[0]<<'\n';
    return 0;
}