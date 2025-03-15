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
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
namespace NTT {
    const int mod=998244353;
    int pw(int x,int p) {
        int r=1;
        while(p>0) {
            if(p&1) r*=x,r%=mod;
            x*=x,x%=mod;
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
Vi ntt_pw(Vi x,int p) {
	Vi r={1};
	while(p>0) {
		if(p&1) r=NTT::ntt(r,x);
		x=NTT::ntt(x,x);
		p>>=1;
	}
	return r;
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
int inv(int x) { return pw(x,mod-2); }
Vi fac(maxn),infac(maxn);
void com_init() {
    fac[0]=1;
    REP1(i,maxn-1) fac[i]=fac[i-1]*i%mod;
    infac[maxn-1]=inv(fac[maxn-1]);
    RREP(i,maxn-1) infac[i]=infac[i+1]*(i+1)%mod;
}
int C(int n,int k) {
    return (fac[n]*infac[k]%mod)*infac[n-k]%mod;
}
int n=8;
vector<Vi> ldp,hdp;
void leolin() {
    ldp=vector<Vi>(n+1,Vi(n+1));
    ldp[0][0]=1;
    REP1(i,n) {
        REP(j,n+1) {
            ldp[i][j]=(ldp[i-1][j]+(j?(i-1)*ldp[i-1][j-1]:0))%mod;
        }
    }
	// return ldp[n][k];
    // oparr(ldp)
}
void huangallen() {
	// Vi v0={1};
	// Vi r(n+1);
	// REP(i,n+1) r[i]=infac[i];

    hdp=vector<Vi>(n+1,Vi(n+1));
    hdp[0][0]=1;
    REP1(i,n) {
        REP1(j,i) {
            REP(k,i) {
                addmod(hdp[i][j],hdp[k][j-1]*(k?inv(k):1)%mod);
            }
        }
    }
	REP1(i,n) REP(j,i+1) {hdp[i][j]=(hdp[i][j]*fac[i-1])%mod;}
    oparr(hdp)
}
bool check() {
    REP1(i,n) {
        REP1(j,i) {
            if(ldp[i][j]!=hdp[i][i-j]) return 0;
        } 
    }
    return 1;
}
signed main() {
    IOS();
    com_init();
    leolin();
    huangallen();
    if(check()) cout<<"YES!!!\n";
    return 0;
}