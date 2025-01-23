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
const int maxv=2e6+5;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v,w;
};
struct DSU {
    int n;
    Vi p,sz,w;
    void init(int _n) {
        n=_n;
        p=w=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:find(p[u]);
    }
    bool merge(int a,int b,int ww) {
        op(a)ope(b)
        int x=find(a),y=find(b);
        if(x==y) return 0;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        w[x]=w;
        sz[y]+=sz[x];
        return 1;
    }
    int val(int a,int b) {
        while(a!=b) {
            if(sz[a]>sz[b]) swap(a,b);
            a=p[a];
        }
        return sz[a];
    }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<edge> e(m);
    Graphw g(n);
    DSU dsu;
    dsu.init(n);
    REP(i,m) cin>>e[i].u>>e[i].v>>e[i].w,e[i].u--,e[i].v--;
    sort(ALL(e),[&](edge a,edge b) { return a.w<b.w; });
    for(auto ee:e) {
        if(dsu.merge(ee.u,ee.v,ee.w)) {
            g[ee.u].pb({ee.v,ee.w});
            g[ee.v].pb({ee.u,ee.w});
        }
    } 
    entr REP(i,n) {
        for(auto [v,w]:g[i]) cout<<i<<' '<<v<<' '<<w<<'\n';
    }entr
    oparr(dsu.p)oparr(dsu.sz)
    entr REP(i,n) cout<<i<<' '<<dsu.p[i]<<'\n';
    entr
    int q;
    cin>>q;
    REP(i,q) {
        int s,t;
        cin>>s>>t,s--,t--;
        int ret=dsu.val(s,t);
        cout<<ret<<'\n';
    }
    return 0;
}