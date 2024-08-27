#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
pii& op2(pii &a) { cout<<"{"<<a.f<<","<<a.s<<"} "; return a; }
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
Graph g;
int n,q;
vector<int> col,sz;
vector<vector<pii>> dp;
const pii zr={-1,-1};
pii merge(pii a,pii b) {
    if(a==zr) return b;
    if(b==zr) return a;
    return {min(a.f,b.f),max(a.s,b.s)};
}
pii operator+(pii a,pii b) {
    if(a==zr) return zr;
    if(b==zr) return zr;
    return {a.f+b.f,a.s+b.s};
}
void dfs(int u,int pa) {
    if(col[u]) {
        dp[u][1]={1,1};
    }
    else {
        dp[u][0]={1,1};
    }
    for(int v:g[u]) {
        if(v==pa) continue;
        dfs(v,u);
        vector<pii> t(n+1,zr);
        REP(i,sz[u]+1) {
            REP(j,sz[v]+1) {
                t[i+j]=merge(t[i+j],dp[u][i]+dp[v][j]);
            }
        }
        t.swap(dp[u]);
        sz[u]+=sz[v];
    }
    dp[u][0]=merge(dp[u][0],{0,0});
}
bool inr(pii r,int x) {
    return r.f<=x&&x<=r.s;
}
void solve() {
    cin>>n>>q;
    sz=vector<int>(n,1);
    col=vector<int>(n);
    dp=vector<vector<pii>>(n,vector<pii>(n+1,zr));
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i,n) cin>>col[i];
    dfs(0,-1);
    vector<pii> rg(n+1,zr);
    REP(i,n) REP(j,n+1) rg[j]=merge(rg[j],dp[i][j]);
    REP(i,q) {
        int b,s;
        cin>>s>>b;
        if(inr(rg[b],s)) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}