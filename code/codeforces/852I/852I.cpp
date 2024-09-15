#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
// #define ll long long
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxb=20;
const int sn=500;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct Data {
    int u,v,l,r,id;
};
int n;
Graph g;
vector<int> gd,f,dfn,in,out,dep;
int cntn=0;
int lt[maxb][maxn];
void init_lca() {
    lt[0][0]=0;
    REP1(i,19) {
        REP(j,n) {
            lt[i][j]=lt[i-1][lt[i-1][j]];
        }
    }
}
int lca(int u,int v) {
    if(dep[u]>dep[v]) swap(u,v);
    int goo=dep[v]-dep[u];
    RREP(i,maxb) {
        if((goo>>i)&1) v=lt[i][v];
    }
    if(u==v) return -1;
    RREP(i,maxb) {
        if(lt[i][u]!=lt[i][v]) {
            u=lt[i][u];
            v=lt[i][v];
        }
    }
    return lt[0][u];
}
void dfs(int u,int pa) {
    dfn.pb(u);
    in[u]=cntn++;
    for(int v:g[u]) {
        if(v==pa) continue;
        lt[0][v]=u;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
    out[u]=cntn++;
    dfn.pb(u);
}
bool nc[maxn];
int cntp[maxn][2],s[maxn<<1];
int now=0;
void add(int u) {
    if(nc[u]) nc[u]=0,cntp[f[u]][gd[u]]--,now-=cntp[f[u]][gd[u]^1];
    else nc[u]=1,cntp[f[u]][gd[u]]++,now+=cntp[f[u]][gd[u]^1];
}
signed main() {
    IOS();
    REP(i,maxn<<1) s[i]=i/sn;
    cin>>n;
    g=Graph(n);
    in=out=gd=dep=f=vector<int>(n);
    REP(i,n) cin>>gd[i];
    REP(i,n) cin>>f[i];
    vector<int> ttf=f;
    sort(ALL(ttf));
    REP(i,n) f[i]=lower_bound(ALL(ttf),f[i])-ttf.begin();
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    init_lca();
    int q;
    cin>>q;
    vector<Data> qu(q);
    REP(i,q) {
        int u,v;
        cin>>u>>v,u--,v--;
        if(in[u]>in[v]) swap(u,v);
        if(out[v]<out[u]) qu[i]={u,v,in[u],in[v],i};
        else qu[i]={u,v,out[u],in[v],i};
    }
    sort(ALL(qu),[&](Data &a,Data &b) {
        if(s[a.l]!=s[b.l]) return a.l<b.l;
        if(s[a.l]&1) return a.r>b.r;
        return a.r<b.r;
    });
    vector<int> an(q);
    int il=0,ir=-1;
    for(auto &[u,v,l,r,id]:qu) {
        while(il>l) add(dfn[--il]);
        while(ir<r) add(dfn[++ir]);
        while(il<l) add(dfn[il++]);
        while(ir>r) add(dfn[ir--]);
        int _lca=lca(u,v);
        if(_lca==-1) an[id]=now;
        else {
            add(_lca);
            an[id]=now;
            add(_lca);
        }
    }
    REP(i,q) cout<<an[i]<<'\n';
    return 0;
}