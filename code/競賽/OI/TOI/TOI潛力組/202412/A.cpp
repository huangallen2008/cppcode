#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int p;
    cin>>p;
    int n=0,m=0;
    while(p%2==0) n++,p/=2;
    while(p%3==0) m++,p/=3;
    int cnt5=0,cnt7=0;
    while(p%5==0) cnt5++,p/=5;
    while(p%7==0) cnt7++,p/=7;
    if(p>1) {
        cout<<"-1\n";
        return 0;
    }
    vector<Vi> dp(n+1,Vi(m+1,inf)),la(n+1,Vi(m+1,-1));
    vector<Vpii> ll(n+1,Vpii(m+1));
    dp[0][0]=0;
    REP(i,n+1) {
        REP(j,m+1) {
            if(!i&&!j) continue;
            if(i>=1) {
                int val=dp[i-1][j]+1;
                if(val>dp[i][j]) {
                    dp[i][j]=val;
                    la[i][j]=2;
                    ll[i][j]={i-1,j};
                }
            }if(j>=1) {
                int val=dp[i][j-1]+1;
                if(val>dp[i][j]) {
                    dp[i][j]=val;
                    la[i][j]=3;
                    ll[i][j]={i,j-1};
                }
            }if(i>=2) {
                int val=dp[i-2][j]+1;
                if(val>dp[i][j]) {
                    dp[i][j]=val;
                    la[i][j]=4;
                    ll[i][j]={i-2,j};
                }
            }if(i>=1&&j>=1) {
                int val=dp[i-1][j-1]+1;
                if(val>dp[i][j]) {
                    dp[i][j]=val;
                    la[i][j]=6;
                    ll[i][j]={i-1,j-1};
                }
            }if(i>=3) {
                int val=dp[i-3][j]+1;
                if(val>dp[i][j]) {
                    dp[i][j]=val;
                    la[i][j]=8;
                    ll[i][j]={i-3,j};
                }
            }if(j>=2) {
                int val=dp[i][j-2]+1;
                if(val>dp[i][j]) {
                    dp[i][j]=val;
                    la[i][j]=9;
                    ll[i][j]={i,j-2};
                }
            }
        }
    }
    int nn=n,nm=m;
    while(nn||nm) {
        auto [x,y]=ll[nn][nm];
        cout<<la[nn][nm]<<' ';
        nn=x,nm=y;
    }
    REP(i,cnt5) cout<<5<<' ';
    REP(i,cnt7) cout<<7<<' ';
    cout<<'\n';
    return 0;
}