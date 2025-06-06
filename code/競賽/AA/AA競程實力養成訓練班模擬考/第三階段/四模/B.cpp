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
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    void ud(int l,int r,int v) {
        ud(l,v);
        ud(r+1,-v);
    }
    int qu(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
}bit;
signed main() {
    IOS();
    int n,x,y;
    cin>>n>>x>>y;
    Vi a(n+1);
    REP1(i,n) cin>>a[i],a[i]--;
    vector<Vi> id(n,{{0}});
    REP1(i,n) id[a[i]].pb(i);
    int q;
    cin>>q;
    vector<Vpii> qu(n+1);
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        qu[r].pb({l,i});
    }
    bit.init(n+1);
    Vpii now(n,{1,0});
    Vi it(n);
    Vi an(q);
    REP1(i,n) {
        int v=a[i];
        bit.ud(now[v].f,now[v].s,-v-1);
        it[v]++;
        int nl=id[v][max(0ll,it[v]-y)]+1,nr=id[v][max(0ll,it[v]-x+1)];
        bit.ud(nl,nr,v+1);
        now[v]={nl,nr};
        for(auto [l,ii]:qu[i]) {
            an[ii]=bit.qu(l);
        }
    }
    REP(i,q) cout<<an[i]<<'\n';
    return 0;
}