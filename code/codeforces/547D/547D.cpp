#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
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
const int N=maxn<<1;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<pii> g[N];
vector<int> deg(N),cur(N),an(N);
bitset<N> e_vis;
int col=0;
void dfs(int u) {
    for(;cur[u]<g[u].size();cur[u]++) {
        auto [v,id]=g[u][cur[u]];
        if(e_vis[id]) continue;
        e_vis[id]=1;
        dfs(v);
        an[id]=col;
        col^=1;
    }
}
void addedge(int u,int v,int id) {
    g[u].pb({v,id});
    g[v].pb({u,id});
    deg[u]^=1;
    deg[v]^=1;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    e_vis.reset();
    int eid=0;
    REP(i,n) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        addedge(u,maxn+v,eid++);
    }
    eid++;
    int last=-1;
    vector<int> odds;
    REP(i,N) {
        if(deg[i]&1) {
            odds.pb(i);
            if(last!=-1) {
                addedge(last,i,eid++);
                last=-1;
            } 
            else last=i;
        }
    }
    for(int x:odds) dfs(x);
    REP(i,N) dfs(i);
    REP(i,n) cout<<(an[i]?'r':'b');
    cout<<'\n';
    return 0;
}