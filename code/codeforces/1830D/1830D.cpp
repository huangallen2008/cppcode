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
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
vector<int> sz;
pair<vector<int>,vector<int>> dfs(int u,int pa) {
    vector<int> v0(sn,inf),v1(sn,inf);
    v0[1]=v1[1]=0;
    for(int v:g[u]) {
        if(v==pa) continue;
        vector<int> t0(sn,inf),t1(sn,inf);
        auto [r0,r1]=dfs(v,u);
        REP(i,sz[u]+1) {
            REP(j,sz[v]+1) {
                if(i+j>=sn) continue;
                chmin(t0[i+j],v0[i]+r0[j]);
                chmin(t1[i+j],v1[i]+r1[j]);
            }
        }
        t0.swap(v0);
        t1.swap(v1);
        sz[u]+=sz[v];
        chmin(sz[u],sn-1);
    }
    REP1(i,sn-1) {
        chmin(v0[0],v1[i]+(i*(i+1)>>1));
        chmin(v1[0],v0[i]+i*(i+1));
    }
    ope(u)oparr(v0)oparr(v1)
    return {v0,v1};
}
void solve() {
    int n;
    cin>>n;
    // dp0=dp1=vector<int>(n);
    sz=vector<int>(n,1);
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    auto [d0,d1]=dfs(0,-1);
    int an=(n*(n+1)>>1)*2-min(d0[0],d1[0]);
    cout<<an<<'\n';
    entr
}
signed main() {
    IOS();
    int T=1;
    cin>>T;while(T--) 
    solve();
    return 0;
}