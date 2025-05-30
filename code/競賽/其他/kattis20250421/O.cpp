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
// #define pii pair<int,int>
#define pipii pair<int,pii>
#define ppi pair<pii,int>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define pii pair<ld,ld>
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
pii operator-(pii a,pii b) { return {a.f-b.f,a.s-b.s}; }
pii operator+(pii a,pii b) { return {b.f+a.f,b.s+a.s}; }
pii operator*(pii a,int b) { return {b*a.f,b*a.s}; }
pii operator*(int b,pii a) { return {b*a.f,b*a.s}; }
pdd operator/(pii a,int b) { return {(ld)a.f/b,(ld)a.s/b}; }
pii to(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
ld cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
ld dot(pii a,pii b) { return a.f*b.f+a.s*b.s; }
int sign(int x) { if(x>0) return 1;else if(x<0) return -1;else return 0; }
bool onl(pii l1,pii l2,pii p) { return l1==l2?l1==p:cros(to(l1,l2),to(l1,p))==0&&dot(to(l1,l2),to(l1,p))>=0&&dot(to(l2,l1),to(l2,p))>=0;}
bool dif_side(pii a,pii b,pii c,pii d) {return sign(cros(to(a,b),to(a,c)))*sign(cros(to(a,b),to(a,d)))<0;}
bool inters(pii a,pii b,pii c,pii d) { return onl(a,b,c)||onl(a,b,d)||onl(c,d,a)||onl(c,d,b)||(dif_side(a,b,c,d)&&dif_side(c,d,a,b)); }
pdd inters_p(pii a,pii b,pii c,pii d) { 
    ld x=abs(cros(b-a,c-a)),y=abs(cros(b-a,d-a));
    return (c*y+d*x)/(x+y);
}
ld dis(pii a,pii b) { return sqrtl(SQ(a.f-b.f)+SQ(a.s-b.s)); }
bool kill1(pii a,pii b,pii c) {//1:can kill
    return cros(to(a,b),to(a,c))<0;
}
bool kill2(pii a,pii b,pii c) {//1:can kill
    return cros(to(a,b),to(a,c))>0;
}
int tar2(pii a,pii b,pii c) {
    return abs(cros(a,b)+cros(b,c)+cros(c,a));
}
ld len(pii x) { return sqrtl(SQ(x.f)+SQ(x.s)); }
ld deg(pii a,pii b) {
    return acosl(dot(a,b)/(len(a)*len(b)));
}
const ld PI=acosl(-1);
void solve() {
    int n;
    cin>>n;
    vector<pii> p(n);
    REP(i,n) cin>>p[i].f>>p[i].s;
    p.pb(p[0]);
    pii o=(p[0]+p[1])/2;
    int id1,id2;
    // REP1(i,n-1) ope(deg(p[1]-o,p[i]-o)*180/PI)
    REP1(i,n) if(deg(p[1]-o,p[i]-o)>=45*PI/180) {
        id1=i;
        break;
    }
    RREP1(i,n-1) if(deg(p[i]-o,p[0]-o)>=45*PI/180) {
        id2=i;
        break;
    }
    ld A=cros(p.back(),p[0]);
    REP(i,SZ(p)-1) A+=cros(p[i],p[i+1]);
    vector<pdd> np;
    np.pb(o);
    pii v1=p[1]-o;
    // op(o)ope(v1)op(v1.f-v1.s)ope(v1.f+v1.s)
    np.pb(inters_p(p[id1-1],p[id1],o,o+40000*(pdd{v1.f-v1.s,v1.f+v1.s})));
    for(int i=id1;i<=id2;i++) np.pb(p[i]);
    pii v2=p[0]-o;
    // op(o)ope(v2)op(v2.f+v2.s)ope(v2.s-v2.f)
    np.pb(inters_p(p[id2],p[id2+1],o,o+40000*(pdd{v2.f+v2.s,v2.s-v2.f})));
    
    ld A2=np.back().f*np[0].s-np.back().s*np[0].f;
    REP(i,SZ(np)-1) A2+=np[i].f*np[i+1].s-np[i].s*np[i+1].f;
    oparr(p)oparr(np)op(id1)ope(id2)
    // op(A)ope(A2)
    ld an=A2/A;
    cout<<fixed<<setprecision(9)<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
