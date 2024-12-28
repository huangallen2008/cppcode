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
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p){
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
Graph g;
Vi c1,cn1,mnd,dp,sz,cng,is1;
void dfs(int u,int fa) {
    int cis=0;
    for(int v:g[u]) {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        cng[u]+=cng[v];
        dp[u]+=dp[v];
        chmin(mnd[u],mnd[v]+1);
        c1[u]+=c1[v];
        cn1[u]+=cn1[v];
        cis+=is1[v];
    }

    bool isng=1;
    for(int v:g[u]) if(v!=fa) { 
        if(g[v].size()==1) {
            isng=0;
            break;
        }
    }
    // ope(cis)
    cng[u]+=isng*(g[u].size()-1);
    for(int v:g[u]) {
        if(v==fa) continue;
        dp[u]+=(sz[u]-cng[u]-sz[v]+cng[v]+(isng)-1)*cn1[v];
        op(u)op(v)op(dp[u])op(sz[u])op(sz[v])op(cng[u])op(cng[v])ope(isng)ope(is1[v])
        if(is1[v]) dp[u]+=cn1[v];
        if(mnd[u]!=1) dp[u]+=(sz[v]-cng[v]-(isng));
        // op(u)op(v)ope(dp[u])
    }
    if(g[u].size()==1) {
        mnd[u]=0;
        sz[u]=0;
    }else {
        if(mnd[u]==1) c1[u]++,is1[u]=1;
        else cn1[u]++;
    }
}
void solve() {
    int n;
    cin>>n;
    g=Graph(n);
    c1=cn1=dp=cng=is1=Vi(n);
    mnd=Vi(n,inf);
    sz=Vi(n,1);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n==2) {
        cout<<"0\n";
        return;
    }
    int le=0;
    REP(i,n) if(g[i].size()==1) le++;
    int an=le*(n-le);
    //choose !leaf as root
    REP(i,n) if(g[i].size()!=1) {
        dfs(i,-1);
        ope(i)oparr(dp)oparr(mnd)oparr(c1)oparr(cn1)oparr(cng)oparr(sz)
        cout<<dp[i]+an<<'\n';
        entr
        break;
    }

}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}