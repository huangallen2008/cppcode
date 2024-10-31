#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define ALL1(x) (x).begin()+1,(x).end()
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
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxn2=2e5+5;
const int maxb=19;
const int inf=(1ll<<62); 
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
    PC(' ');
}
Graph g;
int n,q;
int dfn2=0;
Vi dfn,in,out,id,dep;
void dfs(int u,int fa) {
    id[u]=dfn.size();
    dfn.pb(u);
    in[u]=dfn2++;
    for(int v:g[u]) {
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        dfn.pb(u);
    }
    out[u]=dfn2++;
}
pii min(pii a,pii b) { return a<b?a:b; }
int min(int a,int b) { return a<b?a:b; }
pii st[maxb][maxn2];
void st_init() {
    int n0=dfn.size();
    REP(i,n0) st[0][i]={dep[dfn[i]],dfn[i]};
    REP1(i,maxb-1) {
        int R=n0-(1<<i);
        REP(j,R) {
            st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
        }
    } 
}
pii st_qu(int l,int r) {
    int lg=__lg(r-l+1);
    return min(st[lg][l],st[lg][r-(1<<lg)+1]);
}
pii get_lca(int a,int b) {
    if(id[a]>id[b]) swap(a,b);
    return st_qu(id[a],id[b]);
}
int dis(int a,int b) {
    return dep[a]+dep[b]-(get_lca(a,b).f<<1);
}
bool ispa(int u,int v) {//is_parent or the same vertix
    return in[u]<=in[v]&&out[v]<=out[u];
}
signed main() {
    IOS(); 
    n=read(),q=read();
    // cin>>n>>q;
    g=Graph(n);
    id=in=out=dep=Vi(n);
    REP(i,n-1) {
        int u=read()-1,v=read()-1;
        // cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    st_init();
    REP(i,q) {
        int u=read()-1,v=read()-1,w=read()-1;
        // cin>>u>>v>>w,u--,v--,w--;
        pii r1=get_lca(u,v),r2=get_lca(u,w),r3=get_lca(v,w);
        int mn=max({r1.f,r2.f,r3.f});
        int an;
        if(r1.f==mn) {
            an=r1.s;
        }
        else if(r2.f==mn) {
            an=r2.s;
        }
        else {
            an=r3.s;
        }
        int ans=dis(an,u)+dis(an,v)+dis(an,w);
        out(an+1),out(ans),PC('\n');
        // cout<<an+1<<' '<<ans<<'\n';
    }
    return 0;
}