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
pdd operator-(pdd a,pdd b) { return {a.f-b.f,a.s-b.s}; }
pdd operator+(pdd a,pdd b) { return {b.f+a.f,b.s+a.s}; }
pdd operator*(pdd a,ld b) { return {b*a.f,b*a.s}; }
pdd operator/(pdd a,ld b) { return {(ld)a.f/b,(ld)a.s/b}; }
pdd to(pdd a,pdd b) { return {b.f-a.f,b.s-a.s}; }
ld cros(pdd a,pdd b) { return a.f*b.s-a.s*b.f; }
ld dot(pdd a,pdd b) { return a.f*b.f+a.s*b.s; }
int sign(ld x) { if(x>0) return 1;else if(x<0) return -1;else return 0; }
bool kill1(pdd a,pdd b,pdd c) {//1:can kill
    return cros(to(a,b),to(a,c))<0;
}
bool kill2(pdd a,pdd b,pdd c) {//1:can kill
    return cros(to(a,b),to(a,c))>0;
}
const ld PI=acosl(-1);
#define Vpdd vector<pdd>
ld convex_area(Vpdd p) {
    int n=SZ(p);
    sort(ALL(p));
    // oparr(p)
    vector<pdd> convex={p[0]};
    REP1(i,n-1) {
        while(convex.size()>=2&&kill1(convex[SZ(convex)-2],convex[SZ(convex)-1],p[i])) convex.pop_back();
        convex.pb(p[i]);
    }
    RREP(i,n-1) {
        while(convex.size()>=2&&kill1(convex[SZ(convex)-2],convex[SZ(convex)-1],p[i])) convex.pop_back();
        convex.pb(p[i]);
    }
    convex.pop_back();
    // ope("ok")
    // oparr(convex)
    ld A=cros(convex.back(),convex[0]);
    REP(i,SZ(convex)-1) A+=cros(convex[i],convex[i+1]);
    return A/2;
}
void solve() {
    int n;
    cin>>n;
    ld A0=0;
    vector<pdd> p;
    REP(i,n) {
        ld x,y,w,h,v;
        cin>>x>>y>>w>>h>>v;
        pdd po={x,y};
        A0+=w*h;
        pdd v1=pdd{w*cosl((-v)*PI/180)/2,w*sinl(-v*PI/180)/2};
        pdd v2=pdd{h*cosl((90-v)*PI/180)/2,h*sinl((90-v)*PI/180)/2};
        p.pb(po+v1+v2);
        p.pb(po+v1-v2);
        p.pb(po-v1+v2);
        p.pb(po-v1-v2);
    }
    // oparr(p)
    ld A=convex_area(p);
    // op(A0)ope(A)
    ld ans=(A0)*100/A;
    cout<<fixed<<setprecision(1)<<ans<<" %\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
