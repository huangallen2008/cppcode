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
const int mod=998244353;
const int maxn=1e4+5;
const int maxb=18;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int len,s,t;
    };
    void addtag(Seg &a,int t) {
        a.t+=t;
        a.s+=a.len*t;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.s=b.s+c.s;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=0;
    }
    vector<Seg> s;
    int n;
    void build(int w,int l,int r,vector<int>&a) {
        s[w].len=r-l+1;
        if(l==r) {
            s[w].s=a[l];
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
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].s;
        if(ql>r||qr<l) return 0;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        return _qu(w<<1,l,m,ql,qr)+_qu(w<<1|1,m+1,r,ql,qr);
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    seg.init(n,a);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int x,y,k;
            cin>>x>>y>>k,x--,y--;
            seg.ud(x,y,k);
        }
        else {
            int l,r;
            cin>>l>>r,l--,r--;
            cout<<seg.qu(l,r)<<'\n';
        }
    }
    return 0;
}