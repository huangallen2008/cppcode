#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#ifdef local
#define entr cout<<endl;
#endif

const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
int n,k1,k2;
//Graph g;
int an=0;
vector<int> g[maxn];
//vector<int> sz;
int sz[maxn],deg[maxn];
bool vis[maxn];
int edgeu[maxn],edgev[maxn];
//vector<bool> vis;
int mxd=0;
struct BIT {
    vector<int> b={};
    int n=0;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {//zero-base
        u++;
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        u++;
//        op(n)ope(u)
        if(u<=0) return 0;
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    void to0(int u) {
        u++;
        REP1(i,u) b[i]=0;
    }
};
BIT cnt;
inline int get_tree_sz(int u,int p) {
    sz[u]=1;
    for(int &v:g[u]) {
        if(vis[v]||v==p) continue;
        sz[u]+=get_tree_sz(v,u);
    }
    return sz[u];
}
inline int get_centroid(const int tree_sz,int u,int p) {
    for(int &v:g[u]) {
        if(v==p||vis[v]) continue;
        if(sz[v]>tree_sz) return get_centroid(tree_sz,v,u);
    }
    return u;
}
inline void get_cnt(int u,int p,int dep,const bool fil) {
    if(dep>k2) return;
    mxd=max(mxd,dep);
    if(!fil) {
//        op(dep)ope(an)
//        op(k2-dep)op(cnt.qu(k2-dep))
        op(k2-dep)ope(k1-dep-1)
        an+=cnt.qu(k2-dep)-cnt.qu(k1-dep-1);
        ope(an)
    }
    else cnt.ud(dep,1);
    for(int &v:g[u]) {
        if(vis[v]||v==p) continue;
        get_cnt(v,u,dep+1,fil);
    }
}
inline void centroid_decomp(int root) {
    int centroid=get_centroid(get_tree_sz(root,-1)>>1,root,-1);
    vis[centroid]=1;
    mxd=0;
    cnt.ud(0,1);
//    cnt[0]=1;
    for(int &v:g[centroid]) {
        if(vis[v]) continue;
        get_cnt(v,-1,1,0);
        get_cnt(v,-1,1,1);
    }
    cnt.to0(mxd);
//    ope(centroid)
//    fill(cnt+1,cnt+mxd+1,0);
    op(centroid)ope(an)
    for(int &v:g[centroid]) {
//            op(centroid)ope(v)
        if(!vis[v]) centroid_decomp(v);
    }
}
signed main() {
    IOS();
    cin>>n>>k1>>k2;
    cnt.init(n+2);
    cnt.ud(0,1);
//    ope(n)
//    g=Graph(n);
//    vis=vector<bool>(n);
//    sz=vector<int>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        deg[u]++,deg[v]++;
        edgeu[i]=u;
        edgev[i]=v;
    }
    REP(i,n) g[i].reserve(deg[i]);
    REP(i,n-1) {
        g[edgeu[i]].pb(edgev[i]);
        g[edgev[i]].pb(edgeu[i]);
    }
    centroid_decomp(0);
    cout<<an<<'\n';
//    ope(1)
    return 0;
}
