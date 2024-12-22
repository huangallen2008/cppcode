#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#pragma GCC optimize("unroll-loops")
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
#define entr cout<<endl;
#define maxn (int)(2e5+5)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define GC _getchar_nolock()
#define PC _putchar_nolock
#else 
#define GC getchar_unlocked()
#define PC putchar_unlocked
#endif

inline int read()
{
    int x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=-x;
    return x;
}
inline void out(int x) {
    if(x<0) {
        PC('-');
        x=-x;
    }
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PC(*it);
    PC('\n');
}
const int inf=(1<<30);
//const int maxn=2e5+5;
const int mod=1e9+7;
int n,k1,k2;
ll an=0;
vector<int> g[maxn];
int sz[maxn],deg[maxn];
bool vis[maxn];
int edgeu[maxn],edgev[maxn];
int mxd=0;
int su=0;
int ct[maxn];
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
inline void get_cnt1(int u,int p,int dep) {
    if(dep>k2) return;
    mxd=max(mxd,dep);
    su-=ct[k2-dep+1];
    if(dep<=k1) su+=ct[k1-dep];
    an+=su;
    for(int &v:g[u]) {
        if(vis[v]||v==p) continue;
        get_cnt1(v,u,dep+1);
    }
    su+=ct[k2-dep+1];
    if(dep<=k1) su-=ct[k1-dep];
}
inline void get_cnt2(int u,int p,int dep) {
    if(dep>k2) return;
    ct[dep]++;
    for(int &v:g[u]) {
        if(vis[v]||v==p) continue;
        get_cnt2(v,u,dep+1);
    }
}
inline void centroid_decomp(int root) {
    int centroid=get_centroid(get_tree_sz(root,-1)>>1,root,-1);
    vis[centroid]=1;
    mxd=0;
    for(int &v:g[centroid]) {
        if(vis[v]) continue;
        su=0;
        for(int i=k1;i<=min(mxd,k2);i++) su+=ct[i];
        get_cnt1(v,-1,1);
        get_cnt2(v,-1,1);
    }
    fill(ct+1,ct+mxd+1,0);
    for(int &v:g[centroid]) {
        if(!vis[v]) centroid_decomp(v);
    }
}
signed main() {
    IOS();
    n=read(),k1=read(),k2=read();
    // cin>>n>>k1>>k2;
    ct[0]=1;
    REP(i,n-1) {
        int u=read()-1,v=read()-1;
        // cin>>u>>v;
        // u--,v--;
        deg[u]++,deg[v]++;
        edgeu[i]=u;
        edgev[i]=v;
    }
    REP(i,n) g[i].reserve(deg[i]);
    REP(i,n-1) {
        g[edgeu[i]].pb(edgev[i]);
        g[edgev[i]].pb(edgeu[i]);
    }
    centroid_decomp(rd(1,n));
    cout<<an<<'\n';
    return 0;
}
