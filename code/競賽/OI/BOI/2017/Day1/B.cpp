#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
#define pii pair<int,int>
#define pipii pair<int,pii>
#define ppi pair<pii,int>
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
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=2e5+5;
const int maxb=17;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void _ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    void ud(int l,int r,int v)  {
        _ud(l,v);
        _ud(r+1,-v);
    }
    int qu(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
};
int n,m,k;
Graphw g;
Vi dfn,dfnp,dep;
Vpii dfn2;
Vi in,out,pe;
void dfs(int u,int fa) {
    dfnp[u]=SZ(dfn2);
    dfn2.pb({dep[u],u});
    for(auto [v,id]:g[u]) {
        if(v==fa) continue;
        pe[v]=id;
        in[id]=SZ(dfn);
        dfn.pb(id);
        dep[v]=dep[u]+1;
        dfs(v,u);
        out[id]=SZ(dfn);
        dfn.pb(id);
        dfn2.pb({dep[u],u});
    }
}
pii st[maxb][maxn];
void st_init() {
    int N=SZ(dfn2);
    REP(i,N) st[0][i]=dfn2[i];
    REP1(i,maxb-1) {
        REP(j,N) st[i][j]=min(st[i-1][j],st[i-1][min(N-1,j+(1<<i-1))]);
    }
}
int st_qu(int l,int r) {
    int lg=__lg(r-l+1);
    return min(st[lg][l],st[lg][r-(1<<lg)+1]).s;
}
int qu_lca(int a,int b) {
    if(dfnp[a]>dfnp[b]) swap(a,b);
    return st_qu(dfnp[a],dfnp[b]);
}
signed main() {
    IOS();
    cin>>n>>m>>k;
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb({v,i});
        g[v].pb({u,i});
    }
    dfn={-1};
    pe=in=out=dfnp=dep=Vi(n);
    dfs(0,-1);
    st_init();
    REP(i,m) {
        int s;
        cin>>s;
        Vi a(s);
        REP(j,s) cin>>a[j];
        sort(ALL(a),[&](int x,int y) {return in[x]<in[y]; });
        Vi b;b.pb(a[0]);
        REP1(i,s-1) {
            b.pb()
        }
    }
    return 0;
}
