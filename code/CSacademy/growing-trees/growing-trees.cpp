#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
#define ALL1(x) (x).begin()+1,(x).end()
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
const int maxn=1e5+5;
const int maxn2=2e5+5;
const int maxb=19;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct nod {
    int v,w,c;
};
int n,d;
vector<vector<nod>> g;
Vi dp,dep;
void dfs(int u,int fa,int mb) {
    int mx=0,mx2=0;
    for(auto [v,w,c]:g[u]) {
        if(v==fa) continue;
        w+=c*mb;
        dfs(v,u,mb);
        chmax(dp[u],dp[v]);
        int nd=dep[v]+w;
        chmax(dep[u],nd);
        if(nd>mx) mx2=mx,mx=nd;
        else if(nd>mx2) mx2=nd;
    }
    chmax(dp[u],mx+mx2);
}
int check(int mb) {
    if(mb==d+1) return inf;
    dp=dep=Vi(n);
    dfs(0,-1,mb);
    return dp[0];
}
signed main() {
    IOS(); 
    cin>>n>>d;
    g=vector<vector<nod>>(n);
    REP(i,n-1) {
        int u,v,w,c;
        cin>>u>>v>>w>>c,u--,v--;
        g[u].pb({v,w,c});
        g[v].pb({u,w,c});
    }
    int lb=0,rb=d,mb;
    while(lb<rb) {
        mb=lb+rb>>1;
        op(mb)op(check(mb))ope(check(mb+1))
        if(check(mb+1)-check(mb)>=0) rb=mb;
        else lb=mb+1;
    }
    cout<<lb<<'\n'<<check(lb)<<'\n';
    return 0;
}