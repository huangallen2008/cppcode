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
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    const int all=(1<<20)-1;
    struct Seg {
        int mx,no;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mx=max(b.mx,c.mx);
        a.no=b.no&c.no&(b.mx^c.mx^all);
    }
    void addtag(Seg a,Seg b) {
        a.mx=((a.mx&(b.no^all)))|(b.mx&b.no);
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a);
        addtag(c,a);
    }
    int n;
    vector<Seg> s;
    void build(int w,int l,int r,Vi &a) {
        if(l==r) {
            s[w]={a[l],all};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,Vi a) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,a);
    }
    void _and(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr&&((s[w].no|(v^all))==s[w].no)) {
            s[w].mx&=v;
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _and(w<<1,l,m,ql,qr,v);
        _and(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void rand(int l,int r,int v) {
        _and(1,0,n-1,l,r,v);
    }
    void _or(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr&&((s[w].no|(v))==s[w].no)) {
            s[w].mx|=v;
            return;
        }
        if(ql>r||qr<l) return ;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _or(w<<1,l,m,ql,qr,v);
        _or(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ror(int l,int r,int v){
        _or(1,0,n-1,l,r,v);
    }
    int _mx(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].mx;
        if(ql>r||qr<l) return -inf;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return max(_mx(w<<1,l,m,ql,qr),_mx(w<<1|1,m+1,r,ql,qr));
    }
    int mx(int l,int r) {
        return _mx(1,0,n-1,l,r);
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
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,x;
            cin>>l>>r>>x,l--,r--;
            seg.rand(l,r,x);
        }
        if(opt==2) {
            int l,r,x;
            cin>>l>>r>>x,l--,r--;
            seg.ror(l,r,x);
        }
        if(opt==3) {
            int l,r;
            cin>>l>>r,l--,r--;
            cout<<seg.mx(l,r)<<'\n';
        }
    }
    return 0;
}