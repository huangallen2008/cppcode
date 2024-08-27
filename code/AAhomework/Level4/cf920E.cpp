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
#ifdef LOCAL
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
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
struct DSU {
    vector<int> p,sz;
    int n;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        p[x]=y;
        sz[y]+=sz[x];
    }
    void merger(int l,int r) {
        if(l>r) return;
        int t=find(l);
        while(t<r) {
            merge(t,t+1);
            t=find(t+1);
        }
    }
} dsu;
vector<vector<int>> g;
int n,m;
signed main() {
    IOS();
    cin>>n>>m;
    g=Graph(n);
    dsu.init(n);
    REP(u,n) g[u].pb(-1),g[u].pb(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<pii> edges;
    REP(u,n) {
        sort(ALL(g[u]));
        REP(i,g[u].size()-1) {
            if(g[u][i]+1<g[u][i+1]) {
                dsu.merger(g[u][i]+1,g[u][i+1]-1);
                edges.pb({u,g[u][i+1]-1});
            }
        }
    }
    for(auto &[u,v]:edges) dsu.merge(u,v);
    vector<int> an;
    REP(i,n) {
        if(dsu.p[i]==i) an.pb(dsu.sz[i]);
    }
    sort(ALL(an));
    cout<<an.size()<<'\n';
    for(int &x:an) cout<<x<<' ';
    cout<<'\n';
    return 0;
}
