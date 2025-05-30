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
const int mod=998244353;
const int maxn=3e3+5;
const int maxv=1000;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<Vi> a(n,Vi(m));
    REP(i,n) {
        REP(j,m) {
            char c;
            cin>>c;
            a[i][j]=c=='O';
        }
    }
    int N=n*m;
    int mn=inf;
    Vpii dir={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
    auto nok=[&](int x,int y) { return x<0||x>=n||y<0||y>=m; };
    int now=0;
    vector<Vi> t(n,Vi(m));
    int cnt=0;
    REP(i,n) REP(j,m) t[i][j]=a[i][j],cnt+=a[i][j]==0;
    if(cnt==0) mn=0;
    REP1(mask,(1<<N)-1) {
        int id=__lg(mask&-mask);
        now^=mask&-mask;
        int i=id/m,j=id%m;
        // op(i)ope(j)
        for(auto [dx,dy]:dir) {
            int nx=i+dx,ny=j+dy;
            if(nok(nx,ny)) continue;
            t[nx][ny]=t[nx][ny]^1;
            if(t[nx][ny]==0) cnt++;
            else cnt--;
        }
    //     REP(i,n) {
    //         REP(j,m) {
    //         cout<<(now>>(i*m+j)&1);
    //     }entr }entr
    //     REP(i,n) {
    //         REP(j,m) {
    //         cout<<t[i][j];
    //     }entr 
    // }ope(cnt)entr
        if(cnt==0) chmin(mn,(int)__builtin_popcount(now));
    }
    if(mn==inf) cout<<"-1\n";
    else cout<<mn<<'\n';
    return 0;
}
