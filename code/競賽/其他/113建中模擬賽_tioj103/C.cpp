#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
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
const int mod=998244353;
const int maxn=4e5+5;
const int maxn2=6000+5;
const int maxb=20;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Graphw g;
Vi dep,dfn,id,c;
void dfs(int u,int fa) {
    id[u]=dfn.size();
    dfn.pb(u);
    for(auto [v,w]:g[u]) {
        if(v==fa) continue;
        dep[v]=dep[u]+w;
        dfs(v,u);
        dfn.pb(u);
    }
}
int st[maxb][maxn];
void st_init() {
    int nn=dfn.size();
    REP(i,nn) st[0][i]=dep[dfn[i]];
    REP1(i,maxb-1) {
        REP(j,nn) st[i][j]=min(st[i-1][j],st[i-1][min(nn-1,j+(1<<i-1))]);
    }
}
int st_qu(int l,int r)  {
    int lg=__lg(r-l+1);
    return min(st[lg][l],st[lg][r-(1<<lg)+1]);
}
int lca_dep(int a,int b) {
    if(id[a]>id[b]) swap(a,b);
    return st_qu(id[a],id[b]);
}
int dis(int a,int b) {
    return dep[a]+dep[b]-(lca_dep(a,b)<<1);
}
signed main() {
    IOS(); 
    cin>>n;
    g=Graphw(n);
    c=id=dep=Vi(n);
    REP(i,n) cin>>c[i],c[i]--;
    REP(i,n-1) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    dfs(0,-1);
    st_init();
    // oparr(dep)oparr(dfn)REP(i,n<<1) cout<<st[0][i]<<' ';entr
    // ope(dis(4,2))ope(lca_dep(4,2))oparr(id)
    vector<Vi> cn(n);
    REP(i,n) cn[c[i]].pb(i);
    vector<pii> rv(n);
    Vi an(n);
    REP(i,n) {
        if(!cn[i].size()) continue;
        int t0=cn[i][0];
        int nod=t0,ds=0;
        for(int v:cn[i]) {
            int dst=dis(t0,v);
            if(dst>ds) {
                ds=dst;
                nod=v;
            }
        }
        rv[i].f=nod;
        t0=nod;nod=t0,ds=0;
        for(int v:cn[i]) {
            int dst=dis(t0,v);
            if(dst>ds) {
                ds=dst;
                nod=v;
            }
        }
        rv[i].s=nod;
    }
    REP(i,n) {
        auto [v1,v2]=rv[c[i]];
        int d1=dis(v1,i),d2=dis(v2,i);
        cout<<max(d1,d2)<<'\n';
    }
    return 0;
}