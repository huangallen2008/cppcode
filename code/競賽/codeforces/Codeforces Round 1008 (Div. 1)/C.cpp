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
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int len=0,s=0,ts=0,t=0;
    };
    void addtag(Seg &s,int v) {
        s.ts=(s.ts+2*v*s.s+v*v*s.len)%mod;
        s.s=(s.s+v*s.len)%mod;
        s.t=(s.t+v)%mod;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=0;
    }
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.len=b.len+c.len;
        a.s=(b.s+c.s)%mod;
        a.ts=(b.ts+c.ts)%mod;
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    int n;
    vector<Seg> s;
    int ttt=0;
    void build(int w,int l,int r,Vi &ps,int __=0) {
        // op(w)op(l)op(r)ope(__)ope(ttt)
        // if(ttt++>10) exit(0);
        if(l==r) {
            s[w].s=ps[l];
            s[w].ts=(ps[l]*ps[l])%mod;
            s[w].t=0;
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,ps,__+1);
        build(w<<1|1,m+1,r,ps,__+1);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,Vi &ps) {
        // ttt=0;
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,ps);
    }
    void _ud(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _ud(w<<1,l,m,ql,qr,v);
        _ud(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int l,int r,int v) {
        _ud(1,0,n-1,l,r,v);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return {0,0,0,0};
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    pii qu(int l,int r) {
        Seg ret=_qu(1,0,n-1,l,r);
        return {ret.s,ret.ts};
    }
};
int f(int x) {
    if(x<0) x=-x;
    return (x>>1)*(x+1>>1); 
}
int updv(int s,int d,int n,int k) {
    int k1=k>>1;
    return (s+k1*d+(k1-1)*k1*n)%mod;
}
void solve() {
    int n,q;
    cin>>n>>q;
    ope(n)ope(q)
    string s;
    cin>>s;
    ope(s)
    Vi ps(n);
    ps[0]=s[0]=='1'?1:-1;
    REP1(i,n-1) ps[i]=ps[i-1]+(s[i]=='1'?1:-1);
    SEG seg;
    seg.init(n,ps);
    Vi psum(n),pds(n);
    REP(i,n) {
        psum[i]=((i?psum[i-1]:0)+f(ps[i]))%mod;
        pds[i]=(i?pds[i-1]:0)+f(ps[i]+2)-f(ps[i]);
    }
    oparr(ps)
    oparr(psum)
    oparr(pds)
    int an=0;
    REP1(i,n-1) {
        addmod(an,updv(psum[i-1],pds[i-1],i,-ps[i]));
        ope(an)
    }
    ope(an)
    REP(i,q) {
        int x;
        cin>>x;
    }
    ope("ok")
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}

/*
1
3 2
010
1
3
*/