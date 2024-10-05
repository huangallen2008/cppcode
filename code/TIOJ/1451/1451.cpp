#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,(n))
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define MD(x,m) ((x)%(m)+(m))%(m)
#define md(x) MD(x,mod)
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll inf = 1ll<<62;
const int iinf=2147483647;
const ll mod = 1e9+9;
const ll maxn=1e5+5;
const double PI=acos(-1);
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
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
        scccnt=0;
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
struct TwoSAT {//1-based
    bool ok=1;
    int n;
    vector<int> an;
    vector<vector<int>> g;
    TwoSAT(int _n,vector<pii> cons) {
        ok=1;
        n=_n;
        an=vector<int>(n+1);
        g=vector<vector<int>>(n*2);
        for(auto [u,v]:cons) {
            g[id(-u)].pb(id(v));
            g[id(-v)].pb(id(u));
        }
        SCC scc(g);
        REP1(i,n) {
            if(scc.scc[id(i)]==scc.scc[id(-i)]) {
                ok=0;
                break;
            }
            if(scc.scc[id(i)]<scc.scc[id(-i)]) an[i]=1;
            else an[i]=0;
        }
    }
    int id(int x) { return x+n-(x<0?0:1); }
};
int n,m;
int x,y;
int an;
vector<int> p;
int find(int u) {
    if(p[u]==u) return u;
    return p[u]=find(p[u]);
}
void merge(int x,int y) {
    int a=find(x),b=find(y);
    if(y==b) {
        p[y]=a;
        an--;
    }
}
signed main()
{
    IOS();
    cin>>n>>m;
    an=n;
    p=vector<int>(n);
    REP(i,n) p[i]=i;
    REP(i,m) {
        cin>>x>>y;
        x--;y--;
        merge(x,y);
    }
    cout<<an<<"\n";
    return 0;
}
