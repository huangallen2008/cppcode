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
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<Vi> a(n+2,Vi(n+2));
    vector<Vi> p(n+2,Vi(n+2));
    REP1(i,n) REP1(j,m) {
        char ch;
        cin>>ch;
        a[i][j]=ch=='0';
    }
    REP1(i,n+1) REP1(j,m+1) p[i][j]=p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
    auto cnt=[&](int r1,int r2,int c1,int c2) {
        return p[r2][c2]-p[r2][c1-1]-p[r1-1][c2]+p[r1-1][c1-1];
    };
    k+=2;
    int sum=p[n][m];
    REP1(cr,k-1) {
        int cc=k-cr;
        if(sum%(cc*cr)) continue;
        int pc=sum/cc/cr;
        op(cr)ope(cc)
        REP1(r1,n+1) {
            bool ok=1;
            Vi r(cr+1),c(cc+1);
            int itr=0,now=0;
            int itc=0;
            REP1(j,m+1) {
                if(now==pc) {
                    now=0;
                    c[itc++]=j;
                }else if(now>pc) {
                    ok=0;
                    break;
                }
                now+=cnt(1,r1-1,j,j);
            }
            if(!ok) continue;
            now=0;
            REP1(j,n) {
                if(now==pc) {
                    now=0;
                    r[itr++]=j;
                }else if(now>pc) {
                    ok=0;
                    break;
                }
                now+=cnt(j,j,1,r[0]-1);
            }
            if(!ok) continue;
            oparr(r)oparr(c)entr
        }
    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}