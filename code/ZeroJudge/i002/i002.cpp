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
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
// #define ld long double
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
const int maxn=1e5+5;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
const int N=1<<20;
namespace NTT {
    const int mod=998244353;
    int pw(int x,int p) {
        int r=1;
        while(p>0) {
            if(p&1) r=r*x%mod;
            x=x*x%mod;
            p>>=1;
        }
        return r;
    }
    int inv(int x) {
        return pw(x,mod-2);
    }
    int MA(int a,int b) { int c=a+b; if(c>mod) c-=mod; return c; }
    int MM(int a,int b) { int c=a-b; if(c<0) c+=mod; return c; }
    const int G=3;
    const int INVG=inv(G);
    vector<int> r,c,a,b;
    int n1,n2,t,lt;
    void _ntt(vector<int> &a,int opt){
        for(int i=0;i<t;i++) if(i<r[i]) swap(a[i],a[r[i]]);
        for(int m=1;m<t;m<<=1){
            int gn=pw(opt==1?G:INVG,(mod-1)/(m<<1));
            for(int l=0;l<t;l+=m<<1){
                int g=1;
                for(int k=l;k<l+m;k++){
                    int t1=a[k],t2=a[k+m]*g%mod;
                    a[k+m]=MM(t1,t2);
                    a[k]=MA(t1,t2);
                    g*=gn,g%=mod;
                }
            }
        }
    }
    vector<int>& ntt(vector<int>&_a,vector<int>&_b){
        a=_a,b=_b;
        n1=a.size(),n2=b.size();
        t=1,lt=0;
        while(t<n1+n2) t<<=1,lt++;
        while(a.size()<t) a.pb(0);
        while(b.size()<t) b.pb(0);
        assert(t<=(1ll<<23));
        r=c=vector<int>(t);
        REP(i,t) r[i]=(r[i>>1]>>1)|((i&1)<<(lt-1));
        _ntt(a,1),_ntt(b,1);
        for (int i=0;i<t;i++) c[i]=a[i]*b[i]%mod;
        _ntt(c,-1);
        int invn=inv(t);
        for(int i=0;i<=n1+n2;i++) c[i]=c[i]*invn%mod;
        while(c.size()&&c.back()==0) c.pop_back();
        return c;
    }
};
int n,k;
Vi f,a,dp;
void dc(int l,int r) {
    if(l==r) return;
      if(4){op(l)ope(r)}
    int m=l+r>>1;
    dc(l,m);
    op(l)ope(r)
    int len=r-l+1,llen=m-l+1;
    Vi ld(llen);
    for(int i=l;i<=m;i++) ld[i-l]=dp[i];
    Vi ta(llen+1);
    REP1(i,llen) ta[i]=a[i];
    Vi res=NTT::ntt(ld,ta);
        if(l==7714){
            op(l)ope(r)
            oparr(ld)oparr(ta)
            oparr(res)
        }
    for(int i=m+1;i<=r;i++) {
        if(i>n) {
            if(l==7714)ope("oo")
            addmod(dp[i],res[i-l]);
        }
    }
    if(l==7714){op(l)op(r)ope("ok")op(m)ope(r)}
    dc(m+1,r);
}
signed main() {
    IOS();
    cin>>n>>k;
    f=a=Vi(n+1);
    dp=Vi(k+1);
    REP1(i,n) cin>>f[i];
    for(int i=1;i<n&&i<=k;i++) dp[i]=f[i];
    REP1(i,n) cin>>a[i];
    dc(1,k);
    oparr(dp)
    int an=(dp[k]+mod)%mod;
    cout<<an<<'\n';
    return 0;
}