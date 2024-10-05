#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
const int mod=1e9+7;
const int maxn=5;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int sum,mp,ms,mc;
    }zr={0,0,0,0};
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.sum=b.sum+c.sum;
        a.mp=max(b.mp,b.sum+c.mp);
        a.ms=max(c.ms,c.sum+b.ms);
        a.mc=max({b.mc,c.mc,b.ms+c.mp});
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    int n;
    vector<Seg >s;
    void build(int w,int l,int r,vector<int>&a) {
        if(l==r) {
            s[w]={a[l],a[l],a[l],a[l]};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,vector<int> &a) {
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
        return _qu(1,0,n-1,l,r).mc;
    }
}seg;
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    Vi a(n),b(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    Vi c(n);
    REP(i,n) c[i]=a[i]-b[i]+k;
    oparr(c)
    seg.init(n,c);
    int q;
    cin>>q;
    REP(i,q) {
        int l,r;
        cin>>l>>r,l--,r--;
        cout<<seg.qu(l,r)<<'\n';
    }
    return 0;
}