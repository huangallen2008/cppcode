#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
#define int long long
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
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
bitset<maxn> vis=0;
vector<int> sz,deg,cnt;
void dfs(int u) {
    vis[u]=1;
    for(int v:g[u]) {
        if(vis[v]) continue;
        dfs(v);
        sz[u]+=sz[v];
        cnt[u]+=cnt[v];
    }
    if(deg[u]&1) cnt[u]++;
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    g=Graph(n);
    sz=vector<int>(n,1);
    deg=vector<int>(n);
    cnt=vector<int>(n);
    REP(i,m)  {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++,deg[v]++;
    }
    int cnta=0,an=0;
    REP(i,n) {
        if(!vis[i]) {
            dfs(i);
            if(g[i].size()==0&&i!=0) continue;
            cnta++;
            an+=max((cnt[i]>>1)-1,(int)0);
        }
    }
    an+=cnta;
    if(cnta==1&&cnt[0]==0) an=0;
    cout<<an<<'\n';
    return 0;
}