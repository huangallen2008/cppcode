#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
pii st[maxb][maxn];
Vi a,b;
void st_init() {
    REP(i,n) st[0][i]={b[i],i};
    REP1(i,maxb-1) {
        REP(j,n) {
            st[i][j]=max(st[i-1][j],st[i-1][min(n-1,j+(1<<i-1))]);
        }
    }
}
pii st_qu(int l,int r) {
    int lg=__lg(r-l+1);
    return max(st[lg][l],st[lg][r-(1<<lg)+1]);
}
int mxid(int l,int r) {
    return st_qu(l,r).s;
}
Vi mpc(Vi a,Vi b) {
    if(a.empty()||b.empty()) return {};
    int n=a.size(),m=b.size();
    Vi c(n+m-1);
    int i1=0,i2=0;
    c[0]=a[i1]+b[i2];
    for(int i=1;i<n+m-1;i++) {
        if(i2==m-1||(i1!=n-1&&a[i1+1]-a[i1]>b[i2+1]-b[i2])) i1++;
        else i2++;
        c[i]=a[i1]+b[i2];
    }
    return c;
}
Vi msrt(Vi a,Vi b) {
    int n=a.size(),m=b.size();
    Vi c(n+m);
    int i1=0,i2=0,it=0;
    while(i1<n&&i2<m) {
        if(a[i1]>b[i2]) c[it++]=a[i1++];
        else c[it++]=b[i2++];
    }
    while(i1<n) c[it++]=a[i1++];
    while(i2<m) c[it++]=b[i2++];
    return c;
}
pair<Vi,Vi> f(int l,int r) {
    if(l>r) return {{},{}};
    if(l==r) return {{0,a[l]-b[l]},{a[l]}};
    int m=mxid(l,r);
    pair<Vi,Vi> lr=f(l,m-1),rr=f(m+1,r);
    Vi an1=msrt(lr.s,rr.s);
    Vi an2=mpc(lr.f,rr.f);
    Vi p=an1;
    p.insert(p.begin(),a[m]-b[m]);
    REP1(i,p.size()-1) p[i]+=p[i-1];
    REP(i,an2.size()) chmax(an2[i],p[i]);
    return {an1,an2};
}  
signed main() {
    IOS();
    cin>>n;
    a=b=Vi(n);
    REP(i,n) cin>>a[i]>>b[i];
    st_init();
    auto [an,leolin]=f(0,n-1);
    oparr(an)
    REP1(i,n) cout<<an[i]<<'\n';
    return 0;
}