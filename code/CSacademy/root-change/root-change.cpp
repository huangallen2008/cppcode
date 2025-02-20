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
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Graph g;
Vpii dp,udp,adp;
pii merge(pii a,pii b) {
    if(a.f!=b.f) return max(a,b);
    return {a.f,0};
}
pii upd(pii x) { return {x.f+1,x.s+1}; }
void dfs(int u,int fa) {
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        // pii ret=dp[v];
        // op(u)op(v)ope(ret)
        // ret.f++,ret.s++;
        dp[u]=merge(dp[u],upd(dp[v]));
    }
}
void dfs2(int u,int fa) {
    adp[u]=upd(udp[u]);
    int sz=0;
    Vi ch(1);
    for(int v:g[u]) {
        if(v==fa) continue;
        sz++;
        ch.pb(v);
        adp[u]=merge(adp[u],upd(dp[v]));
    }
    Vpii pre(sz+2),suf(sz+2);
    REP1(i,sz) pre[i]=merge(pre[i-1],upd(dp[ch[i]]));
    RREP1(i,sz) suf[i]=merge(suf[i+1],upd(dp[ch[i]]));
    REP1(i,sz) udp[ch[i]]=merge(upd(udp[u]),merge(pre[i-1],suf[i+1]));
    op(u)ope(sz)
    oparr(pre)oparr(suf)
    for(int v:g[u]) if(v!=fa) dfs2(v,u);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    dp=udp=adp=Vpii(n);
    udp[0]={-1,0};
    g=Graph(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    } 
    dfs(0,-1);
    dfs2(0,-1);
    oparr(udp)oparr(adp)
    REP(i,n) cout<<n-1-adp[i].s<<'\n';
    return 0;
}