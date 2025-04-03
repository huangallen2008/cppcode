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
const int mod=998244353;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    cout<<fixed<<setprecision(9);
    int n,x;
    cin>>n>>x;
    Vi a(n);
    vector<ppi> t(n);
    Vpii b(n);
    REP(i,n) cin>>b[i].f>>b[i].s,t[i]={b[i],i};
    sort(ALL(t));
    REP(i,n) a[i]=t[i].s;
    auto inter=[&](int x,int y) ->ld {
        auto [x1,y1]=b[x];
        auto [x2,y2]=b[y];
        if(x1==x2) return y1<y2?inf:-inf;
        return (ld)(x2*x2+y2*y2-x1*x1-y1*y1)/(x2*2-x1*2);
    };
    oparr(a)
    vector<pair<int,ld>> stk;
    REP(i,n) {
        while(stk.size()&&inter(stk.back().f,a[i])<=stk.back().s) stk.pop_back();
        ld xx;
        if(SZ(stk)==0||(xx=inter(stk.back().s,a[i]))<x) stk.pb({a[i],xx});
        // op(i)oparr(stk)
    }
    vector<ld> an(n);
    REP(i,SZ(stk)) {
        an[stk[i].s]=(i==SZ(stk)-1?x:stk[i+1].f)-stk[i].f;
    }
    // oparr(stk)
    REP(i,n) cout<<an[i]<<'\n';
    return 0;
}
