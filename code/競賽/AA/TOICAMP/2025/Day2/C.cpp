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
signed main() {
    IOS();
    int n;
    cin>>n;
    Vi a(n+1);
    REP1(i,n) cin>>a[i];
    struct Mex {
        Vi c;
        set<int> s;
        Mex(int n) {
            c=Vi(n+1);
            REP(i,n+1) s.insert(i);
        }
        void add(int x) {
            if(c[x]++==0) s.erase(x);
        }
        void del(int x) {
            if(--c[x]==0) s.insert(x);
        }
        int mex() { return *s.begin(); }
    };
    Mex all(n);
    REP1(i,n) all.add(a[i]);
    int mex=all.mex();
    Mex lb(n),rb(n);
    int itl=1,itr=1;
    Vi dp(n+1),pdp(n+1);
    dp[0]=pdp[0]=1;
    REP1(i,n) {
        lb.add(a[i]);
        rb.add(a[i]);
        while(itl<=i&&lb.mex()>mex) lb.del(a[itl++]);
        while(itr<=i&&rb.mex()>=mex) rb.del(a[itr++]);
        dp[i]=((itr-2>=0?pdp[itr-2]:0)-(itl-2>=0?pdp[itl-2]:0))%mod;
        pdp[i]=(pdp[i-1]+dp[i])%mod;
    }
    int an=dp[n];
    cout<<an<<'\n';
    return 0;
}