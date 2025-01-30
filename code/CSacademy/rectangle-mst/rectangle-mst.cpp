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
struct DSU {
    int n,cc,an;
    Vi p,sz;
    void init(int _n) {
        n=_n;
        cc=n;
        an=0;
        p=Vi(n);
        sz=Vi(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b,int w) {
        op(a)op(b)ope(w)oparr(p)
        int x=find(a),y=find(b);
        if(x==y) return ;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        cc--;
        an+=w;
    }
};
struct SEG {
    struct Seg {
        int sum,mp,mid,mid2;
        bool operator==(Seg b) { return sum==b.sum; }
    };
    const Seg zero={inf,inf};

    int n;
    vector<Seg> s;
    Vi gp;
    bool sg(int a,int b) { return gp[a]==gp[b]; }

    Seg merge(Seg b,Seg c) {
        if(b==zero) return c;
        if(c==zero) return b;
        Seg a;
        a.sum=b.sum+c.sum;
        a.mp=min(b.mp,b.sum+c.mp);
        if(a.mp==b.mp) {
            a.mid=b.mid;
            if(b.mid2!=-1) a.mid2=b.mid2;
            else if(!sg(b.mid,c.mid)) a.mid2=c.mid;
            else a.mid2=c.mid2;
        }
        else {
            a.mid=c.mid;
            if(c.mid2!=-1)a.mid2=c.mid2;
            else if(!sg(a.mid,b.mid))a.mid2=b.mid;
            else a.mid2=b.mid2;
        }
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }

    void build(int w,int l,int r) {
        s[w]={0,0,l,l==r?-1:l+1};
        if(l==r) return;
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
    }
    void init(int _n,Vi _gp) {
        n=_n;
        gp=_gp;
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w].sum+=v;
            s[w].mp+=v;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    // Seg _qu(int w,int l,int r,int ql,int qr) {
    //     if(ql<=l&&r<=qr) return s[w];
    //     if(ql>r||qr<l) return zero;
    //     int m=l+r>>1;
    //     return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    // }
    pii qu(int u) {//return {v,w}
        // Seg ret=_qu(1,0,n-1,l,r);
        Seg ret=s[1];
        if(!sg(u,ret.mid)) return {ret.mid,ret.mp};
        return {ret.mid2,ret.mp};
    }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    struct qur {
        int l,r,w;
    };
    vector<vector<qur>> qu(n+1);
    auto adqu=[&](int x1,int x2,int y1,int y2,int w) {
        qu[x1].pb({y1,y2,w});
        qu[x2+1].pb({y1,y2,-w});
    };
    // REP(i,n) adqu(i,i,i,i,inf);
    REP(i,m) {
        int x1,x2,y1,y2,w;
        cin>>x1>>x2>>y1>>y2>>w,x1--,x2--,y1--,y2--;
        adqu(x1,x2,y1,y2,w);
        adqu(y1,y2,x1,x2,w);
    }
    DSU dsu;
    dsu.init(n);
    while(dsu.cc>1) {
        ope(dsu.cc)
        Vi gp(n);
        REP(i,n) gp[i]=dsu.find(i);
        SEG seg;
        seg.init(n+1,gp);
        auto opqu=[&](qur oo)->void {
            seg.ud(oo.l,oo.w);
            seg.ud(oo.r+1,-oo.w);
        };
        REP(i,n) {
            for(auto oo:qu[i]) opqu(oo);
            pii ret=seg.qu(i);
            op(i)ope(ret.f)
            if(ret.f!=-1) dsu.merge(i,ret.f,ret.s);
        }
    }
    cout<<dsu.an<<'\n';
    return 0;
}