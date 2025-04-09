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
const int mod=1e9+7;
const int maxn=500+5;
const int maxb=18;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
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
Vi fac(maxn),infac(maxn);
void com_init() {
    fac[0]=1;
    REP1(i,maxn-1) fac[i]=fac[i-1]*i%mod;
    infac[maxn-1]=inv(fac[maxn-1]);
    RREP(i,maxn-1) infac[i]=infac[i+1]*(i+1)%mod;
}
int C(int n,int k) {
    return (fac[n]*infac[k]%mod)*infac[n-k]%mod;
}
signed main() {
    IOS();
    com_init();
    int n,k;
    cin>>n>>k;
    int n2=n>>1;
    vector<Vi> dp1(n2+1,Vi(k+1)),dp2(n2+1,Vi(k+1));
    dp1[0][0]=dp2[0][0]=1;
    REP1(i,n2) {
        REP(j,min(i*2,k+1)) {
            addmod(dp1[i][j],dp1[i-1][j]);
            if(j) addmod(dp1[i][j],dp1[i-1][j-1]*(i*2-1-j+1));
            if(j>1) addmod(dp1[i][j],dp1[i-1][j-2]*(i*2-1-j+2)*(i*2-1-j+1));
        }
    }
    REP1(i,n2) {
        REP(j,min(i*2+1,k+1)) {
            addmod(dp2[i][j],dp2[i-1][j]);
            if(j) addmod(dp2[i][j],dp2[i-1][j-1]*(i*2-j+1));
            if(j>1) addmod(dp2[i][j],dp2[i-1][j-2]*(i*2-j+2)*(i*2-j+1));
        }
    }
    int an=0;
    Vi an1,an2;
    if(n&1) {
        an1=Vi(k+1);
        REP1(i,k) an1[i]=(dp1[n2][i]+dp1[n2][i-1]*(n-i+1));
        an2=dp2[n2];
    }else {
        an1=dp1[n2];
        an2=Vi(k+1);
        REP1(i,k) an2[i]=(dp2[n2][i]+dp2[n2][i-1]*(n-i+1));
    }
    REP(i,k+1) addmod(an,an1[i]*nan2[k-i]);
    cout<<an<<'\n';
    return 0;
}
