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
const int mod=998244353;
const int maxn=5;
const int inf=(1ll<<50);
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
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    vector<pii> f;
    for(int i=2;i*i<=m;i++) {
        if(m%i==0) {
            int cnt=0;
            while(m%i==0) {
                m/=i;
                cnt++;
            }
            f.pb({i,cnt});
        }
    }
    if(m>1) f.pb({m,1});
    Vi a(n);
    REP(i,n) cin>>a[i];
    int fc=f.size();
    Vi cnt(1<<fc),v(1<<fc);
    REP(i,n) {
        int fo=0;
        int t=a[i];
        bool ok=1;
        REP(j,fc) {
            auto [fa,c]=f[j];
            int cnt=0;
            while(t%fa==0) {
                t/=fa;
                cnt++;
            }
            if(cnt>c) {
                ok=0;
                break;
            }
            if(cnt==c) {
                fo^=1<<j;
            }
        }
        if(t>1) ok=0;
        if(!ok) continue;
        cnt[fo]++;
    }
    REP(i,1<<fc) v[i]=pw(2,cnt[i])-1;
    Vi dp(1<<fc);
    dp[0]=v[0]+1;
    int all=(1<<fc)-1;
    for(int i=1;i<1<<fc;i++) {
        RREP(j,1<<fc) {
            dp[j|i]=(dp[j|i]+dp[j]*v[i])%mod;
        }
    }
    int an=(dp[all]+mod)%mod;
    cout<<an<<'\n';
    return 0;
}