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
const int maxn=2e5+5;
const int maxv=2e9+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii operator+(pii a,pii b) { return {a.f+b.f,a.s+b.s}; }
pii operator-(pii a) { return {-a.f,-a.s}; }
pii operator-(pii a,pii b) { return {a.f-b.f,a.s-b.s}; }
int sig(int x) { return x<0?-1:(x>0?1:0); }
int dot(pii a,pii b) { return a.f*b.f+a.s*b.s; }
int cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
bool inl(pii a,pii b,pii c) {  return cros(b-a,c-a)==0&&dot(b-a,c-a)>=0&&dot(a-b,c-b)>=0; }
bool is_inter(pii a,pii b,pii c,pii d) {
    if(inl(a,b,c)||inl(a,b,d)||inl(c,d,a)||inl(c,d,b)) return 1;
    return sig(cros(b-a,c-a))*sig(cros(b-a,d-a))<0&&sig(cros(d-c,a-c))*sig(cros(d-c,b-c))<0;
}
void Solve() {
    int n;
    cin>>n;
    Vpii a(n);
    REP(i,n) cin>>a[i];
    sort(ALL(a));
    auto dis=[&](pii a,pii b) { return SQ(a.s-b.s)+SQ(a.f-b.f); };
    auto brute=[&]() {
        int an=inf;
        REP(i,n) REP(j,i) chmin(an,dis(a[i],a[j]));
        return an;
    };
    auto solve=[&](auto solve,Vpii a) ->int{
        if(SZ(a)<=1) return inf;
        Vpii v1,v2;
        int n=SZ(a);
        REP(i,n) {
            if(i<(n>>1)) v1.pb(a[i]);
            else v2.pb(a[i]);
        }
        int mid=a[n>>1].f;
        int d1=solve(solve,v1),d2=solve(solve,v2);
        int d=min(d1,d2);
        Vpii c1,c2;
        int sd=sqrt(d);
        for(auto x:v1) if(x.f>=mid-sd) c1.pb(x);
        for(auto x:v2) if(x.f<=mid+d) c2.pb(x);
        sort(ALL(c1),[&](pii a,pii b) { return a.s<b.s; });
        sort(ALL(c2),[&](pii a,pii b) { return a.s<b.s; });
        int il=0,ir=0;
        int n1=SZ(c1),n2=SZ(c2);
        int an=d;
        REP(i,n1) {
            while(ir<n2&&c2[ir].s<=c1[i].s+d) ir++;
            while(il<n2&&c2[il].s<c1[i].s-d) il++;
            if(ir-il>6) {
                oparr(a)
                exit(0);
            }
            for(int j=il;j<ir;j++) chmin(an,dis(c1[i],c2[j]));
        }
        return an;
    };
    int ans=solve(solve,a);
    #ifdef LOCAL
    if(ans!=brute()) {
        oparr(a)
        exit(0);
    }
    #else
    cout<<ans<<'\n';
    #endif
}
signed main() {
    IOS();
    int T=1;
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    cin>>T;
    #endif
    while(T--) Solve();
    return 0;
}