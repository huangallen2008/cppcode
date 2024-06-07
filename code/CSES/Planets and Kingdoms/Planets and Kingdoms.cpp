#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) x*x
#define pii pair<int,int>
#define MD(x,m) (x%m+m)%m
#define md(x) MD(x,mod)
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
ll pw(ll x,ll p,ll m=mod) {
    ll r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return r;
};
ll inv(ll x,ll m=mod) {
    return pw(x,m-2,m);
}
struct Bridge {
    vector<int> low,vis,dep;
    vector<pii> an;
    vector<vector<int>> g;
    Bridge(vector<vector<int>> _g) {
        getBridge(_g);
    }
    void dfs(int u,int par) {
        vis[u]=1;
        low[u]=inf;
        for(auto v:g[u]) {
            if(vis[v]) {
                if(v==par) continue;
                low[u]=min(low[u],dep[v]);
                continue;
            }
            dep[v]=dep[u]+1;
            dfs(v,u);
            if(low[v]>dep[u])
                an.pb({u,v});
            low[u]=min(low[u],low[v]);
        }
    }
    vector<pii> getBridge(vector<vector<int>> _g) {
        g=_g;
        int n=SZ(g);
        low=vector<int>(n);
        vis=vector<int>(n);
        dep=vector<int>(n);
        an.clear();
        dfs(0,-1);
        return an;
    }
};
struct SCC {
    int scccnt=0;//scc數量
    vector<int> scc;//scc[x]:x在第幾個scc
    vector<int> end_order;//結束時間
    vector<int> vis;
    SCC(const vector<vector<int>> &g) {
        int n=SZ(g);
        vector<vector<int>> rg(n);
        vis=vector<int>(n);
        scc=vector<int>(n);
        REP(i,SZ(g))
            for(auto v:g[i]) rg[v].pb(i);
        REP(i,SZ(g))
            if(vis[i]==0)
                dfs1(rg,i);
        vis=vector<int>(n);
        reverse(ALL(end_order));
        for(auto u:end_order) {
            if(vis[u]==0) {
                scc[u]=scccnt++;
                dfs2(g,u);
            }
        }
    }
    void dfs1(const vector<vector<int>> &rg,int u) {
        vis[u]=1;
        for(auto v:rg[u]) {
            if(vis[v]) continue;
            dfs1(rg,v);
        }
        end_order.pb(u);
    }
    void dfs2(const vector<vector<int>> &g,int u) {
        vis[u]=1;
        for(auto v:g[u]) {
            if(vis[v]) continue;
            scc[v]=scc[u];
            dfs2(g,v);
        }
    }
};
int n,m;
int a,b;
vector<vector<int>> g;
signed main()
{
    IOS();
    cin>>n>>m;
    g=vector<vector<int>>(n);
    REP(i,m) {
        cin>>a>>b;
        a--; b--;
        g[a].pb(b);
    }
    SCC scc(g);
    cout<<scc.scccnt<<"\n";
    REP(i,n) cout<<scc.scc[i]+1<<" ";
    cout<<"\n";
    return 0;
}
