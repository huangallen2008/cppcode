#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
const int mod=1e9+7;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define GC _getchar_nolock()
#define PC _putchar_nolock
#else 
#define GC getchar_unlocked()
#define PC putchar_unlocked
#endif
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
inline string reads()
{
    char c=GC;
    string s;
    while(c==' '||c=='\n')c=GC;
    while(c!=' '&&c!='\n'&&c!=EOF) s+=c,c=GC;
    return s;
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
    // PC('\n');
}
#define Vll vector<ll>
int n,m;
Vi trans(Vi v,int type=1) {
    REP(i,n) {
        REP(j,1<<n) if(j>>i&1) {
            addmod(v[j],v[j^(1<<i)]*type);
        }
    }
    return v;
}
Vll merge(Vll a,Vll b) {
    REP(i,1<<n) a[i]=a[i]*b[i]%mod;
    return a; 
}
signed main() {
    IOS();
    n=read(),m=read();
    // cin>>n>>m;
    vector<Vi> a(m,Vi(n,-1));
    REP(i,n) {
        string s=reads();
        // cin>>s;
        REP(j,m) {
            char c=s[j];
            // cin>>c;
            if(c!='.') a[j][i]=c-'a';
        }
    }
    Vll dp(1<<n,1);
    int all=(1<<n)-1;
    REP(i,m) {
        Vi d(1<<n);
        int sum=1;
        Vi nv(26,1);
        auto upd=[&](int u,bool type) ->void{
            if(u==-1) return;
            // op(u)
            if(type) {
                sum+=nv[u];
                nv[u]<<=1;
            }else {
                nv[u]>>=1;
                sum-=nv[u];
            }
        };
        d[0]=1;
        for(int j=1;j<1<<n;j++) {
            REP(k,n) {
                if(j>>k&1) {
                    upd(a[i][k],1);
                    break;
                }
                else {
                    upd(a[i][k],0);
                }
            }
            d[j]=sum;
        }
        dp=merge(dp,d);
        // oparr(d)oparr(dp)
    }
    dp=trans(dp,-1);
    // oparr(dp)
    Vi an(n+1);
    REP(i,1<<n) {
        addmod(an[n-__builtin_popcount(i)],dp[i]);
    }
    REP(i,n+1) out((an[i]+mod)%mod),PC(' ');//cout<<(an[i]+mod)%mod<<' ';
    // cout<<'\n';
    PC('\n');
    return 0;
}