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
const int maxn=4e5+5;
const int maxb=19;
const int inf=1ll<<60;
const int sn=400;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,d;
Graph g;
Vi dep,in,dis;
Vi all,v1,v2;
int st[maxb][maxn];
void dfs(int u,int fa) {
    in[u]=SZ(dfn);
    dfn.pb(u);
    for(int v:g[u]) {
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        dfn.pb(u);
    }
}
void st_init() {
    int nn=SZ(dfn);
    REP(i,nn) st[0][i]=dep[dfn[i]];
    REP1(i,maxb-1) {
        REP(j,n) st[i][j]=min(st[i-1][j],st[i-1][min(nn-1,j+(1<<i-1))]);
    }
}
int st_qu(int l,int r) {
    int lg=__lg(r-l+1);
    return min(st[lg][l],st[lg][r-(1<<lg)+1]);
}
int lca_dep(int a,int b) { 
    if(in[a]>in[b]) swap(a,b);
    return st_qu(in[a],in[b]); 
}
int qu_dis(int a,int b) { return dep[a]+dep[b]-2*lca_dep(a,b); }
void bfs() {
    dis=Vi(n,inf);
    queue<int> q;
    for(int x:v1) {
        q.push(x);
        dis[x]=0;
    }
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        for(int v:g[u]) {
            if(dis[v]>dis[u]+1) {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
signed main() {
    IOS();
    cin>>n>>d;
    g=Graph(n);
    dep=in=Vi(n);
    dis=Vi(n,inf);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    st_init();
    Vi p(n);
    REP(i,n)p[i]=i;
    sort(ALL(p),[&](int a,int b) { return dep[a]>dep[b]; });
    auto gdis=[&](int x) {
        int mn=dis[x];
        for(int u:v2) chmin(mn,qu_dis(x,u));
        return mn;
    };
    REP(i,n) {
        int dd=gdis(p[i]);
        if(dd<d) continue;
        all.pb(p[i]);
        v2.pb(p[i]);
        if(SZ(v2)==sn) {
            for(int x:v2) v1.pb(x);
            v2.clear();
            bfs();
        }
    }
    cout<<SZ(all)<<'\n';
    for(int x:all) cout<<x<<' ';
    cout<<'\n';
    return 0;
}
