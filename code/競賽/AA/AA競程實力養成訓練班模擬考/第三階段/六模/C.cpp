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
    Vi a(n),cnt(n);
    REP(i,n) cin>>a[i];
    a[0]=1;
    Vi id(1);
    REP(i,n) if(a[i]==0) id.pb(i);
    // REP1(i,n-1) cnt[i]=cnt[i-1]+(a[i]==-1);
    // Vi mx(n);
    // mx[0]=1;
    // REP1(i,n-1) mx[i]=max(mx[i-1],a[i]);
    int nn=id.size();
    vector<Vi> dp(n,Vi(n+1));
    // ope("ok")
    dp[0][1]=1;
    REP1(i,n-1) {
        if(a[i]==0){
            REP1(j,n) addmod(dp[i][j],dp[i-1][j-1]+dp[i-1][j]*(j));
        }
        else if(a[i]==-1) {
            REP1(j,n) dp[i][j]=dp[i-1][j-1];
        }
        else {
            dp[i]=dp[i-1];
            REP(k,a[i]) addmod(dp[i][k+1],dp[i][k]),dp[i][k]=0;
        }
        // chmax(mx[id[i]],mx[id[i-1]]+cnt[id[i]]-cnt[id[i-1]]);
        // int x=mx[id[i]];
        // REP(j,x) addmod(dp[i-1][j+1],dp[i-1][j]),dp[i-1][j]=0;
        // Vi ss=dp[i-1];
        // RREP(i,n) {
        //     addmod(ss[i],ss[i+1]);
        // }
        // oparr(dp[1])
    }
    // oparr(mx)
    int an=0;
    REP1(i,n) addmod(an,dp[n-1][i]);
    an=(an+mod)%mod;
    cout<<an<<'\n';
    return 0;
}