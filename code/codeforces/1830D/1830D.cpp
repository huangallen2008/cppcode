#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math,no-stack-protector")
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
#define del(x) (x).clear(),(x).shrink_to_fit()
#ifdef LOCAL_
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
const int sn=600;
const int inf=(1<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
vector<int> sz;
pair<vector<int>,vector<int>> dfs(int u,int pa) {
    vector<int> dp0(2,inf),dp1(2,inf);
    dp0[1]=dp1[1]=0;
    for(int v:g[u]) {
        if(v==pa) continue;
        auto [dp0v,dp1v]=dfs(v,u);
        int N=min(sz[u]+sz[v]+1,sn);
        vector<int> t0(N,inf),t1(N,inf);
        REP(i,sz[u]+1) {
            REP(j,sz[v]+1) {
                if(i+j>=sn) continue;
                chmin(t0[i+j],dp0[i]+dp0v[j]);
                chmin(t1[i+j],dp1[i]+dp1v[j]);
            }
        }
        t0.swap(dp0);
        t1.swap(dp1);
        sz[u]+=sz[v];
        chmin(sz[u],sn-1);
    }
    REP1(i,dp0.size()-1) {
        chmin(dp0[0],dp1[i]+(i*(i+1)>>1));
        chmin(dp1[0],dp0[i]+i*(i+1));
    }
    return {dp0,dp1};
}
void solve() {
    int n;
    cin>>n;
    sz=vector<int>(n,1);
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    auto [dp0,dp1]=dfs(0,-1);
    ll an=n*(ll)(n+1)-min(dp0[0],dp1[0]);
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T=1;
    cin>>T;while(T--) 
    solve();
    return 0;
}