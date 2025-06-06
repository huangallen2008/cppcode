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
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define Vld vector<ld>
#define Mat vector<Vld>
Mat operator*(Mat a,Mat b) {
    int n=SZ(a),m=SZ(b),k=SZ(b[0]);
    Mat c(n,Vld(k));
    REP(i,n) REP(j,m) REP(l,k) c[i][l]+=a[i][j]*b[j][l];
    return c;
}
Mat pw(Mat x,int p) {
    int n=SZ(x);
    Mat r(n,Vld(n));
    REP(i,n) r[i][i]=1;
    while(p>0) {
        if(p&1) r=r*x;
        x=x*x;
        p>>=1;
    }
    return r;
}
signed main() {
    IOS();
    Mat r(64,Vld(64));
    REP(i,8) {
        REP(j,8) {
            ld pos=(ld)1/((i!=0&&i!=7)+(j!=0&&j!=7)+2);
            if(i!=0) r[i<<3|j][i-1<<3|j]=pos;
            if(i!=7) r[i<<3|j][i+1<<3|j]=pos;
            if(j!=0) r[i<<3|j][i<<3|j-1]=pos;
            if(j!=7) r[i<<3|j][i<<3|j+1]=pos;
        }
    }
    int k;
    cin>>k;
    Mat ra=pw(r,k);
    Vld an(64,1);
    REP(i,64) {
        Mat x(1,Vld(64));
        x[0][i]=1;
        Mat res=x*ra;
        REP(j,64) an[j]=an[j]*(1-res[0][j]);
    }
    ld ans=0;
    REP(i,64) ans+=an[i];
    cout<<fixed<<setprecision(6)<<ans<<'\n';
    return 0;
}
