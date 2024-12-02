#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define piii pair<pii,int>
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// struct SEG {
//     struct Seg {
//         int v1,v2,mv;
//     }zr={-inf,inf,-inf};
//     Seg merge(Seg b,Seg c) {
//         Seg a;
//         a.v1=max(b.v1,c.v1);
//         a.v2=min(b.v2,c.v2);
//         a.mv=max({b.mv,c.mv,c.v1-b.v2});
//         return a;
//     }
//     void pull(Seg &a,Seg &b,Seg &c) {
//         a=merge(b,c);
//     }
//     vector<Seg> s;
//     int n;
//     void init(int _n) {
//         n=_n;
//         s=vector<Seg>(n<<2);
//     }
//     void _ud(int w,int l,int r,int u,pii v) {
//         if(l==r) {
//             s[w].v1=v.f;
//             s[w].v2=v.s;
//             return;
//         }
//         int m=l+r>>1;
//         if(u<=m) _ud(w<<1,l,m,u,v);
//         else _ud(w<<1|1,m+1,r,u,v);
//         pull(s[w],s[w<<1],s[w<<1|1]);
//     }
//     void ud(int u,pii v) {
//         _ud(1,0,n-1,u,v);
//     }
//     Seg _qu(int w,int l,int r,int ql,int qr) {
//         if(ql<=l&&r<=qr) return s[w];
//         if(ql>r||qr<l) return zr;
//         int m=l+r>>1;
//         return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
//     }
//     int qu(int l,int r) {
//         return _qu(1,0,n-1,l,r).mv;
//     }
// }seg;
struct SEG {
    struct Seg {
        int mp,ms,ma,sum;
    }zr={-inf,-inf,-inf,0};
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.mp=max(b.mp,b.sum+c.mp);
        a.ms=max(c.sum+b.ms,c.ms);
        a.ma=max({b.ma,c.ma,b.ms+c.mp});
        a.sum=b.sum+c.sum;
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    vector<Seg> s;
    int n;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
    }
    void _ud(int w,int l,int r,int u,pii v) {
        if(l==r) {
            s[w].mp=v.f+v.s;
            s[w].ms=v.f+v.s;
            s[w].ma=v.f+v.s*2;
            s[w].sum=v.f;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int u,pii v) {
        _ud(1,0,n-1,u,v);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return zr;
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r).ma;
    }
}seg;
struct BIT {
    Vi b;
    int n;
    void init(int _n) {
        n=_n;
        b=Vi(n);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) { return pre(r)-pre(l-1); }
}pa;
void solve() {
    int n;
    cin>>n;
    Vi a(n+1),b(n+1);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    seg.init(n);
    REP1(i,n) seg.ud(i,{a[i],b[i]});
    int q;
    cin>>q;
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int p,v;
            cin>>p>>v,p--;
            a[p]=v;
            seg.ud(p,{a[p],b[p]});
        }else if(opt==2) {
            int p,v;
            cin>>p>>v,p--;
            b[p]=v;
            seg.ud(p,{a[p],b[p]});
        }else {
            int l,r;
            cin>>l>>r,l--,r--;
            cout<<seg.qu(l,r)<<'\n';
        }
        REP(j,20) cout<<seg.s[j].ma<<' ';entr
    }
}
signed main() {
    IOS();
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}