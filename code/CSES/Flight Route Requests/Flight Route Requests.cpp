#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
//#define int long long
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
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int n,m;
Graph g;
vector<bool> inc,vis,hv_c;
vector<int> sz;
void dfs(int u) {
    vis[u]=1;
    int r=0;
    hv_c[u]=inc[u];
    for(int v:g[u]) {
        if(vis[v]) continue;
        dfs(v);
        hv_c[u]=hv_c[u]||hv_c[v];
        sz[u]+=sz[v];
    }
}
signed main() {
    IOS();
    cin>>n>>m;
    Graph gd(n);
    g=Graph(n);
    vector<int> ind(n);
    vis=vector<bool>(n);
    hv_c=vector<bool>(n);
    sz=vector<int>(n,1);
    inc=vector<bool>(n,1);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        gd[u].pb(v);
        ind[v]++;
    }
    queue<int> q;
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        inc[u]=0;
        for(int v:gd[u]) {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    int an=0;
    REP(i,n) {
        if(!vis[i]) {
            dfs(i);
            an+=sz[i]-1+hv_c[i];
        }
    }
    cout<<an<<'\n';
    return 0;
}
