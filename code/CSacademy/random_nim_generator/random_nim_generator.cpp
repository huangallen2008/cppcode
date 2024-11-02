#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define ALL1(x) (x).begin()+1,(x).end()
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=30011;
const int maxn=2e4+5;
const int maxn2=2e5+5;
const int maxb=20;
const int inf=(1ll<<62); 
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
int inv(int x) { 
    return pw(x,mod-2);
}
Vi fac(maxn),infac(maxn);
int C(int n,int k) {
    return (fac[n]*infac[k]%mod)*infac[n-k]%mod;
}
bool isp(int n) {
    for(int i=2;i*i<=n;i++) if(n%i==0) return 0;return 1;
}
int dp(int n,int k) {
    op(n)ope(k)
    if(k<0) return 1;
    if(k==0) return 1;
    int r=0;
    int x=__lg(k+1),y=k-(1<<x);
    // op(x)ope(y)
    for(int i=0;i<=n;i+=2) {
        // op(pw(y+1,i))ope(C(n,i))
        addmod(r,(i==n?dp(i,y):pw(y+1,i)*pw(2,x*(n-i-1)))*C(n,i));ope(r)
    }
    return r;
}
signed main() {
    IOS();
    fac[0]=1;
    REP1(i,maxn-1) fac[i]=fac[i-1]*i%mod;
    infac[maxn-1]=inv(fac[maxn-1]);
    RREP(i,maxn-1) infac[i]=infac[i+1]*(i+1)%mod;
    int n,k;
    cin>>n>>k;
    int r=dp(n,k);
    // REP(i,n+1) cout<<fac[i]<<' ';entr
    // REP(i,n+1) cout<<(infac[i]*fac[i])%mod<<' ';entr
    // ope(r)ope(tt)
    ope(r)
    int an=pw(k+1,n)-r;
    an=(an+mod)%mod;
    cout<<an<<'\n';
    return 0;
}