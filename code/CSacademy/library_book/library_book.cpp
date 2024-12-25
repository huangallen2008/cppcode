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
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
typename f() {
    
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Vpii a(n+1),b(m+1);
    REP1(i,n) cin>>a[i].f>>a[i].s;
    REP1(i,m) cin>>b[i].f>>b[i].s;
    sort(1+ALL(a));
    sort(1+ALL(b));
    vector<Vi> dp(n+1,Vi(m+1,inf));
    dp[0][0]=0;
    REP(i,n+1) {
        REP(j,m+1) {
            if(!i&&!j) continue;
            if(i) {
                op(i)op(j)op("1")ope(max(dp[i-1][j],a[i].f)+a[i].s);
                chmin(dp[i][j],max(dp[i-1][j],a[i].f)+a[i].s);
            }
            if(j) {
                op(i)op(j)op("2")ope(max(dp[i][j-1],b[j].f+b[j].s));
                chmin(dp[i][j],max(dp[i][j-1],b[j].f+b[j].s));
            }
        }
        op(i)oparr(dp[i])
    }
    cout<<dp[n][m]<<'\n';
    return 0;
}