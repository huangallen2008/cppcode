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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,q;
vector<int> c;
Graph g;
int dfs(int u,int e,int k,int d,int an,int p) {
    if(u==e) return an;
    for(auto v:g[u]) {
        if(v==p) continue;
        if(c[v]==k&&an==-1) {
            int ret=dfs(v,e,k,d+1,d+1,u);
            if(ret!=-1) return ret;
        }
        else {
            int ret=dfs(v,e,k,d+1,an,u);
            if(ret!=-1) return ret;
        }
    }
    return -1;
}
signed main() {
    IOS();
    cin>>n>>q;
    g=Graph(n);
    c=vector<int>(n);
    REP(i,n) cin>>c[i];
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    while(q--) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int u,v,k;
            cin>>u>>v>>k,u--,v--;
            int an;
            if(c[u]==k) an=0;
            else an=dfs(u,v,k,0,-1,-1);
            cout<<an<<'\n';
        }
        else {
            int u,k;
            cin>>u>>k,u--;
            c[u]=k;
        }
    }
    return 0;
}