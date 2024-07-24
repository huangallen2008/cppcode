#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int mn=0,mx=0;
    };
    void addtag(Seg &a,int mn,int mx) {
        chmin(a.mx,mn);
        chmax(a.mx,mx);
        chmin(a.mn,mn);
        chmax(a.mn,mx);
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.mn,a.mx);
        addtag(c,a.mn,a.mx);
        a.mn=inf,a.mx=0;
    }
    int n;
    vector<Seg> s;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
    }
    void _mn(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],v,0);
            return;
        }
        if(ql>r||qr<l) return;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        _mn(w<<1,l,m,ql,qr,v);
        _mn(w<<1|1,m+1,r,ql,qr,v);
    }
    void mn(int l,int r,int v) {
        _mn(1,0,n-1,l,r,v);
    }
    void _mx(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],inf,v);
            return;
        }
        if(ql>r||qr<l) return;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        _mx(w<<1,l,m,ql,qr,v);
        _mx(w<<1|1,m+1,r,ql,qr,v);
    }
    void mx(int l,int r,int v) {
        _mx(1,0,n-1,l,r,v);
    }
    void _qu(int w,int l,int r) {
        if(l==r) {
            cout<<s[w].mx<<'\n';
            return;
        }
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        _qu(w<<1,l,m);
        _qu(w<<1|1,m+1,r);
    }
    void qu() {
        return _qu(1,0,n-1);
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    seg.init(n);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,v;
            cin>>l>>r>>v;
            seg.mx(l,r,v);
        }
        else {
            int l,r,v;
            cin>>l>>r>>v;
            seg.mn(l,r,v);
        }
    }
    seg.qu();
    return 0;
}