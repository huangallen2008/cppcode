#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
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
const int maxb=18;
const int lgv=30;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
namespace FFT {
    #define Cd complex<ld>
    #define VC vector<Cd>
    const ld PI=acosl(-1);
    int t,lt;
    VC a,b;
    Vi r;
    int n1,n2;
    void _fft(VC &a,int on=1) {
        REP(i,t) if(i<r[i]) swap(a[i],a[r[i]]);
        for(int m=2;m<=t;m<<=1) {
            Cd wn(cosl(2*PI/m),sinl(on*2*PI/m));
            for(int l=0;l<t;l+=m) {
                Cd w=1;
                for(int k=l;k<l+m;k++) {
                    Cd x=a[k],y=a[k+m/2]*w;
                    a[k]=x+y;
                    a[k+m/2]=x-y;
                    w*=wn;
                }
            }
        }
        if(on==-1) {
            REP(i,t) a[i]/=t;
        }
    }
    Vi fft(Vi _a,Vi _b) {
        n1=SZ(_a),n2=SZ(_b);
        a=VC(n1),b=VC(n2);
        REP(i,n1) a[i]=_a[i];
        REP(i,n2) b[i]=_b[i];
        lt=0,t=1;
        while(t<n1+n2) t<<=1,lt++;
        while(SZ(a)<t) a.pb(0);
        while(SZ(b)<t) b.pb(0);
        r=Vi(t);
        REP(i,t) r[i]=r[i>>1]<<1|(i&1)<<lt-1;
        _fft(a),_fft(b);
        VC __(5);
        // VC c(t);
        REP(i,t) a[i]=a[i]*b[i];
        ope(t)
        _fft(a,-1);
        Vi _c(t);
        REP(i,t) _c[i]=a[i].real();
        while(SZ(_c)&&_c.back()==0) _c.pop_back();
        return _c;
    }
};
signed main() {
    IOS();
    Vi a={1,2,1};
    Vi b={1,2,1};
    Vi c=FFT::fft(a,b);
    oparr(c)
    return 0;
}
