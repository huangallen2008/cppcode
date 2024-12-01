#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii operator+(pii a,pii b) { return {a.f+b.f,a.s+b.s}; }
pii operator-(pii a,pii b) { return {a.f-b.f,a.s-b.s}; }
pii to(pii a,pii b) { return b-a; }
int cros(pii a,pii b) { return a.f*b.s-a.s*b.f; }
int dot(pii a,pii b) { return a.f*b.f+a.s*b.f; }
int sig(int x) { return x<0?-1:(x>0?1:0); }
bool onl(pii a,pii b,pii p) {
    return dot(to(a,p),to(a,b))>=0&&dot(to(b,p),to(b,a))>=0&&cros(to(a,p),to(a,b))==0;
}
bool bana(pii a,pii b,pii c,pii d) {//a-b c-d
// op(a.f)op(a.s)op(b.f)op(b.s)op(c.f)op(c.s)op(d.f)ope(d.s)
    if(onl(a,b,c)||onl(a,b,d)||onl(c,d,a)||onl(c,d,b)) return 1;
    return sig(cros(b-a,c-a))*sig(cros(to(a,b),to(a,d)))<0&&sig(cros(to(c,d),to(c,a)))*sig(cros(to(c,d),to(c,b)))<0;
}
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    vector<pii> c(n),d(m);
    REP(i,n) cin>>c[i].f>>c[i].s;
    REP(i,m) cin>>d[i].f>>d[i].s;
    int cnt=0;
    REP(i,m) {
        for(int j=i+1;j<m;j++) {
            REP(k,n-1) {
                cnt+=bana(c[k],c[k+1],d[i],d[j]);
            }
        }
    }
    cout<<cnt<<'\n';
    return 0;
}