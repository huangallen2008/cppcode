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
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SCC {
    Graph g,gb;
    vector<bool> vis;
    vector<int> end_order,sccid;
    int n,scccnt=0;
    void init(int _n,Graph &_g) {
        g=_g;
        n=_n;
        gb=Graph(n);
        sccid=vector<int>(n);
        REP(i,n) for(int v:g[i]) gb[v].pb(i);
        vis=vector<bool>(n);
        REP(i,n) if(!vis[i]) dfs1(i);
        reverse(ALL(end_order));
        vis=vector<bool>(n);
        for(int i:end_order) {
            if(!vis[i]) {
                sccid[i]=scccnt++;
                dfs2(i);
            }
        }
    }
    void dfs1(int u) {
        vis[u]=1;
        for(int v:g[u]) {
            if(vis[v]) continue;
            dfs1(v);
        }
        end_order.pb(u);
    }
    void dfs2(int u) {
        vis[u]=1;
        for(int v:gb[u]) {
            if(vis[v]) continue;
            sccid[v]=sccid[u];
            dfs2(v);
        }
    }
};
struct TwoSAT {
    int n=0;
    bool ok=1;
    Graph g;
    vector<bool> an;
    void init(int _n,vector<pii> &cons) {
        n=_n;
        an=vector<bool>(n+1);
        g=Graph(n<<1);
        for(auto [x,y]:cons) {
            op(x)ope(y)
            g[id(x)].pb(id(y));
        }
        oparr(an)
        SCC scc;
        scc.init(n<<1,g);
        oparr(scc.sccid)
        REP1(i,n) {
            if(scc.sccid[id(i)]==scc.sccid[id(-i)]) {
                ok=0;
                break;
            }
            if(scc.sccid[id(i)]>scc.sccid[id(-i)]) {
                an[i]=1;
                op("ffffffffff")ope(i)
            }
        }
        oparr(an)
    }
    int id(int x) { return x+n-(x>0); }
};
void solve() {
    int n,m;
    cin>>n>>m;
    Vpii cons;
    TwoSAT ts;
    REP(i,m) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int u,x;
            cin>>u>>x;
            if(!x) u=-u;
            cons.pb({-u,u});
        }else {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            if(!x) u=-u;
            if(!y) v=-v;
            cons.pb({u,v});
        }
    }
    ts.init(n,cons);
    if(ts.ok) {
        cout<<"YES\n";
        REP1(i,n) cout<<ts.an[i]<<' ';
        cout<<'\n';
    }else cout<<"NO\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}