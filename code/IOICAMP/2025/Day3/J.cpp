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
const int mod=1234567891;
const int P=989898989;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int v3=0,v4=0,ta=-1,tx=0,a1,an,len; 
        bool operator==(Seg x) {
            return x.v3==v3&&x.v4==v4&&x.ta==ta&&x.tx==tx&&x.a1==a1&&x.an==an&&x.len==len;
        }
    };
    const Seg zero={inf,inf,inf,inf,inf,inf,inf};
    void addtaga(Seg &a,int ta) {
        if(ta==-1) return;
        a.v3=a.len&1?ta:0;
        a.v4=0;
        a.ta=ta;
        a.tx=0;
        a.a1=a.an=ta;
    }
    void addtagx(Seg &a,int x) {
        a.v3^=a.len&1?x:0;
        //a.v4
        if(a.ta==-1) a.tx^=x;
        else a.ta^=x;
        a.a1^=x,a.an^=x;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.ta==-1) {
            addtagx(b,a.tx);
            addtagx(c,a.tx);
        }else {
            addtaga(b,a.ta);
            addtaga(c,a.ta);
        }
        a.ta=-1,a.tx=0;
    }
    Seg merge(Seg b,Seg c) {
        if(b==zero) return c;
        if(c==zero) return b;
        Seg a;
        a.len=b.len+c.len;
        a.v3=b.v3^c.v3;
        a.v4=b.v4+c.v4+(b.an^c.a1);
        a.a1=b.a1;
        a.an=c.an;
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    vector<Seg> s;
    int n;
    void build(int w,int l,int r) {
        s[w]={0,0,-1,0,0,0,r-l+1};
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
    void _uda(int w,int l,int r,int ql,int qr,int v){ 
        if(ql<=l&&r<=qr) {
            addtaga(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _uda(w<<1,l,m,ql,qr,v);
        _uda(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void uda(int l,int r,int v) {
        _uda(1,0,n-1,l,r,v);
    }
    void _udx(int w,int l,int r,int ql,int qr,int v){ 
        if(ql<=l&&r<=qr) {
            addtagx(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _udx(w<<1,l,m,ql,qr,v);
        _udx(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void udx(int l,int r,int v) {
        _udx(1,0,n-1,l,r,v);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        op(w)op(l)op(r)ope(s[w].v4)
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return zero;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int q3(int l,int r) { return _qu(1,0,n-1,l,r).v3; }
    int q4(int l,int r) { return _qu(1,0,n-1,l,r).v4; }
    int vv4() { return s[1].an^s[1].a1; }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    seg.init(n);
    Vi a(n);
    REP(i,n) cin>>a[i];
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,v;
            cin>>l>>r>>v,l--,r--;
            if(l<r) seg.uda(l,r,v);
            else {
                seg.uda(l,n-1,v);
                seg.uda(0,r,v);
            }
        }
        if(opt==2) {
            int l,r,v;
            cin>>l>>r>>v,l--,r--;
            if(l<r)seg.udx(l,r,v);
            else {
                seg.udx(l,n-1,v);
                seg.udx(0,r,v);
            }
        }
        if(opt==3) {
            int l,r;
            cin>>l>>r,l--,r--;
            int an=0;
            if(l<r) an=seg.q3(l,r);
            else an=seg.q3(l,n-1)^seg.q3(1,r);
            cout<<an<<'\n';
        }
        if(opt==4) {
            int l,r;
            cin>>l>>r,l--,r--;
            int an=0;
            if(l<r) an=seg.q4(l,r);
            else {
                an=seg.q4(l,n-1)+seg.q4(0,r)+seg.vv4();
            }
            cout<<an<<'\n';
        }
        ope(seg.vv4())
    }
    return 0;
}