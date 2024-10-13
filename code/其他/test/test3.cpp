#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
//#define int long long
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const ll inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
vector<int> g[maxn];
int n,m;
int a[maxn],id[maxn];
ll dp[maxn],mxdep[maxn];
bool vis[maxn];
void dfs(int u) {
    vis[u]=1;
    ll mxd1=0,mxd2=0;
    for(int v:g[u]) {
        if(vis[v]) continue;
        dfs(v);
        dp[u]=max(dp[u],dp[v]);
        if(mxdep[v]>mxd1) {
            mxd2=mxd1;
            mxd1=mxdep[v];
        }
        else if(mxdep[v]>mxd2) mxd2=mxdep[v];
    }
    dp[u]=max(dp[u],a[u]+mxd1+mxd2);
    mxdep[u]=mxd1+a[u];
}
signed main() {
    IOS();
//    #ifdef LOCAL
//        freopen("in.txt","r",stdin);
//    #endif // LOCAL
    cin>>n>>m;
//    g=Graph(n);
//    a=vector<int>(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    REP(i,n) cin>>a[i];
    if(n==m) {
        REP(i,n) id[i]=i;
        shuffle(id,id+n,rng);
        int rd=0;
        ll an=-inf;
        while((clock())<100&&rd<n) {
//            long double time=(long double)clock()/CLOCKS_PER_SEC;
//            cout<<fixed<<setprecision(3)<<time<<endl;
//            vis=vector<bool>(n);
            REP(i,n) {
                vis[i]=0;//
                dp[i]=-inf;
                mxdep[i]=-inf;
            }
            REP(i,n) shuffle(ALL(g[i]),rng);
            dfs(id[rd]);
            an=max(an,dp[id[rd++]]);
        }
        cout<<an<<'\n';
    }
    else {
//        vis=vector<bool>(n);
        REP(i,n) {
            vis[i]=0;//
            dp[i]=-inf;
            mxdep[i]=-inf;
        }
        dfs(0);
        cout<<dp[0]<<'\n';
    }
    return 0;
}
