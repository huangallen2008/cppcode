#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
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
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=2e9+5;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    Vi dp1(n+1);
    dp1[0]=1;
    REP1(i,k) {
        Vi ndp(n+1);
        REP(j,n+1) {
            if(j) addmod(ndp[j],dp1[j-1]*(n-j+1));
            if(j<n) addmod(ndp[j],dp1[j+1]*(j+1));
        } 
        swap(dp1,ndp);
    }
    Vi dp2(m+1);
    dp2[0]=1;
    REP1(i,k) {
        Vi ndp(m+1);
        REP(j,m+1) {
            if(j) addmod(ndp[j],dp2[j-1]*(m-j+1));
            if(j<m) addmod(ndp[j],dp2[j+1]*(j+1));
        } 
        swap(dp2,ndp);
    }
    // oparr(dp1)oparr(dp2)
    int an=0;
    REP(c1,n+1) {
        if(c1*2==n) {
            if(c1*m!=s) continue;
            REP(c2,m+1) addmod(an,dp1[c1]*dp2[c2]);
            continue;
        }
        if((s-c1*m)%(n-c1*2)) continue;
        int c2=(s-c1*m)/(n-c1*2);
        if(c2<0||c2>m) continue;
        // op(c1)ope(c2)
        addmod(an,dp1[c1]*dp2[c2]);
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}