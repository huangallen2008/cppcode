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
    Graph g,gb,ng;
    vector<bool> vis;
    vector<int> end_order,sccid,ssum;
    vector<int> dp;
    int n,scccnt=0;
    int an=0;
    void init(int _n,Graph &_g,vector<int> &a) {
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
        ssum=vector<int>(scccnt);
        REP(i,n) ssum[sccid[i]]+=a[i];
        ng=Graph(scccnt);
        REP(i,n) {
            for(int v:g[i]) {
                if(sccid[i]!=sccid[v]) {
                    ng[sccid[i]].pb(sccid[v]);
                }
            }
        }
        dp=vector<int>(scccnt);
        vis=vector<bool>(scccnt);
        REP(i,scccnt) {
            if(!vis[i]) {
                dfs3(i);
            }
        }
        REP(i,scccnt) an=max(an,dp[i]);
    }
    void dfs3(int u) {
        vis[u]=1;
        for(int v:ng[u]) {
            if(!vis[v]) dfs3(v);
            dp[u]=max(dp[u],dp[v]);
        }
        dp[u]+=ssum[u];
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
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Graph g(n);
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
    }
    SCC scc;
    scc.init(n,g,a);
    cout<<scc.an<<'\n';
    return 0;
}
