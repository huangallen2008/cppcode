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
const int maxn=1e6+5;
const int maxv=1000;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int sum,mp,ms,ma;
    };
    const Seg zr={0,0,0,0};
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.sum=b.sum+c.sum;
        a.mp=max(b.mp,b.sum+c.mp);
        a.ms=max(c.ms,c.sum+b.ms);
        a.ma=max({b.ma,c.ma,b.ms+c.mp});
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    int n;
    vector<Seg> s;
    void build(int w,int l,int r,Vi &a) {
        if(l==r) {
            s[w].sum=a[l];
            s[w].mp=s[w].ms=s[w].ma=max(a[l],0ll);
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,Vi &a) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,a);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return zr;
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r).ma;
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;  
    Vi a(n);
    REP(i,n) cin>>a[i];
    seg.init(n,a);
    REP(i,q) {
        int l,r;
        cin>>l>>r,l--,r--;
        int an=seg.qu(l,r);
        cout<<an<<'\n';
    }
    return 0;
}
