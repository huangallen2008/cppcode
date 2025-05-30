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
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
#define pii pair<int,int>
#define pipii pair<int,pii>
#define ppi pair<pii,int>
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
const int maxn=2e5+5;
const int maxv=1300;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
const int mod=1e9+7;
template<class T>
struct Func {
    T func;
    Func(const T &func):func(func) {}
    template<class... Args>
    constexpr decltype(auto) operator()(Args &&... args) {
        return func(*this, forward<Args>(args)...);
    }
};
template<class T>
Func(const T &) -> Func<T>;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) { return pw(x,mod-2); }
const Vi S={487631};
const int TS=1;
vector<Vi> gethash(int n) {
    Graph g(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<Vi> ret(TS);
    auto gh=[&](int S) ->Vi {
        Vi dp(n,S),udp(n),adp(n);
        Func dfs0=[&](auto dfs0,int u,int fa)->void {
            for(int v:g[u]) {
                if(v==fa) continue;
                dfs0(v,u);
                (dp[u]*=S+dp[v])%=mod;
            }
        };
        dfs0(0,-1);
        Func dfs1=[&](auto dfs1,int u,int fa)->void {
            adp[u]=(S+udp[u])*dp[u]%mod;
            for(int v:g[u]) {
                if(v==fa) continue;
                udp[v]=adp[u]*inv(S+dp[v])%mod;
                dfs1(v,u);
            }
        };
        udp[0]=-S+1;
        dfs1(0,-1);
        // REP(i,n) udp[i]=(udp[i]+mod)%mod;
        // REP(i,n) adp[i]=(adp[i]+mod)%mod;
        REP(i,n) adp[i]=(adp[i]+mod)%mod;
        // oparr(dp)
        // oparr(udp)
        // oparr(adp)
        return adp;
    };
    REP(i,TS) ret[i]=gh(S[i]);
    return ret;
};
void solve() {
    int n;
    cin>>n;
    auto r1=gethash(n);
    auto r2=gethash(n);
    auto same=[&](Vi a,Vi b) { 
        map<int,int> mp1;
        for(auto x:a) mp1[x]++;
        for(auto x:b) if(--mp1[x]<0) return 0;
        return 1;
    };
    bool ok=1;
    REP(i,TS) ok&=same(r1[i],r2[i]);
    cout<<(ok?"YES":"NO")<<'\n';
}
signed main() {
    IOS();
    #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    #endif
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
