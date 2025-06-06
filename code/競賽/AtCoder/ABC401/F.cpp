#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
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
const int mod=1e9;
const int maxn=500+5;
const int maxb=18;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
template<class T>
struct Func {
    T func;
    Func(const T &func):func(func) {}
    template<class... Args>
    constexpr decltype(auto) operator()(Args &&... args) {
        return func(*this, forward<Args>(args)...);
    }
};
template<class T>
Func(const T &) -> Func<T>;
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) { return pre(r)-pre(l-1); }
};
Vpii get_g() {
    int n;
    cin>>n;
    Graph g(n);
    REP(i,n-1 ) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    Vi dp(n),mxd(n),amx(n),umx(n);
    auto dfs=[&](auto dfs,int u,int fa) {
        int mx=0,mx2=0;
        for(int v:g[u]) {
            if(v==fa) continue;
            dfs(v,u);
            chmax(dp[u],dp[v]);
            chmax(mxd[u],mxd[v]+1);
            int v=mxd[v]+1;
            if(v>mx) mx2=mx,mx=v;
            else if(v>mx2) mx2=v;
        }
        chmax(dp[u],mx1+mx2);
    };
    dfs(0,-1);
    auto dfs2=[&](auto dfs2,int u,int fa) {
        amx[u]=max(mxd[u],umx[u]);
        for(int v:g[u]) {
            if(v==fa) continue;
            ch.pb(v);
        }
    }
}
signed main() {
    IOS();
    
    return 0;
}
