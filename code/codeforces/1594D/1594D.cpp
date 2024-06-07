#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
Graphw g;
vector<int> col;
void addedge(int u,int v,int w) {
    g[u].pb({v,w});
    g[v].pb({u,w});
}
pii dfs(int u) {
    int sz=1,an=col[u];
    for(auto [v,w]:g[u]) {
        if(col[v]!=-1) {
            if(col[v]!=col[u]^w) {
                return {-1,-1};
            }
            else continue;
        }
        col[v]=col[u]^w;
        auto ret=dfs(v);
        if(ret.f==-1) return {-1,-1};
        sz+=ret.f;
        an+=ret.s;
    }
    return {sz,an};
}
void solve() {
    int n,m;
    cin>>n>>m;
    g=Graphw(n);
    col=vector<int>(n+1,-1);
    REP(i,m) {
        int u,v;
        string s;
        cin>>u>>v>>s;
        u--,v--;
        if(s[0]=='c') addedge(u,v,0);
        else addedge(u,v,1);
    }
    int an=0;
    REP(i,n) {
        if(col[i]==-1) {
            col[i]=0;
            auto [sz,mx]=dfs(i);
            if(sz<0) {
                cout<<"-1\n";
                return ;
            }
            an+=max(mx,sz-mx);
        }
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
