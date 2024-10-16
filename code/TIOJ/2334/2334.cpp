#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v,w;
};
struct DSU {
    Vi p,sz;
    void operator=(DSU &x) {
        p=x.p,sz=x.sz;
    }
    void init(int n) {
        p=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
    }
    bool same(int a,int b) { return find(a)==find(b); }
};
struct TCC {
    Vi dep,low;
    vector<bool> isb;
    int n;
    Graphw g;
    DSU dsu;
    void dfs(int u,int pa) {
        for(auto [v,w]:g[u]) {
            if(dep[v]) {
                if(v==pa) {
                    continue;
                }
                chmin(low[u],dep[v]);
            }
            else {
                dep[v]=dep[u]+1;
                dfs(v,u);
                chmin(low[u],low[v]);
                if(low[v]>dep[u]) {
                    isb[v]=1;
                } 
            }
        }
        for(auto [v,w]:g[u]) {
            if(!isb[v]) dsu.merge(u,v);
        }
    }
    void init(Graphw _g) {
        g=_g;
        n=g.size();
        isb=vector<bool>(n);
        dep=Vi(n);
        low=Vi(n,inf);
        dsu.init(n);
        // dep[0]=1;
        REP(i,n) if(!dep[i]) dfs(i,-1);
    }
}tcc;
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    vector<edge> e(m);
    REP(i,m) cin>>e[i].u>>e[i].v>>e[i].w,e[i].u--,e[i].v--;
    vector<pair<DSU,int>> dsus;
    sort(ALL(e),[&](edge a,edge b) {
        return a.w<b.w;
    });
    Graphw gg(n);
    tcc.init(gg);
    dsus.pb({tcc.dsu,0});
    for(auto [u,v,w]:e) {
        if(dsus.back().f.same(u,v)) continue;
        gg[u].pb({v,w});
        gg[v].pb({u,w});
        tcc.init(gg);
        dsus.pb({tcc.dsu,w});
        oparr(tcc.dsu.p)ope(w)
    }
    int q;
    cin>>q;
    REP(i,q) {
        int u,v;
        cin>>u>>v,u--,v--;
        if(!dsus.back().f.same(u,v)) cout<<"-1\n";
        else {
            int l=0,r=dsus.size()-1,mid;
            while(l<r) {
                mid=l+r>>1;
                if(dsus[mid].f.same(u,v)) r=mid;
                else l=mid+1;
            }
            int an=dsus[l].s;
            cout<<an<<'\n';
        }
    }
    return 0;
}