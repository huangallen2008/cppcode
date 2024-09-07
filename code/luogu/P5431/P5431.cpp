#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
// const int mod=998244353;
int mod=998244353;
const int maxn=1e4+5;
const int maxb=18;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*1ll*x%mod;
        x=x*1ll*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) { return pw(x,mod-2); }
#define GC getchar()
#define PC putchar
inline int read()
{
    int x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=-x;
    return x;
}
inline void out(int x) {
    if(x<0) {
        PC('-');
        x=-x;
    }
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PC(*it);
    PC(' ');
}
signed main() {
    IOS();
    int n,k;
    n=read(),mod=read(),k=read();
    vector<int> a(n),f(n),fi(n),in(n);
    REP(i,n) a[i]=read();
    f[0]=a[0];
    for(int i=1;i<n;i++) f[i]=a[i]*1ll*f[i-1]%mod;
    fi[n-1]=inv(f[n-1]);
    for(int i=n-2;i>=0;i--) fi[i]=fi[i+1]*1ll*a[i+1]%mod;
    in[0]=fi[0];
    for(int i=1;i<n;i++) in[i]=fi[i]*1ll*f[i-1]%mod;
    int an=0;
    RREP(i,n) an=(an+in[i])*1ll*k%mod;
    out(an);
    return 0;
}