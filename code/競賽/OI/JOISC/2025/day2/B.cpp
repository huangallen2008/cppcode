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
const int maxb=20;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct ST {
    int n;
    Vi a;
    vector<Vi> st;
    void init(int _n,Vi _a) {
        n=_n;
        a=_a;
        st=vector<Vi>(maxb,Vi(n));
        REP(i,n) st[0][i]=a[i];
        REP1(i,maxb-1) {
            REP(j,n) st[i][j]=min(st[i-1][j],st[i-1][min(n-1,j+(1<<i-1))]);
        }
    }
    int qu(int l,int r) {
        int lg=__lg(r-l+1);
        return min(st[lg][l],st[lg][r-(1<<lg)+1]);
    }
};
signed main() {
    IOS();
    int n,x;
    cin>>n>>x;
    int N=n*2;
    Vi a(N),c(N);
    REP(i,N) cin>>a[i],a[i]--;
    REP(i,N) cin>>c[i];
    Vpii id(n,{-1,-1});
    REP(i,N) {
        if(id[a[i]].f==-1) id[a[i]].f=i;
        else id[a[i]].s=i;
    }
    oparr(id)
    Vi v(N);
    REP(i,n) v[0]+=id[i].f;
    v[0]-=n*(n-1)>>1;
    REP1(i,N-1) {
        int now=v[i-1];
        now-=(id[a[i-1]].f-(i-1)+N)%N;
        op(i)op(now)
        swap(id[a[i-1]].f,id[a[i-1]].s);
        now-=(n-1);op(now)op(id[a[i-1]].f-i+n)
        now+=(id[a[i-1]].f-i+N)%N;ope(now)
        v[i]=now;
    }
    vector<pipii> t(N);
    REP(i,N) t[i]={v[i],{c[i],c[i]+x*v[i]}};
    sort(ALL(t));
    Vi v1(N),v2(N),vt(N);
    REP(i,N) vt[i]=t[i].f;
    REP(i,N) v1[i]=t[i].s.f;
    REP(i,N) v2[i]=t[i].s.s;
    ST st1,st2;
    st1.init(N,v1);
    st2.init(N,v2);
    oparr(vt)oparr(v1)oparr(v2)
    int q;
    cin>>q;
    REP(i,q) {
        int s;
        cin>>s;
        s=n*n-s;
        int it=lower_bound(ALL(vt),s)-vt.begin();
        int mn1=st1.qu(0,it-1),mn2=st2.qu(it,N-1)-s*x;
        int an=min(mn1,mn2);
        cout<<an<<'\n';
    }
    return 0;
}
