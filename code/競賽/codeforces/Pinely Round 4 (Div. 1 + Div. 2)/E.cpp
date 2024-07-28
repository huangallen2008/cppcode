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
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii qu() {
    cout<<"1 2\n";cout.flush();
    int u,c;
    cin>>u>>c;
    return {u,c};
}
Graph g;
vector<int> col;
bool ok;
void dfs(int u) {
    for(int v:g[u]) {
        if(col[v]!=0) {
            if(col[v]!=3-col[u]) {
                ok=0;
                return;
            }
        }
        col[v]=3-col[u];
        dfs(v);
        if(!ok) return;
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    if(n==1) {
        cout<<"Bob\n";cout.flush();
        int c1,c2;
        cin>>c1>>c2;
        cout<<1<<' '<<c1<<'\n';
        cout.flush();
    }
    g=Graph(n+1);
    ok=1;
    vector<bool> vis(n+1);
    col=vector<int>(n+1);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    cout<<"Alice\n";cout.flush();
    pii ret=qu();
    col[ret.f]=ret.s;
    dfs(ret.f);
    vis[ret.f]=1;
    if(!ok) {
        REP1(i,n-1) qu();
        return;
    }
    REP1(i,n-2) {
        pii ret=qu();
        if(col[ret.f]!=ret.s) {
            REP(rd,n-i-1) qu();
            return;
        }
        vis[ret.f]=1;
    }
    REP1(i,n) {
        if(!vis[i]) {
            cout<<3-col[i]<<' '<<3<<'\n';
            cout.flush();
        }
    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) 
        solve();
    return 0;
}