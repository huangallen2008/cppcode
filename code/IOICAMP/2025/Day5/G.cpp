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
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n, m; cin >> n >> m;//m--;
    vector<vector<int> > a(n+1, vector<int> (m+2));
    for(int i = 1; i <= n; i++) {
        // int xxx;cin>>xxx;
        for(int j = 1; j <= m; j++){

            cin >> a[i][j], a[i][j] += a[i][j-1];
        }
    }
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int> > dp(n+1, vector<int>(m+1));
    // vector<vector<int> > xdp(n+1, vector<int>(m+1));
    vector<deque<pii>> dq(n+1);
    REP1(i,n) dq[i].pb({-a[i][1],0});
    // REP1(i,n) xdp[i][0]=0;
    Vi mdp(m+1);
    for(int j = 1; j <= m; j++) {
        for(int i= 1; i <= n; i++) {
            while(dq[i].size()&&dq[i].front().s<=j-b[i]-2) dq[i].pop_front();
            dp[i][j]=dq[i].front().f+a[i][j];
            chmax(mdp[j],dp[i][j]);
        }

        REP1(i,n) {
            //{mdp[j]-a[i][j+1]}
            while(dq[i].size()&&dq[i].back().f<=mdp[j]-a[i][j+1]) dq[i].pop_back();
            dq[i].pb({mdp[j]-a[i][j+1],j});
            // xdp[i][j]=max(xdp[i][j-1],mdp[j]-a[i][j+1]);
        }
        // REP1(i,n) cout<<dp[i][j]<<' ';entr
    }
    int an=0;
    REP1(i,n) chmax(an,dp[i][m]);
    cout<<an<<'\n';
    return 0;
}