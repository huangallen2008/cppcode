#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define md(x) (x%mod+mod)%mod
#ifdef local
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
struct SCC {
    Graph g,gb;
    vector<bool> vis;
    vector<int> end_order,sccid;
    int n,scccnt=0;
    void init(int _n,Graph &_g) {
        g=_g;
        n=_n;
        gb=Graph(n);
        sccid=vector<int>(n);
        REP(i,n) for(int v:g[i]) gb[v].pb(i);
        vis=vector<bool>(n);
        REP(i,n) if(!vis[i]) dfs1(i);
        reverse(ALL(end_order));
        vis=vector<bool>(n);
        for(int i:end_order) {
            if(!vis[i]) {
                sccid[i]=scccnt++;
                dfs2(i);
            }
        }
    }
    void dfs1(int u) {
        vis[u]=1;
        for(int v:g[u]) {
            if(vis[v]) continue;
            dfs1(v);
        }
        end_order.pb(u);
    }
    void dfs2(int u) {
        vis[u]=1;
        for(int v:gb[u]) {
            if(vis[v]) continue;
            sccid[v]=sccid[u];
            dfs2(v);
        }
    }
};
struct TwoSAT {
    int n=0;
    bool ok=1;
    Graph g;
    vector<bool> an;
    void init(int _n,vector<pii> &cons) {
        n=_n;
        an=vector<bool>(n+1);
        g=Graph(n<<1);
        for(auto [x,y]:cons) {
            g[id(-x)].pb(id(y));
            g[id(-y)].pb(id(x));
        }
        SCC scc;
        scc.init(n<<1,g);
        REP1(i,n) {
            if(scc.sccid[id(i)]==scc.sccid[id(-i)]) {
                ok=0;
                break;
            }
            if(scc.sccid[id(i)]>scc.sccid[id(-i)]) {
                an[i]=1;
            }
        }
    }
    int id(int x) { return x+n-(x>0); }
};
signed main() {
    IOS();
    int n,m;
    cin>>m>>n;
    TwoSAT tsat;
    vector<pii> cons(m);
    REP(i,m) {
        char cx,cy;
        int x,y;
        cin>>cx>>x>>cy>>y;
        if(cx=='+') cons[i].f=x;
        else cons[i].f=-x;
        if(cy=='+') cons[i].s=y;
        else cons[i].s=-y;
    }
    tsat.init(n,cons);
    if(tsat.ok) {
        REP1(i,n) cout<<(tsat.an[i]?'+':'-')<<' ';
        cout<<'\n';
    }
    else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
