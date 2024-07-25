#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
vector<int> col,las;
int n,m,s;
void op_path(int u) {
    vector<int> p;
    while(u!=s) p.pb(u),u=las[u];
    p.pb(s);
    reverse(ALL(p));
    cout<<p.size()<<'\n';
    for(int x:p) cout<<x<<' ';
    cout<<'\n';
}
void dfs(int u) {
    for(int v:g[u]) {
        if(v==s) continue;
        if(col[v]) {
            if(col[v]==col[u]) continue;
            cout<<"Possible\n";
            op_path(v);las[v]=u;
            op_path(v);
            exit(0);
        }
        col[v]=col[u];
        las[v]=u;
        dfs(v);
    }
}
signed main() {
    IOS();
    cin>>n>>m>>s;
    g=Graph(n+1);
    col=vector<int>(n+1);
    las=vector<int>(n+1);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
    }
    for(int v:g[s]) {
        if(col[v]) {
            cout<<"Possible\n";
            op_path(v);las[v]=s;
            op_path(v);
            exit(0);
        }
        col[v]=v;
        las[v]=s;
        dfs(v);
    }
    cout<<"Impossible\n";
    return 0;
}
