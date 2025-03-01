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
const int maxn=5;
const int maxb=64;
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
template<class T> Func(const T &) -> Func<T>;
Vpii dir={{0,1},{0,-1},{1,0},{-1,0}};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    // auto ing=[&](int x,int y) {
    //     return !(x<0||x>=n||y<0||y>=m);
    // };
    int N=(n+1)*(m+1);
    auto id=[&](int a,int b) { return a*(m+1)+b; };
    vector<char> a0(N);
    REP1(i,n) REP1(j,m) cin>>a0[id(i,j)];
    Vi iw(N),to(N);
    REP1(i,n) REP1(j,m) iw[id(i,j)]=a0[id(i,j)]!='.'&&a0[id(i,j)]!='#';
    REP1(i,n) REP1(j,m) if(iw[id(i,j)]) {
        if(a0[id(i,j)]=='^') to[id(i,j)]=iw[id(i-1,j)]?id(i-1,j):id(i,j);
        if(a0[id(i,j)]=='>') to[id(i,j)]=iw[id(i,j+1)]?id(i,j+1):id(i,j);
        if(a0[id(i,j)]=='<') to[id(i,j)]=iw[id(i,j-1)]?id(i,j-1):id(i,j);
        if(a0[id(i,j)]=='v') to[id(i,j)]=iw[id(i+1,j)]?id(i+1,j):id(i,j);
    } 
    vector<Vi> cid(N);
    int coinid=0;
    REP1(i,n) REP1(j,m) if(a0[id(i,j)]=='#') {
        for(auto [dx,dy]:dir) {
            int nx=i+dx,ny=j+dy;
            cid[id(nx,ny)].pb(coinid);
        }
        coinid++;
    }
    Vi inc(N,1),ind(N);
    Vi wid;
    REP1(i,n) REP1(j,m) if(iw[id(i,j)]) wid.pb(id(i,j));
    for(int x:wid) ind[to[x]]++;
    queue<int> q;
    for(int x:wid) if(ind[x]==0) q.push(x);
    while(q.size()) {
        int u=q.front();
        q.pop();
        inc[u]=0;
        if(--ind[to[u]]==0) q.push(to[u]);
    }
    Graph g(N);
    for(int x:wid) g[to[x]].pb(x);
    Vi vis(N);
    Vi c(N);
    Vi an(N);
    int cnt=0;
    auto add=[&](int x) { cnt+=c[x]++==0; };
    auto addv=[&](Vi v) { for(int x:v) add(x); };
    auto del=[&](int x) { cnt-=--c[x]==0; };
    auto delv=[&](Vi v) { for(int x:v) del(x); };
    for(int x:wid) {
        if(vis[x]) continue;
        if(!inc[x]) continue;
        Vi nid;
        nid.pb(x);
        addv(cid[x]);
        int t=to[x];
        while(t!=x) {
            addv(cid[t]);
            nid.pb(t);
        }
        for(int u:nid) an[u]=cnt;
        Func dfs=[&](auto dfs,int u) {
            if(!inc[u]) an[u]=cnt;
            for(int v:g[u]) {
                if(inc[v]) continue;
                addv(cid[v]);
                dfs(v);
                delv(cid[v]);
            }
        };
        for(int u:nid) dfs(u);
        for(int u:nid) delv(cid[u]);
    }
    return 0;
}