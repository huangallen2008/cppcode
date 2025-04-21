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
pii operator-(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
pii operator+(pii a,pii b) { return {b.f+a.f,b.s+a.s}; }
pii operator*(pii a,int b) { return {b*a.f,b*a.s}; }
pdd operator/(pii a,int b) { return {(ld)a.f/b,(ld)a.s/b}; }
pii to(pii a,pii b) { return {b.f-a.f,b.s-a.s}; }
int cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
int dot(pii a,pii b) { return a.f*b.f+a.s*b.s; }
int sign(int x) { if(x>0) return 1;else if(x<0) return -1;else return 0; }
bool onl(pii l1,pii l2,pii p) {return cros(to(l1,l2),to(l1,p))==0&&dot(to(l1,l2),to(l1,p))>=0&&dot(to(l2,l1),to(l2,p))>=0;}
bool dif_side(pii a,pii b,pii c,pii d) {return sign(cros(to(a,b),to(a,c)))*sign(cros(to(a,b),to(a,d)))<0;}
bool inters(pii a,pii b,pii c,pii d) { return onl(a,b,c)||onl(a,b,d)||onl(c,d,a)||onl(c,d,b)||(dif_side(a,b,c,d)&&dif_side(c,d,a,b)); }
pdd inters_p(pii a,pii b,pii c,pii d) { 
    int x=abs(cros(b-a,c-a)),y=abs(cros(b-a,d-a));
    return (c*y+d*x)/(x+y);
}
void solve() {
    pii a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    op(a)op(b)op(c)ope(d)
    op(onl(a,b,c))op(onl(a,b,d))op(onl(c,d,a))ope(onl(c,d,b))
    if(!inters(a,b,c,d)) {
        cout<<"none\n";
        return;
    }
    cout<<fixed<<setprecision(2);
    if(cros(b-a,d-c)==0) {
        pdd p1=max(a,c),p2=min(b,d);
        if(p1==p2) cout<<p1.f<<' '<<p1.s<<'\n';
        else cout<<p1.f<<' '<<p1.s<<' '<<p2.f<<' '<<p2.s<<'\n';
    }else {
        pdd an=inters_p(a+a-b,b+b-a,c+c-d,d+d-c);
        cout<<an.f<<' '<<an.s<<'\n';
    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
