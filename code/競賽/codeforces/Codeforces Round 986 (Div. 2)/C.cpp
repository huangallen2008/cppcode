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
const int maxn=1e6+5;
const int maxc=26;
const int maxb=20;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n,m,v;
    cin>>n>>m>>v;
    Vi a(n+1),p(n+1);
    REP1(i,n) cin>>a[i],p[i]=p[i-1]+a[i];
    Vi dp(n+1),rdp(n+2);
    REP1(i,n) {
        int id=(upper_bound(ALL(p),p[i]-v)-p.begin())-1;
        if(id<0) continue;
        dp[i]=dp[id]+1;
    }
    RREP1(i,n) {
        int id=(lower_bound(ALL(p),p[i-1]+v)-p.begin())+1;
        if(id>n) continue;
        rdp[i]=rdp[id]+1;
    }
    Vi pdp(n+1);
    REP1(i,n) pdp[i]=pdp[i-1]+dp[i];
    oparr(dp)oparr(rdp)oparr(pdp)
    int an=0;
    REP1(i,n) {
        int rcnt=rdp[i+1];
        int lid=lower_bound(ALL(pdp),m-rcnt)-pdp.begin();
        chmax(an,p[i]-p[lid]);
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