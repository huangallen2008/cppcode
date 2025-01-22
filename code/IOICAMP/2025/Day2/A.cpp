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
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=5;
const int maxv=1e5+5;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct LCSEG {
    struct line {
        int m,k;
    };
    int cal(line l,int x) {
        return l.m*x+l.k;
    }
    line mxl(line a,line b,int x) {
        if(cal(a,x)>cal(b,x)) return a;
        else return b;
    }
    vector<line> s;
    int n;
    void init(int _n) {
        n=_n;
        s=vector<line>(n<<2,{0,0});
    }
    void _ud(int w,int l,int r,line v) {
        if(l==r) {
            s[w]=mxl(s[w],v,l);
            return;
        }
        int m=l+r>>1;
        if(cal(v,m)>cal(s[w],m)) swap(s[w],v);
        if(v.m<s[w].m) {
            _ud(w<<1,l,m,v);
        }
        else {
            _ud(w<<1|1,m+1,r,v);
        }
    }
    void ud(line v) {
        _ud(1,0,n-1,v);
    }
    int _qu(int w,int l,int r,int x) {
        int an=cal(s[w],x);
        if(l==r) return an;
        int m=l+r>>1;
        if(x<=m) return max(an,_qu(w<<1,l,m,x));
        else return max(an,_qu(w<<1|1,m+1,r,x));
    }
    int qu(int x)  {
        return _qu(1,0,n-1,x);
    }
} lcseg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    // lcseg.init(n+1);
    Vi a(n+1);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int x,y;
            cin>>x>>y;
            REP1(j,n) chmax(a[j],x*j+y);
            // lcseg.ud({a,b});
        }if(opt==3) {
            int l,r;
            cin>>l>>r;
            int mx=0;
            for(int j=l;j<=r;j++) chmax(mx,a[j]);
            cout<<mx<<'\n';
            // int rr=max(lcseg.qu(l),lcseg.qu(r));
            // cout<<rr<<'\n';
        }if(opt==2) {
            int c;
            cin>>c;
            REP1(i,n) chmin(a[i],c);
        }
    }
    return 0;
}