#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxb=30;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
Vi c,dep;
int n;
vector<pii> stk(maxn);
Vi an;
int en=0;
void dfs(int u) {
    int tmp_en=en;
    for(int v:g[u]) {
        pii tmp;
        while(en>=2&&(c[v]-stk[en-1].f)*(dep[stk[en-1].s]-dep[stk[en-2].s])<=(stk[en-1].f-stk[en-2].f)*(dep[v]-dep[stk[en-1].s])) en--;
        an[v]=stk[en-1].s;
        tmp=stk[en];
        stk[en++]={c[v],v};
        dep[v]=dep[u]+1;
        dfs(v);
        stk[--en]=tmp;
    }
    en=tmp_en;
}
signed main() {
    IOS(); 
    cin>>n;
    g=Graph(n);
    c=an=dep=Vi(n);
    REP(i,n) cin>>c[i];
    REP1(i,n-1) {
        int u;
        cin>>u,u--;
        g[u].pb(i);
    }
    REP(i,n) {
        sort(ALL(g[i]),[&](int a,int b) {
            return c[a]>c[b];
        });
    }
    stk[en++]={c[0],0};
    dfs(0);
    oparr(dep)
    REP1(i,n-1) cout<<an[i]+1<<'\n';
    return 0;
}