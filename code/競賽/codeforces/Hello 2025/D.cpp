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
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int mp,ms,ma,sum;
    }zr={-inf,-inf,-inf,0};
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.mp=max(b.mp,b.sum+c.mp);
        a.ms=max(c.sum+b.ms,c.ms);
        a.ma=max({b.ma,c.ma,b.ms+c.mp});
        a.sum=b.sum+c.sum;
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    vector<Seg> s;
    int n;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w].sum=v;
            s[w].mp=s[w].ms=s[w].ma=max(0ll,v);
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    int qu() { return s[1].ma; }
    // Seg _qu(int w,int l,int r,int ql,int qr) {
    //     if(ql<=l&&r<=qr) return s[w];
    //     if(ql>r||qr<l) return zr;
    //     int m=l+r>>1;
    //     return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    // }
    // int qu(int l,int r) {
    //     return _qu(1,0,n-1,l,r).ms2;
    // }
}seg1,seg2;
void solve() {
    int n,q;
    cin>>n>>q;
    Vi a(n);
    REP(i,n) cin>>a[i];
    // if(n==1) {
    //     int x;
    //     REP(i,q) cin>>x>>x;
    //     REP(i,q) cout<<"0\n";
    //     return;
    // }
    seg1.init(n-1);
    seg2.init(n-1);
    REP(i,n-1) {
        seg1.ud(i,a[i+1]-a[i]-1);
        seg2.ud(i,a[i]-a[i+1]-1);
    }
    cout<<max(seg1.qu(),seg2.qu())<<'\n';
    REP(i,q) {
        int u,v;
        cin>>u>>v,u--;
        a[u]=v;
        if(u) {
            seg1.ud(u-1,a[u]-a[u-1]-1);
            seg2.ud(u-1,a[u-1]-a[u]-1);
        }
        if(u<n-1) {
            seg1.ud(u,a[u+1]-a[u]-1);
            seg2.ud(u,a[u]-a[u+1]-1);
        }
        cout<<max(seg1.qu(),seg2.qu())<<'\n';
    }
}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}