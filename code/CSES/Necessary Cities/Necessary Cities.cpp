#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
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
const int maxn=5e4+5;
const int maxv=1e5+5;
const int inf=(1<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct AP {
    int n;
    vector<int> lev,hbe,aps;
    vector<bool> vis,isap;
    void init(int _n,Graph &g) {
        n=_n;
        vis=vector<bool>(n);
        isap=vector<bool>(n);
        lev=vector<int>(n);
        hbe=vector<int>(n);
        dfs(g,0,-1);
//        oparr(lev)oparr(hbe)
    }
    void dfs(Graph &g,int u,int p) {
        vis[u]=1;
        hbe[u]=lev[u];
        int cnt_chid=0,t_hbe=0;
        for(int v:g[u]) {
            if(vis[v]) {
                hbe[u]=min(hbe[u],lev[v]);
                continue;
            }
            cnt_chid++;
            lev[v]=lev[u]+1;
            dfs(g,v,u);
            if(!isap[u]&&hbe[v]>=lev[u]&&p!=-1) {
                isap[u]=1;
                aps.pb(u);
            }
            hbe[u]=min(hbe[u],hbe[v]);
        }
        if(p==-1&&cnt_chid>1) {
            aps.pb(u);
        }
    }
} ap;
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Graph g(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    ap.init(n,g);
    cout<<ap.aps.size()<<'\n';
    for(auto x:ap.aps) cout<<x+1<<' ';
    cout<<'\n';
    return 0;
}
