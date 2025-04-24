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
    int n;
    Vi s;
    void init(int _n) {
        n=_n;
        s=Vi(n<<2,inf);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            chmin(s[w],v);
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        s[w]=min(s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) { _ud(1,0,n-1,u,v); }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return inf;
        int m=l+r>>1;
        return min(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) { return _qu(1,0,n-1,l,r); }
};
signed minimum_garbage(const std::vector<signed> &L, const std::vector<signed> &R,const std::vector<signed> &J, const std::vector<signed> &Q) {
    int n = L.size();
    int m = J.size();
    int k = Q.size();
    Vpii a(n);
    Vi t,b(m),c(k);
    t.pb(-inf);
    REP(i,m) b[i]=J[i],t.pb(b[i]);
    REP(i,k) c[i]=Q[i],t.pb(c[i]);
    sort(ALL(c));
    sort(ALL(t));
    t.erase(unique(ALL(t)),t.end());
    REP(i,m) b[i]=lower_bound(ALL(t),b[i])-t.begin();
    b.pb(0);
    sort(ALL(b));
    REP(i,k) c[i]=lower_bound(ALL(t),c[i])-t.begin();
    REP(i,n) a[i]={lower_bound(ALL(t),L[i])-t.begin(),upper_bound(ALL(t),R[i])-t.begin()-1};
    oparr(b)oparr(c)oparr(a)
    int N=SZ(t);
    Vi pc(N+1);
    REP(i,k) pc[c[i]]++;
    REP1(i,N-1) pc[i]+=pc[i-1];
    SEG seg,seg2;
    seg.init(N);
    seg2.init(N);
    seg.ud(0,0);
    seg2.ud(0,0-0);
    sort(ALL(a));
    Vi dp(N+1,inf);
    dp[0]=0;
    for(auto [l,r]:a) {
        int l1=*prev(upper_bound(ALL(b),l));
        chmin(dp[r],min(seg.qu(l1,l-1)+pc[r]-pc[l-1],));
        seg2.ud(r,dp[r]-pc[r]);
        seg.ud(r,dp[r]);
        oparr(dp)
    }
    int an=dp[b.back()];
    return an;
}
