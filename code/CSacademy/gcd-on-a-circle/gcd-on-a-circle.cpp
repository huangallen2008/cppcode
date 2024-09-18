#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxn=1e5+1;
const int maxb=17;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Vi a;
int n;
struct ST {
    int s[maxb][maxn];
    int n;
    void init(int _n) {
        n=_n+1;
        REP(i,n) s[0][i]=a[i];
        REP1(i,maxb-1) {
            REP(j,n) {
                s[i][j]=__gcd(s[i-1][j],s[i-1][min(n-1,j+(1<<i-1))]);
            }
        }
    }
    int qu(int k) {
        int v=a[k];
        for(int i=__lg(k);i>=0;i--) {
            if(k<(1<<i)) continue;
            int nv=__gcd(v,s[i][k-(1<<i)+1]);
            if(nv>1) {
                v=nv;
                k-=1<<i;
            }
        }
        return k;
    }
};
int la0=-1;
Vi dp,p;
int solve() {
    oparr(a)
    if(a[1]==la0) return dp[a.size()-1];
    int n=a.size();
    dp=p=Vi(n);
    ope("ok")
    ST st;
    st.init(n-1);
    dp[0]=p[0]=1;
    REP1(i,n-1) {
        int r=st.qu(i);
        if(r==0) dp[i]=p[i-1];
        else dp[i]=(p[i-1]-p[r-1])%mod;
        p[i]=(p[i-1]+dp[i])%mod;
    }
    la0=a[1];
    return dp[n-1];
}
signed main() {
    IOS(); 
    int n;
    cin>>n;
    a=Vi(n+1);a[0]=1;
    REP1(i,n) cin>>a[i];
    int an=solve();
    op(a[1])ope(a.back())
    while(__gcd(a[1],a.back())>1) {
        a[1]=__gcd(a[1],a.back()),a.pop_back();
        an=(an+solve())%mod;
    }
    cout<<an<<'\n';
    return 0;
} 