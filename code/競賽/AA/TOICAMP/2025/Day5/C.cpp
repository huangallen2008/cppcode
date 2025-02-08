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
#ifdef LOCAL_
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
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n+1;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        op(u)ope(v)
        u++;
        for(;u<=n;u+=u&-u) (b[u]+=v)%=mod;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) (r+=b[u])%=mod;
        return r;
    }
    int qu(int l,int r) { l++,r++; return (pre(r)-pre(l-1))%mod; }
};
signed main() {
    IOS();
    #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    n++;
    Vpii a(n+1,{-1,-1});
    a[n]={n*2-1,n*2};
    REP1(i,n*2-2) {
        int x;
        cin>>x;
    // op(i)ope(x)ope(a[x])
        if(a[x].f==-1) a[x].f=i;
        else a[x].s=i;
    }
    BIT bit;
    bit.init(n*2+10);
    sort(1+ALL(a));
    bit.ud(0,1);
    vector<Vpii> o(n+2);
    Vi dp(n+1);
    dp[0]=1;
    ope("ok")
    REP1(i,n) {
        for(auto [x,y]:o[i]) bit.ud(x,y);
        dp[i]=bit.qu(0,a[i].s);
        if(i==n) break;
        bit.ud(a[i].s,dp[i]);
        int val=bit.qu(0,a[i].f);
        int id=lower_bound(1+ALL(a),pii{a[i].s,-inf})-a.begin();
        // ope(id)
        ope(i)ope(id)
        assert(id<=n);
        o[id].pb({a[i].f,val});
    }
    oparr(dp)
    int an=(dp[n]+mod-1)%mod;
    cout<<an<<'\n';
    return 0;
}