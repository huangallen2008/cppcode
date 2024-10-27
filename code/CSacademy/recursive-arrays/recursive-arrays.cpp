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
Vi inc,a,dep,vis;
int dfs1(int u,int fa,int ori) {
    vis[u]=1;
    int ret=-1;
    for(int v:g[u]) {
        if(v==fa) continue;
        if(v==ori) {
            inc[u]=1;
            ret=1;
            continue;
        }
        int rr=dfs1(v,u,ori);
        if(rr!=-1) ret=rr+1;
        if(inc[v])inc[u]=1;
    }
    return ret;
}
void dfs2(int u,int fa,int ori) {
    if(inc[u]) dep[u]=0;
    for(int v:g[u]) {
        if(v==fa||v==ori) continue;
        dep[v]=dep[u]+1;
        dfs2(v,u,fa);
    }
}
signed main() {
    IOS(); 
    cin>>n;
    g=Graph(n);
    inc=a=Vi(n);
    REP(i,n) {
        cin>>a[i],a[i]--;
        g[a[i]].pb(i);
    }
    Vi t;
    REP(i,n) if(!vis[i]) t.pb(dfs1(i,-1,i));
    dfs2(0,-1,0);
    int mxd=0;
    REP(i,n) chmax(mxd,dep[i]);
    ope(t.size())
    oparr(t);
    return 0;
}