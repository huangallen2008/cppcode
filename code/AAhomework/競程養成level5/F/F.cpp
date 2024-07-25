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
const int maxn=300+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    vector<int> s;
    void init(int n) {
        s=vector<int>(n<<2,-inf);
    }
    void ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w]=v;
            return;
        }
        int m=l+r>>1;
        if(u<=m) ud(w<<1,l,m,u,v);
        else ud(w<<1|1,m+1,r,u,v);
        s[w]=max(s[w<<1],s[w<<1|1]);
    }
    int qu(int w,int l,int r,int v) {
        if(l==r) return s[w];
        int m=l+r>>1;
        if(s[w<<1|1]>v) return qu(w<<1|1,m+1,r,v);
        else return qu(w<<1,l,m,v);
    }
}seg;
Graph g;
int n;
vector<int> stk,v,p,l;
void dfs(int u) {
    l[u]=seg.qu(1,0,n-1,v[u]);
    seg.ud(1,0,n-1,stk.size(),v[u]);
    stk.pb(v[u]);
    for(int v:g[u]) dfs(v);
    stk.pop_back();
    seg.ud(1,0,n-1,stk.size(),-inf);
}
void solve() {
    cin>>n;
    p=vector<int>(n);
    v=vector<int>(n);
    l=vector<int>(n);
    seg.init(n);
    g=Graph(n);
    REP1(i,n-1) cin>>p[i];
    REP(i,n) cin>>v[i];
    REP1(i,n-1) g[p[i]].pb(i);
    stk={n};
    seg.ud(1,0,n-1,0,n);
    dfs(0);
    int an=0;
    REP(i,n) addmod(an,l[i]*(i+1));
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}