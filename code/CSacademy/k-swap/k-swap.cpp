#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int mn,t;
    };
    void addtag(Seg &a,int t) {
        a.mn+=t;
        a.t+=t;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=0;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mn=min(b.mn,c.mn);
    }
    vector<Seg> s;
    int n;
    void build(int w,int l,int r,vector<pii> &a) {
        if(l==r) {
            s[w].mn=a[l].s;
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,vector<pii> &a) {
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
    int _qu(int w,int l,int r) {
        if(l==r) return r;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        if(s[w<<1].mn==0) return _qu(w<<1,l,m);
        else return _qu(w<<1|1,m+1,r);
    }
    int qu() {return _qu(1,0,n-1); }
}seg;
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) {
        return pre(r)-pre(l-1);
    }
}bit;
signed main() {
    IOS(); 
    int n,k;
    cin>>n>>k;
    Vi a(n);
    REP(i,n) cin>>a[i];
    bit.init(maxv);
    vector<pii> b(n);
    REP(i,n) {
        b[i]={a[i],i-bit.qu(max(0ll,a[i]-k),min(maxv-1,a[i]+k))};
        bit.ud(a[i],1);
    }
    sort(ALL(b));
    for(auto [x,y]:b) cout<<"{"<<x<<' '<<y<<"} ";entr
    seg.init(n,b);
    Vi an(n);
    REP(i,n) {
        int id=seg.qu();
        an[i]=b[id].f;
        int il=lower_bound(ALL(b),pii{id-k,-inf})-b.begin()-1;
        int ir=lower_bound(ALL(b),pii{id+k,inf})-b.begin();
        seg.ud(0,il,-1);
        seg.ud(ir,n-1,-1);
        seg.ud(id,id,inf);
    }
    REP(i,n) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}