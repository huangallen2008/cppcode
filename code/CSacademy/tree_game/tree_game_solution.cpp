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
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Graph g;
Vi ac,bc;
Vi dp[3];//0:no path to alex 1:have one path.. 2.no path and no alex parent  3.
void dfs(int u,int fa) {
    int mx=-inf;//
    int mx1=-inf;//max dp[1]-max(dp[0],dp[1])
    int mx2=-inf;// sec max dp[1]-max(dp[0],dp[1])
    for(auto v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        dp[0][u]+=max(dp[1][v],dp[2][v]+1);
        dp[2][u]+=dp[1][v];
        chmax(mx,max(dp[0][v],dp[2][v])-dp[1][v]);
        int val=max(dp[0][v],dp[2][v])-max({dp[0][v],dp[1][v],dp[2][v]});
        dp[1][u]+=max({dp[0][v],dp[1][v],dp[2][v]});
        if(val>mx1) mx2=mx1,mx1=val;
        else if(val>mx2) mx2=val;
    }
    dp[1][u]+=1+mx1+mx2;
    chmax(dp[1][u],dp[2][u]);
    dp[2][u]+=mx;
}
signed main() {
    IOS(); 
    cin>>n;
    g=Graph(n);
    dp[0]=dp[2]=Vi(n);

    dp[1]=Vi(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    oparr(dp[0])oparr(dp[1])oparr(dp[2])
    //g[0] sz=1->b[0]=0;
    int an=max({dp[0][0],dp[1][0],dp[2][0]});
    cout<<an<<'\n';
    return 0;
}