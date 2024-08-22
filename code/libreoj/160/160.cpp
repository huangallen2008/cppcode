#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
int n,c;
vector<int> out,dfn,mo;
Graph g;
int cnt=0;
void dfs(int u) {
    for(int v:g[u]) {
        dfs(v);
        chmin(mo[u],mo[v]);
    }
    dfn.pb(u);
    out[u]=cnt++;
    chmin(mo[u],out[u]);
}
signed main() {
    IOS();
    cin>>n>>c;
    g=Graph(n);
    vector<int> d(n),w(n),v(n);
    out=vector<int>(n);
    mo=vector<int>(n,inf);
    REP(i,n) cin>>d[i],d[i]--;
    REP(i,n) if(d[i]!=-1) g[d[i]].pb(i);
    REP(i,n) cin>>w[i];
    REP(i,n) cin>>v[i];
    REP(i,n) if(d[i]==-1) dfs(i);
    vector<vector<int>> dp(n,vector<int>(c+1,-inf));
    dp[0][0]=0,dp[0][w[dfn[0]]]=v[dfn[0]];
    REP1(i,n-1) {
        int u=dfn[i];
        dp[i][0]=0;
        REP(j,c+1) {
            if(j>=w[u]) dp[i][j]=dp[i-1][j-w[u]]+v[u];
            if(mo[u]!=0) chmax(dp[i][j],dp[mo[u]-1][j]);
        }
    }
    int an=*max_element(ALL(dp[n-1]));
    cout<<an<<'\n';
    return 0;
}