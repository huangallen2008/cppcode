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
const int mod=1e9+7;
const int maxn=2e6+5;
const int maxv=1300;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct Dinic {
    struct E {
        int u,v,cap,r;
    };
    vector<E> es;
    Graph g;
    int n;
    int s,t;
    Vi dis,it;
    void init(int _n) {
        n=_n;
        g=Graph(n);
    }
    void addedge(int u,int v,int c) {
        es.pb({u,v,c,c});
        es.pb({v,u,c,0});
        g[u].pb(SZ(es)-2);
        g[v].pb(SZ(es)-1);
    }
    bool bfs() {
        dis=Vi(n,inf);
        dis[s]=0;
        queue<int> q;
        q.push(s);
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            for(auto id:g[u]) {
                auto [_,v,cap,r]=es[id];
                if(r&&dis[v]>dis[u]+1) {
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return dis[t]!=inf;
    }
    int dfs(int u,int cap) {
        if(u==t||cap==0) return cap;
        for(int &i=it[u];i<SZ(g[u]);i++) {
            int id=g[u][i];
            auto [_,v,_c,r]=es[id];
            if(dis[v]!=dis[u]+1) continue;
            int ret=dfs(v,min(cap,r));
            if(ret>0) {
                es[id].r-=ret;
                es[id^1].r+=ret;
                return ret;
            }
        }
        return 0;
    }
    int mxf(int _s,int _t) {
        s=_s,t=_t;
        int an=0,mf;
        while(bfs()) {
            it=Vi(n);
            while((mf=dfs(s,inf))>0) {
                an+=mf;
            }
        }
        return an;
    }
};
signed main() {
    IOS();
    int n;
    cin>>n;
    Vi r(n),c(n);
    int rs=0,cs=0;
    REP(i,n) cin>>r[i],rs+=r[i];
    REP(i,n) cin>>c[i],cs+=c[i];
    if(rs!=cs) {
        cout<<"-1\n";
        return 0;
    }
    Dinic dinic;
    dinic.init(n*2+2);
    REP(i,n) REP(j,n) dinic.addedge(i,j+n,1);
    REP(i,n) dinic.addedge(n<<1,i,r[i]);
    REP(i,n) dinic.addedge(i+n,n<<1|1,c[i]);
    if(dinic.mxf(n<<1,n<<1|1)!=rs) {
        cout<<"-1\n";
        return 0;
    }
    REP(i,n) {
        REP(j,n) {
            cout<<(dinic.es[i*n+j<<1])
        }
    }
    return 0;
}
