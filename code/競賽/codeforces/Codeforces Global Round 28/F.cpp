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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
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
const int maxb=30;
const int maxo=61; /////////////////////
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Vi a,b;
int di(int a,int b) { return (a+b-1)/b; }
pii st[maxb][maxn];
void st_init() {
    REP(i,n) st[0][i]={b[i],i};
    REP1(i,maxb-1) {
        REP(j,n) {
            st[i][j]=min(st[i-1][j],st[i-1][min(n-1,j+(1<<i-1))]);
        }
    }
}
pii st_qu(int l,int r) {
    int lg=__lg(r-l+1);
    return min(st[lg][l],st[lg][r-(1<<lg)+1]);
}
int mnid(int l,int r) {
    return st_qu(l,r).s;
}
Vi f(int l,int r) {
    if(l>r) {
        Vi res(maxo,1);
        return res;
    }
    if(l==r) {
        Vi res(maxo);
        res[0]=a[l];
        REP1(i,maxo-1) res[i]=di(res[i-1],b[l]);
        return res;
    }
    int m=mnid(l,r);
    // op(l)op(r)ope(m)
    Vi r1=f(l,m-1),r2=f(m+1,r);
    // op(l)ope(r)oparr(r1)oparr(r2)
    Vi res(maxo,inf);
    REP(i,maxo) {
        REP(j,i+1) {
            chmin(res[i],max({r1[j],r2[i-j],a[m]}));
        }
    }
    // oparr(res)
    REP1(i,maxo-1) chmin(res[i],di(res[i-1],b[m]));
    // oparr(res)
    return res;
}
void solve() {
    cin>>n;
    a=b=Vi(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    st_init();
    Vi an=f(0,n-1);
    // oparr(an)
    REP(i,maxo) {
        if(an[i]==1) {
            cout<<i<<'\n';
            return;
        }
    }  ///////////////remenber maxo=60
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}