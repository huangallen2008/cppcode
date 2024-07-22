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
        int len,a=0,d=0;
    };
    void addtag(Seg &s,int a,int d) {
        s.a+=a;
        s.d+=d;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.a,a.d);
        addtag(c,a.a+a.d*b.len,a.d);
        a.a=0,a.d=0;
    }
    int n;
    vector<Seg> s;
    void build(int w,int l,int r) {
        s[w]={r-l+1,0,0};
        if(l==r) return;
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
    }
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void _ud(int w,int l,int r,int ql,int qr,int a,int d) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],a+(l-ql)*d,d);
            return;
        }
        if(ql>r||qr<l) return;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        _ud(w<<1,l,m,ql,qr,a,d);
        _ud(w<<1|1,m+1,r,ql,qr,a,d);
    }
    void ud(int l,int r,int a,int d) {
        _ud(1,0,n-1,l,r,a,d);
    }
    int _qu(int w,int l,int r,int u) {
        if(l==r) return s[w].a;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        if(u<=m) return _qu(w<<1,l,m,u);
        else return _qu(w<<1|1,m+1,r,u);
    }
    int qu(int u) {
        return _qu(1,0,n-1,u);
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
            int l,r,a,d;
            cin>>l>>r>>a>>d;
            l--,r--;
            seg.ud(l,r,a,d);
        }
        else {
            int u;
            cin>>u;
            u--;
            cout<<seg.qu(u)<<'\n';
        }
    }
    return 0;
}