#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
#define ll long long
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
#define chmin(x,y) mn(x,y)
#define addmod(x,y) x=((x+(y))%mod)
//#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
//#else
//#define op(x) ;
//#define ope(x) ;
//#define oparr(x) ;
//#define entr ;
//#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const ll inf=(1ll<<62);
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//int rd(int l,int r) {
//    return uniform_int_distribution<int>(l,r)(rng);
//}
#include<unistd.h>
char OB[65536]; int OP;
inline char RC(){static char buf[65536],*p=buf,*q=buf;return p==q&&(q=(p=buf)+read(0,buf,65536))==buf?-1:*p++;}
inline int R(){static char c;int a;while((c=RC())<'0');a=c^'0';while((c=RC())>='0')a*=10,a+=c^'0';return a;}
int n,k,x,y,z;
inline ll cost(const int v) {
    return v<0?(ll)x*(-v):(ll)y*v;
}
inline void mn(ll &a,ll b) { if(b<a) swap(a,b); }
signed main(){
    IOS();
//    cin>>n>>k>>x>>y>>z;
    n=R(),k=R(),x=R(),y=R(),z=R();
    vector<int> a(n);
    REP(i,n) a[i]=R();
    vector<int> s(1<<n);
    const int all=(1<<n)-1;
    for(int i=1;i<=all;i++) {
        s[i]=s[i^(i&-i)]+a[__lg(i&-i)];
    }
    ll an=inf;
    vector<ll> dp1(1<<n);
    for(int f1=1;f1*f1<=k;f1++) {
        if(k%f1) continue;
        int f2=k/f1;
        dp1[0]=inf;
        for(int i=1;i<=all;i++) {
            dp1[i]=cost(s[i]-f1)+(ll)(__builtin_popcount(i))*z;
        }
        REP(i,n) {
            int t=all^(1<<i);
//            REP(j,1<<n) {
            for(int j=t;j>0;j=(j-1)&t) {
                chmin(dp1[j^(1<<i)],dp1[j]);
            }
        }
        for(int i=1;i<all;i++) {
            chmin(an,cost(s[i]-f2)+(ll)(__builtin_popcount(i)-2)*z+dp1[all^i]);
        }
    }
    cout<<an<<'\n';
    return 0;
}
