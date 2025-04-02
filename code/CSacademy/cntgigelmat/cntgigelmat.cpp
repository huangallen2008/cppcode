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
const int mx=1e9+5;
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
    int qu(int l,int r) { return pre(r)-pre(l-1); }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<Vi> a(n+2,Vi(m+2));
    REP1(i,n) {
        REP1(j,m) {
        char c;
        cin>>c;
        a[i][j]=c=='1';
    }
    }
    vector<Vi> cl,cr,cu,cd,clu,crd,c1,c2;
    cl=cr=cu=cd=clu=crd=c1=c2=vector<Vi>(n+2,Vi(m+2));
    REP1(i,n) {
        REP1(j,m) {
            if(a[i][j]) {
                cl[i][j]=cl[i][j-1]+1;
                cu[i][j]=cu[i-1][j]+1;
                clu[i][j]=clu[i-1][j-1]+1;
            }
        }
    }
    RREP1(i,n) {
        RREP1(j,m) {
            if(a[i][j]) {
                cr[i][j]=cr[i][j+1]+1;
                cd[i][j]=cd[i+1][j]+1;
                crd[i][j]=crd[i+1][j+1]+1;
            }
        }
    }
    REP1(i,n) {
        REP1(j,m) {
            c1[i][j]=min({cr[i][j],cd[i][j],crd[i][j]});
            c2[i][j]=min({cl[i][j],cu[i][j],clu[i][j]});
        }
    }
    auto go=[&](int x,int y) ->ll{
        BIT bit;
        bit.init(n);
        vector<Vi> del(n+1);
        ll an=0;
        for(int i=x,j=y;i<=n&&j<=m;i++,j++) {
            bit.ud(i,1);
            if(i+c1[i][j]<=n) del[i+c1[i][j]].pb(i);
            for(int t:del[i]) bit.ud(t,-1);
            an+=bit.qu(max(i-c2[i][j]+1,1),i);
        }
        return an;
    };
    ll an=0;
    for(int i=n;i>1;i--) an+=go(i,1);
    REP1(i,m) an+=go(1,i);
    cout<<an<<'\n';
    return 0;
}
