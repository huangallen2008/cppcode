#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,sse4,bmi2,popcnt")
#define iint signed
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
const int mod=1e9+7;
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
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
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x){ return pw(x,mod-2); }
const int inv2=inv(2);
signed main() {
    IOS();
    int n=read(),m=read(),k=read();
    // cin>>n>>m>>k;
    Vpii a(k);
    REP(i,k) a[i].f=read(),a[i].s=read();//cin>>a[i].f>>a[i].s;
        k++,a.pb({n+1,0});
    sort(ALL(a));
    int sx=0,an=0;
    REP(i,k) { //sx+1 -> a[i].f-1
        if(i&&a[i].f==a[i-1].f) continue;
        set<int> s;
        s.insert(0);
        s.insert(m+1);
        auto cost=[&](int len) {
            return ((len+1)*len%mod)*inv2;
        };
        int now=cost(m)%mod;
        auto ins=[&](int x) ->void{
            // ope(x)
            if(s.find(x)!=s.end()) return;
            s.insert(x);
            auto it=s.find(x);
            (now+=cost(*next(it)-x)+cost(x-*prev(it))-cost(*next(it)-*prev(it)))%=mod;
            // (now-=cost(*next(it)-*prev(it)))%=mod;
            // (now+=cost(x-*prev(it)))%=mod;
            // (now+=cost(*next(it)-x))%=mod;
        };
        int lx=sx+1;
        int len0=a[i].f-lx;
        int j=i;
        while(j<k) {
            // op(i)op(j)op(len0)op(lx)op(a[j].f)ope(now)
            if(j!=i)(an+=(now*(a[j].f-lx)%mod)*len0)%=mod;
            else (an+=((now*(a[j].f-lx)%mod)*(len0+1)%mod)*inv2)%=mod;
            // ope(an)
            int nx=a[j].f;
            while(j<k&&a[j].f==nx) ins(a[j++].s);
            lx=nx;
        }
        sx=a[i].f;
    }
    ope(an)
    REP(i,k) { //sx+1 -> a[i].f-1
        if(i&&a[i].f==a[i-1].f) continue;
        set<int> s;
        s.insert(0);
        s.insert(m+1);
        auto cost=[&](int len) {
            return ((len+1)*len%mod)*inv2;
        };
        int now=cost(m)%mod;
        auto ins=[&](int x) ->void{
            if(s.find(x)!=s.end()) return;
            s.insert(x);
            auto it=s.find(x);
            (now+=cost(*next(it)-x)+cost(x-*prev(it))-cost(*next(it)-*prev(it)))%=mod;
            // (now+=)%=mod;
            // (now+=)%=mod;
        };
        int lx=a[i].f;
        int j=i;
        while(j<k&&a[j].f==a[i].f) ins(a[j++].s);
        while(j<k) {
            (an+=(now*(a[j].f-lx)))%=mod;
            // op(i)op(now)op(j)op(a[j].f)op(lx)ope(an)
            int nx=a[j].f;
            while(j<k&&a[j].f==nx) ins(a[j++].s);
            lx=nx;
        }
        // sx=a[i].f;
    }
    ope(an)
            //    an=0;
    int ans=((n*(n+1)>>1)%mod)*((m*(m+1)>>1)%mod)%mod-an;
    ans=(ans%mod+mod)%mod;
    cout<<ans<<'\n';
    return 0;
}