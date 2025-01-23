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
const int maxv=2e6+5;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<Vi> a(n+1,Vi(m+1));
    REP1(i,n) REP1(j,m) cin>>a[i][j];
    vector<Vi> dr(n+1,Vi(m)),dc(n,Vi(m+1));
    REP1(i,n) REP1(j,m-1) dr[i][j]=dr[i-1][j]+dr[i][j-1]-dr[i-1][j-1]+abs(a[i][j]-a[i][j+1]);
    REP1(i,n-1) REP1(j,m) dc[i][j]=dc[i-1][j]+dc[i][j-1]-dc[i-1][j-1]+abs(a[i][j]-a[i+1][j]);
    auto sum2=[&](vector<Vi>&a,int r1,int r2,int c1,int c2) {
        r1--,c1--;
        return a[r2][c2]-a[r1][c2]-a[r2][c1]+a[r1][c1];
    };
    auto same=[&](int r1,int r2,int c1,int c2) {
        // op(r1)op(r2)op(c1)ope(c2)
        return sum2(dr,r1,r2,c1,c2-1)+sum2(dc,r1,r2-1,c1,c2)==0;
    };
    auto samev=[&](Vi v) ->bool{
        if(v.size()==0) return 1;
        for(int x:v) if(x!=v[0]) return 0;
        return 1;
    };
    auto ok=[&](int r1,int r2,int c1,int c2) {
        return same(r1+1,r2-1,c1+1,c2-1)&&same(r1+1,r2-1,c1,c1)&&same(r1+1,r2-1,c2,c2)&&same(r1,r1,c1+1,c2-1)&&same(r2,r2,c1+1,c2-1)&&samev(Vi{a[r1][c1],a[r1][c2],a[r2][c1],a[r2][c2]})&&samev({a[r1][c1+1],a[r1+1][c2],a[r2][c2-1],a[r2-1][c1]});
    };
    int an=0;
    REP1(i,n) {
        REP1(j,m) {
            if(i<=2||j<=2) continue;
            int l=3,r=min(i,j)+1,mid;
            while(l<r) {
                mid=l+r+1>>1;
                if(ok(i-mid+1,i,j-mid+1,j)) l=mid;
                else r=mid-1; 
            }
            // op(i)op(j)ope(l)
            an+=l-3;
            // for(int k=3;k<=i&&k<=j;k++) if(ok(i-k+1,i,j-k+1,j)) an++;
        }
    }
    cout<<an<<'\n';
    return 0;
}