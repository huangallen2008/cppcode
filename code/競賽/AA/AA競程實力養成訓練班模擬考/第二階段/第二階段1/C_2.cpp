#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,sse4,bmi2,popcnt")
// #define int long long
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
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=17;
const int inf=(1ll<<29);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g,g2;
int n,a,b;
vector<int> c,l;
// vector<bool> vis;
bitset<maxn> vis;
const int k=1;
int cnt;
void dfs(int u) {
    vis[u]=1;
    int mnl=inf;
    for(int &v:g[u]) {
        if(vis[v]) continue;
        dfs(v);
        chmin(c[u],c[v]+1);
        chmin(mnl,l[v]+1);
        chmax(l[u],l[v]+1);
    }
    // op("i")op(u)op(mnl)ope(l[u])
    if(-mnl-1>=l[u]) {
        l[u]=mnl;
    }
    if(l[u]==k) {
        c[u]=0;
        l[u]=-k-1;
        cnt++;
        // op('o')ope(u)
    }
    // op(u)op(c[u])ope(l[u])
}
void solve() {
    cin>>n>>a>>b;
    assert(n<=20);
    g=Graph(n);
    g2=Graph(n);
    REP1(i,n-1) {
        int p;
        cin>>p;
        g[p].pb(i);
        g2[p].pb(i);
        g2[i].pb(p);
        // op(p)ope(i)
    }
    int an=inf;
    REP(co,1<<n) {
        cnt=0;
        c=vector<int>(n,inf);
        l=vector<int>(n);
        vis.reset();
        // vector<bool> ch(n),ch2(n);
        bitset<maxn> ch,ch2; 
        REP(i,n) if((co>>i)&1) ch[i]=1;
        // REP(i,n) cout<<ch[i];entr
        REP(i,n) {
            if(ch[i]) ch2[i]=1;
            for( int &v:g2[i]) {
                if(ch[v]) ch2[i]=1;
            }
        }
        // REP(i,n) cout<<ch2[i];entr
        REP(i,n) {
            if(ch2[i]) vis[i]=1;
            for(int &v:g2[i]) {
                if(ch2[v]) vis[i]=1;
            }
        }
        // REP(i,n) cout<<vis[i];entr
        REP(i,n){
            if(vis[i]) continue;
            dfs(i);
            if(l[i]>=0) cnt++;
            // op(i)REP(j,n) cout<<vis[i];entr
        }
        int cnt1=__builtin_popcount(co);
        int ret=cnt*a+cnt1*b;
        // op(cnt)op(cnt1)ope(ret)
        chmin(an,ret);
    }
    assert(an!=inf);
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}