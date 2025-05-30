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
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<Vi> a(n+1,Vi(m+1,-1)),ps(n+1,Vi(m+1));
    REP1(i,n) {
        REP1(j,m) {
            char c;
            cin>>c;
            a[i][j]=c=='X'?-1:c-'0';
            ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i][j];
        }
    }
    auto asum=[&](int x1,int x2,int y1,int y2) {
        return ps[x2][y2]-ps[x2][y1-1]-ps[x1-1][y2]+ps[x1-1][y1-1];
    };
    Vi mxx(m+1);
    int an=0;
    REP1(i,n) {
        REP1(j,m) if(a[i][j]==-1) mxx[j]=i;
        Vi pa(m+1);
        Vpii stk={{inf,0}};
        int now=0;
        REP1(j,m) {
            while(SZ(stk)&&stk.back().f<mxx[j]) {
                now-=asum(stk.back().f+1,i,stk[SZ(stk)-2].s+1,stk.back().s);
                stk.pop_back();
            }
            now+=asum(mxx[j]+1,i,stk.back().s+1,j);
            stk.pb({mxx[j],j});
            pa[j]=now;
        }
        stk={{inf,m+1}};
        now=0;
        Vi sa(m+1);
        RREP1(j,m) {
            while(SZ(stk)&&stk.back().f<mxx[j]) {
                now-=asum(stk.back().f+1,i,stk.back().s,stk[SZ(stk)-2].s-1);
                stk.pop_back();
            }
            now+=asum(mxx[j]+1,i,j,stk.back().s-1);
            stk.pb({mxx[j],j});
            sa[j]=now;
        }
        REP1(j,m) chmax(an,pa[j]+sa[j]-asum(mxx[j]+1,i,j,j));
    }
    cout<<an<<'\n';
    return 0;
}
