#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops")
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
#define ppi pair<pii,int>
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
const int maxn=4e5+5;
const int maxb=19;
const int inf=1<<30;
const int sn=400;
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
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r){ return pre(r)-pre(l-1); }
};
signed main() {
    IOS();
    int n=read(),q=read();
    // cin>>n>>q;
    Vi a(n);
    REP(i,n) cin>>a[i];
    vector<ppi> qu(q);
    REP(i,q) cin>>qu[i].f,qu[i].f.f--,qu[i].f.s--,qu[i].s=i;
    Vi dn(n);
    REP(i,n) dn[i]=i/sn;
    sort(ALL(qu),[&](ppi a,ppi b) { 
        return dn[a.f.f]==dn[b.f.f]?(dn[a.f.f]&1?a.f.s>b.f.s:a.f.s<b.f.s):a.f.f<b.f.f;
    });
    Vi t=a;
    t.pb(-inf);
    sort(ALL(t));
    REP(i,n) a[i]=lower_bound(ALL(t),a[i])-t.begin();
    BIT bit;
    bit.init(n);
    int itl=0,itr=-1;
    auto upd=[&](int x,int c=1) {
        bit.ud(x,t[x]*c);
    };
    auto gan=[&]() {
        int now=1,id=0;
        int lid=0;
        while(id<n) {
            id=upper_bound(ALL(t),now)-t.begin()-1;
            if(id==lid) break;
            now+=bit.qu(lid+1,id);
            lid=id;
        }
        return now;
    };
    Vi an(q);
    REP(i,q) {
        while(itl>qu[i].f.f) upd(a[--itl],1);
        while(itr<qu[i].f.s) upd(a[++itr],1);
        while(itl<qu[i].f.f) upd(a[itl++],-1);
        while(itr>qu[i].f.s) upd(a[itr--],-1);
        an[qu[i].s]=gan();
    }
    REP(i,q) cout<<an[i]<<'\n';
    return 0;
}
