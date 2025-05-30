#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=1e9+7;
const int maxn=755;
const int maxb=30;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// int dp[maxn][maxn][maxn];
int fac[maxn],infac[maxn];
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
signed main() {
    IOS(); 
    fac[0]=1,infac[0]=1;
    for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=1;i<maxn;i++) infac[i]=inv(fac[i]);
    int n;
    cin>>n;
    Vi a(n+1);
    REP1(i,n) cin>>a[i];
    sort(ALL1(a));
    a.pb(inf);
    Vi cnt(n+1);
    vector<Vi> dp(2,Vi(2));
    REP1(i,n) cnt[i]=a[i]==a[i-1]?cnt[i-1]+1:1;
    dp[0][0]=1;
    REP1(i,n-1) {
        vector<Vi> ndp(i+1,Vi(cnt[i]+1));
        if(a[i+1]==a[i]) {
            REP(j,i) {
                int R=min(cnt[i],j+1);
                REP(k,R) {//cnt[i]+cnt[i]-k
                    dp[j][k]%=mod;
                    (ndp[j+1][k+1]+=dp[j][k]*((cnt[i]<<1)-k));
                    if(j>0)(ndp[j-1][k]+=dp[j][k]*(j-k));
                    (ndp[j][k]+=dp[j][k]*(i+1-j+(k-cnt[i]<<1)));//i-vuuyugbyubgui
                }
            }
        }
        else {
            REP(j,i) {
                int R=min(cnt[i],j+1);
                REP(k,R) {//cnt[i]+cnt[i]-k
                    dp[j][k]%=mod;
                    // addmod(ndp[j+1][0],dp[j][k]*(cnt[i]*2-k));
                    if(j>0)(ndp[j-1][0]+=dp[j][k]*(j));
                    (ndp[j][0]+=dp[j][k]*(i+1-j));
                }
            }
        }
        swap(ndp,dp);
    }
    int an=dp[0][0]%mod;
    for(int i=1;i<=n;i++) if(a[i]!=a[i+1]) an=(an*infac[cnt[i]])%mod;
    cout<<an<<'\n';
    return 0;
}