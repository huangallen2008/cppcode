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
#define G vector<bitset<maxn>>
const int mod=1e9+7;
const int maxn=5e4+5;
const int maxv=1e5+5;
const int inf=(1<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SCC {
    vector<bool> vis;
    int n;
    vector<int> sccid;
    vector<int> end_order;
    G l;
    Graph ng;
    void init(int _n,Graph &g) {
        n=_n;
        Graph gb(n);
        REP(i,n) for(int v:g[i]) gb[v].pb(i);
        vis=vector<bool>(n);
        REP(i,n) if(!vis[i]) dfs1(g,i);
        reverse(ALL(end_order));
        sccid=vector<int>(n);
        vis=vector<bool>(n);
        int cnt_id=0;
        for(int i:end_order) {
            if(!vis[i]) {
                sccid[i]=cnt_id++;
                dfs2(gb,i);
            }
        }
        ng=Graph(cnt_id);
        REP(i,n) {
            for(int v:g[i]) {
                if(sccid[i]!=sccid[v]) {
                    ng[sccid[i]].pb(sccid[v]);
                }
            }
        }
        l=G(cnt_id);
        REP(i,cnt_id) l[i][i]=1;
        RREP(i,cnt_id) {
            for(int v:ng[i]) {
                l[i]|=l[v];
            }
        }
    }
    void dfs1(Graph &g,int u) {
        vis[u]=1;
        for(int v:g[u]) {
            if(!vis[v]) dfs1(g,v);
        }
        end_order.pb(u);
    }
    void dfs2(Graph &gb,int u) {
        vis[u]=1;
        for(int v:gb[u]) {
            if(vis[v]) continue;
            sccid[v]=sccid[u];
            dfs2(gb,v);
        }
    }
    bool can_reach(int u,int v) {
        int a=sccid[u],b=sccid[v];
        return l[a][b];
    }
} scc;
signed main() {
    IOS();
    int n,m,q;
    cin>>n>>m>>q;
    Graph g(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
    }
    scc.init(n,g);
    REP(i,q) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        if(scc.can_reach(u,v)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
