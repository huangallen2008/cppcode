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
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Vi a,b;
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
Vi mx(Vi a,Vi b) {
    REP(i,b.size()) chmax(a[i],b[i]);
    return a;
}
pair<Vi,Vi> f(int l,int r) {
    if(l==r) return {{-inf,a[l]-b[l]},{0,a[l]}};
    int m=l+r>>1;
    pair<Vi,Vi> lr=f(l,m),rr=f(m+1,r);
    Vi an1=mx(mpc(lr.s,rr.f),lr.f);
    Vi an2=mpc(lr.s,rr.s);
    // op(l)op(r)ope(m)oparr(lr.f)oparr(lr.s)oparr(rr.f)oparr(an1)oparr(lr.s)oparr(rr.s)oparr(an2)entr
    return {an1,an2};
}  
bool real(Vi my_an) {
    Vi an(n+1,-inf);
    REP(i,1<<n) {
        int mx=-inf,sum=0;
        REP(j,n) if(i>>j&1) {
            chmax(mx,b[j]);
            sum+=a[j];
        }
        chmax(an[__builtin_popcount(i)],sum-mx);
    }
    REP1(i,n)if(my_an[i]!=an[i]) return 0;
    return 1;
}
signed main() {
    IOS();
    
    int T=600;while(T--){
    n=rd(1,7);
    // cin>>n;
    a=b=Vi(n);
    REP(i,n) a[i]=rd(-10,10),b[i]=rd(-10,10);
    // REP(i,n) cin>>a[i]>>b[i];
    Vpii t(n);
    REP(i,n) t[i]={a[i],b[i]};
    sort(ALL(t),[&](pii a,pii b) {
        return a.s<b.s;
    });
    REP(i,n) a[i]=t[i].f,b[i]=t[i].s;
    // oparr(a)oparr(b)oparr(t)
    auto [an,leolin]=f(0,n-1);
    // oparr(an)
    // REP1(i,n) cout<<an[i]<<'\n';
    if(!real(an)) {
        REP(i,n) cout<<t[i].f<<' '<<t[i].s<<'\n';entr
    }
    }
    return 0;
}

/*
-9 10
6 -10
3 -7
3 -4
-5 6
-3 9
*/