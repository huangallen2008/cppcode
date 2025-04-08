#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
#define int long long
#define iint signed
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
const int maxn=2e5+5;
const int maxb=18;
const int lgv=30;
const signed inf=1<<30;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,q;
Vi a;
int st[lgv][maxb][maxn];
vector<Vi> sum;
void st_init() {
    sum=vector<Vi>(lgv,Vi(n));
    REP(i,lgv) REP(j,n) st[i][0][j]=inf;
    REP(i,n) {
        int lg=__lg(a[i]);
        st[lg][0][i]=a[i];
        sum[lg][i]+=a[i];
    }
    REP(i,lgv) REP1(j,n-1) sum[i][j]+=sum[i][j-1];
    REP(i,lgv) {
        REP1(j,maxb-1) {
            REP(k,n) {
                st[i][j][k]=min(st[i][j-1][k],st[i][j-1][min(n-1,k+(1<<j-1))]);
            }
        } 
    }
}
int st_qu(int b,int l,int r) {
    int lg=__lg(r-l+1);
    return min(st[b][lg][l],st[b][lg][r-(1<<lg)+1]);
}
int qur(int l,int r) {
    int now=1;
    REP(i,lgv) {
        if(now>=st_qu(i,l,r)) now+=sum[i][r]-(l?sum[i][l-1]:0);
        // op(l)op(r)op(i)ope(now)
    }
    return now;
}
signed main() {
    IOS();
    cin>>n>>q;
    a=Vi(n);
    REP(i,n) cin>>a[i];
    st_init();
    REP(i,q) {
        int l,r;
        cin>>l>>r,l--,r--;
        cout<<qur(l,r)<<'\n';
    }
    return 0;
}
