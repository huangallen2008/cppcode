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
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct edge {
    int u,v,w;
};
void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    Graphw g(n);
    vector<edge> es;
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
        es.pb({u,v,w});
    }
    sort(ALL(es),[&](edge a,edge b) {
        return a.w<b.w;
    });
    vector<vector<Vi>> an(n,vector<Vi>(n,Vi(n,inf)));
    vector<Vi> dis(n,Vi(n,inf));
    REP(i,n) dis[i][i]=0;
    for(auto [u,v,w]:es) dis[u][v]=dis[v][u]=1;
    REP(k,n) REP(i,n) REP(j,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(auto [u,v,w]:es) {
        REP(i,n) REP(j,n) {
            dis[i][j]=min({dis[i][j],dis[i][u]+dis[v][j],dis[i][v]+dis[u][j]});
        }
        REP(i,n) REP(j,n) if(i!=j) chmin(an[i][j][dis[i][j]+1],w);
        // cout<<dis;
    }
    // REP(i,n) REP(j,n) {op(i)op(j)oparr(an[i][j])}
    REP(i,n) REP(j,n) REP1(k,n-1) chmin(an[i][j][k],an[i][j][k-1]);
    REP(i,q) {
        int u,v,k;
        cin>>u>>v>>k,u--,v--;
        cout<<an[u][v][min(k,n-1)]<<' ';
    }
    cout<<'\n';
    // entr
}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}

/*
1
4 4 2
1 2 2
2 4 2
1 3 4
3 4 1
1 4 2
2 3 1

1
6 7 3
1 2 10
2 3 3
3 4 9
4 5 2
5 6 1
2 4 10
4 6 10
1 6 3
1 6 2
2 4 1
*/