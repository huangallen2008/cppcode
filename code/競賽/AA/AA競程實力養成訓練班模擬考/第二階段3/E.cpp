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
const int mod=998244353;
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Vi fac(maxn),infac(maxn);
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
int C(int n,int k) {
    return (fac[n]*infac[k]%mod)*infac[n-k]%mod;
}
void solve() {
    int n;
    cin>>n;
    string r;
    cin>>r;
    int n2=n>>1;
    if(n&1) {
        int cnt=0,cv=0;
        for(char x:r) {
            if(x=='V') cv++;
            else cnt++;
            if(cv==n2+1) break;
        }
        int an=C(n2+cnt,cnt)*C(n2+n-cnt,n-cnt)%mod;
        cout<<an<<'\n';
    }
    else {
        int cnt=0;
        int cv=0;
        bool allen=0;
        int an=0;
        for(int x:r) {
            if(x=='V') cv++;
            else {
                cnt++;
                if(allen) {
                    an=(an+C(n2-1+cnt,cnt)*C(n2+n-cnt,n-cnt))%mod;
                    ope(an)
                }
            }
            if(cv==n2) allen=1,an=C(n2+cnt,cnt)*C(n2+n-cnt,n-cnt),ope(an);
            if(cv==n2+1) break;
        }
        cout<<an<<'\n';
    }
}
signed main() {
    IOS(); 
    fac[0]=infac[0]=1;
    REP1(i,maxn) fac[i]=fac[i-1]*i%mod;
    REP1(i,maxn) infac[i]=inv(fac[i]);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}