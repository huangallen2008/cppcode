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
const int maxv=2e6+10;
// const int maxn=1e3+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
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
        if(u<=0) return 0;
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) {
        return pre(r)-pre(l-1);
    }
}bit;
// struct SEG {
//     struct Seg {
//         int mx,ta,tx;
//     };
//     void addtaga(Seg &a,int ta) {
//         a.mx+=ta;
//         a.ta+=ta;
//         a.tx+=ta;
//     }
//     void addtagx(Seg &a,int tx) {
//         chmax(a.mx,tx);
//         chmax(a.tx,tx);
//     }
//     void push(Seg &a,Seg &b,Seg &c) {
//         addtaga(b,a.ta);
//         addtagx(b,a.tx);
//         addtaga(c,a.ta);
//         addtagx(c,a.tx);
//         a.ta=0,a.tx=0;
//     }
//     void pull(Seg &a,Seg &b,Seg &c) {
//         a.mx=max(b.mx,c.mx);
//     }
//     int n;
//     vector<Seg> s;
//     void init(int _n) {
//         n=_n;
//         s=vector<Seg>(n<<2);
//     }
//     void _ud_x(int w,int l,int r,int ql,int qr,int v) {
//         if(ql<=l&&r<=qr) {
//             addtagx(s[w],v);
//             return;
//         }
//         if(ql>r||qr<l) return;
//         int m=l+r>>1;
//         push(s[w],s[w<<1],s[w<<1|1]);
//         _ud_x(w<<1,l,m,ql,qr,v);
//         _ud_x(w<<1|1,m+1,r,ql,qr,v);
//         pull(s[w],s[w<<1],s[w<<1|1]);
//     }
//     void ud_x(int l,int r,int v) {
//         _ud_x(1,0,n-1,l,r,v);
//     }void _ud_a(int w,int l,int r,int ql,int qr,int v) {
//         if(ql<=l&&r<=qr) {
//             addtaga(s[w],v);
//             return;
//         }
//         if(ql>r||qr<l) return;
//         int m=l+r>>1;
//         push(s[w],s[w<<1],s[w<<1|1]);
//         _ud_a(w<<1,l,m,ql,qr,v);
//         _ud_a(w<<1|1,m+1,r,ql,qr,v);
//         pull(s[w],s[w<<1],s[w<<1|1]);
//     }
//     void ud_a(int l,int r,int v) {
//         _ud_a(1,0,n-1,l,r,v);
//     }
//     int _qu(int w,int l,int r,int ql,int qr) {
//         if(ql<=l&&r<=qr) return s[w].mx;
//         if(ql<r||qr<l) return -inf;
//         int m=l+r>>1;
//         push(s[w],s[w<<1],s[w<<1|1]);
//         return max(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
//     }
//     int qu(int l,int r) {
//         return _qu(1,0,n-1,l,r);
//     }
// }seg;
struct SEG {
    struct Seg {
        int mx=-inf,ta;
    };
    void addtaga(Seg &a,int ta) {
        a.mx+=ta;
        a.ta+=ta;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtaga(b,a.ta);
        addtaga(c,a.ta);
        a.ta=0;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mx=max(b.mx,c.mx);
    }
    int n;
    vector<Seg> s;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
    }
    void _ud_x(int w,int l,int r,int u,int v) {
        if(l==r) {
            chmax(s[w].mx,v);
            return;
        }
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        if(u<=m)_ud_x(w<<1,l,m,u,v);
        else _ud_x(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud_x(int u,int v) {
        op("x")op(u)ope(v)
        _ud_x(1,0,n-1,u,v);
    }void _ud_a(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtaga(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _ud_a(w<<1,l,m,ql,qr,v);
        _ud_a(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud_a(int l,int r,int v) {
        op("a")op(l)op(r)ope(v)
        _ud_a(1,0,n-1,l,r,v);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].mx;
        if(ql>r||qr<l) return -inf;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return max(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
}seg;
signed main() {
    IOS();
    // #ifdef LOCAL
    //     seg.init(5);
    //     seg.ud_a(1,3,1);
    //     op(seg.qu(1,2))
    //     seg.ud_x(1,2);
    //     op(seg.qu(1,2))
    // #endif
    int n,d;
    cin>>n>>d;
    Vi a(n+1);
    Vi t;
    REP(i,n) cin>>a[i],t.pb(a[i]),t.pb(a[i]+d);
    a[n]=maxv;
    t.pb(a[n]),t.pb(a[n]+d);
    sort(ALL(t));
    Vi nxt(n+1);
    REP(i,n+1) {
        nxt[i]=lower_bound(ALL(t),a[i]+d)-t.begin()+1;
        a[i]=lower_bound(ALL(t),a[i])-t.begin()+1;
    }
    bit.init(maxv);
    // bit2.init(maxv);
    seg.init(maxv);
    Vi dp(n+1,1),mv(n+1);
    REP(i,n+1) {
        chmax(dp[i],seg.qu(0,a[i]-1)+1);
        mv[i]=dp[i];
        // bit.ud(a[i],1);
        seg.ud_a(a[i],a[i]+d,1);
        seg.ud_x(a[i],dp[i]);
    }
    // oparr(dp)oparr(mv)
    cout<<dp[n]-1<<'\n';
    return 0;
}