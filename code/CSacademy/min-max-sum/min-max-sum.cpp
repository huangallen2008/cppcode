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
const int maxn=1e5+5;
const int maxx=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
const int inv2=inv(2);
struct SEG {
    struct Seg {
        int s,t;
    };
    void addtag(Seg &a,int t) {
        (a.s*=t)%=mod;
        (a.t*=t)%=mod;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=1;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.s=(b.s+c.s)%mod;
    }
    vector<Seg> s;
    int n;
    void build(int w,int l,int r) {
        s[w]={r-l+1,1};
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
    int sum() { return s[1].s; }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].s;
        if(ql>r||qr<l) return 0;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return (_qu(w<<1,l,m,ql,qr)+_qu(w<<1|1,m+1,r,ql,qr))%mod;
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
}seg;
signed main() {
    IOS(); 
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    int mxe=*max_element(ALL(a)),mne=*min_element(ALL(a));
    int an=mxe*mne%mod;
    {
        int px=-inf,pn=inf;
        REP(i,n-1) {
            chmin(pn,a[i]);
            chmax(px,a[i]);
            (an+=(pn*px%mod)*pw(2,n-i-2))%=mod;
        }
    }
    {
        int px=-inf,pn=inf;
        RREP1(i,n-1) {
            chmin(pn,a[i]);
            chmax(px,a[i]);
            (an+=(pn*px%mod)*pw(2,i-1))%=mod;
        }
    }
    seg.init(n);
    vector<pii> mx,mn; 
    mx.pb({inf,0});
    mn.pb({-inf,0});
    seg.ud(0,n-1,pw(2,n-3));
    seg.ud(0,0,0);
    seg.ud(n-1,n-1,0);
    REP1(i,n-2) {
        ope(i)
        while(mx.back().f<=a[i]) {
            seg.ud(mx[mx.size()-2].s+1,mx.back().s,a[i]*inv(mx.back().f)%mod );
            mx.pop_back();
        }
        while(mn.back().f>=a[i]) {
            seg.ud(mn[mn.size()-2].s+1,mn.back().s,a[i]*inv(mn.back().f)%mod );
            mn.pop_back();
        }
        seg.ud(i,i,a[i]*a[i]%mod);
        mx.pb({a[i],i});
        mn.pb({a[i],i});
        // REP(j,n) cout<<seg.qu(j,j)<<' ';entr
        (an+=seg.qu(1,i))%=mod;
        // ope(seg.qu())
        seg.ud(0,i,inv2);
    }
    cout<<an<<'\n';
    entr
    return 0;
}