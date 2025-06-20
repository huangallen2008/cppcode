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
const int maxn=1e6+5;
const int maxv=1000;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void go(int n,int m) {

    int N=n*m;
    Vi a(N);
    REP(i,N) a[i]=i;
    map<Vi,int> mp;
    do {
        Vi vis(N);
        int cnt=0;
        REP(i,N) if(a[i]!=i&&!vis[i]){
            int t=a[i];
            while(t!=i) {
                vis[t]=1;
                t=a[t];
                cnt++;
            }
        }
        Vi a0(N);
        REP(i,N) a0[i]=a[i]/m;
        if(!mp[a0]) mp[a0]=inf;
        chmin(mp[a0],cnt);
    }while(next_permutation(ALL(a)));
    {
        Vi _(N);
        REP(i,N) _[i]=i/m;
        mp[_]=0;
    }
    Vi an(N);
    for(auto [x,y]:mp) {
        // for(int t:x) cout<<t<<' ';cout<<": "<<y<<endl;
        an[y]++;
    }
    cout<<"n="<<n<<" m="<<m<<": "; REP(i,N-m+1) cout<<an[i]<<' ';cout<<endl;
}
int dp[100];
int F(int n) {
    if(n==1||n==2) return 1;
    if(dp[n]) return dp[n];
    return dp[n]=F(n-1)+F(n-2);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[1]=dp[2]=1;
    for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n]<<'\n';
    return 0;
}
