#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
// #define int long long
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
#ifdef LOCAL_
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
const int maxv=1e5+5;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define GC _getchar_nolock()
#define PC _putchar_nolock
#else 
#define GC getchar_unlocked()
#define PC putchar_unlocked
#endif
inline int read()
{
    int x=0;
    bool neg=0;
    char c=GC;
    while(c<'0'||c>'9'){if(c=='-') neg=1;c=GC;}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=GC;
    if(neg) x=-x;
    return x;
}
inline string reads()
{
    char c=GC;
    string s;
    while(c==' '||c=='\n')c=GC;
    while(c!=' '&&c!='\n'&&c!=EOF) s+=c,c=GC;
    return s;
}
inline void out(int x) {
    if(x<0) {
        PC('-');
        x=-x;
    }
    char str[18];
	auto it=str;
    do { 
        *it=x%10+'0',it++;
        x/=10;
    } while(x);
    for(it--;it>=str;it--) PC(*it);
    // PC('\n');
}
#define ss string
ss mx(ss a,ss b) {
    if(a.size()>b.size()) swap(a,b);
    REP(i,a.size()) chmax(b[i],a[i]);
    return b;
}
struct SEG {
    struct Seg {
        ss v,t1="0",t2="-1";
    };
    void addtag1(Seg &a,ss t1) {
        if(a.t2=="-1") {
            a.t1=mx(a.t1,t1);
            a.v=mx(a.v,t1);
        }else {
            a.t2=mx(a.t2,t1);
            a.v=mx(a.v,t1);
        }
    }
    void addtag2(Seg &a,ss t2) {
        a.t1="0";
        a.t2=a.v=t2;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.v=mx(b.v,c.v);
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t2=="-1") {
            addtag1(b,a.t1);
            addtag1(c,a.t1);
        }else {
            addtag2(b,a.t2);
            addtag2(c,a.t2);
        }
        a.t1="0",a.t2="-1";
    }
    int n;
    vector<Seg> s;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
    }
    void _ud1(int w,int l,int r,int ql,int qr,ss v) {
        // op(w)op(l)ope(r)
        if(ql<=l&&r<=qr) {
            addtag1(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _ud1(w<<1,l,m,ql,qr,v);
        _ud1(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud1(int l,int r,ss v) {
        op(l)ope(r)
        _ud1(1,0,n-1,l,r,v);
    }
    void _ud2(int w,int l,int r,int ql,int qr,ss v) {
        if(ql<=l&&r<=qr) {
            addtag2(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _ud2(w<<1,l,m,ql,qr,v);
        _ud2(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud2(int l,int r,ss v) {
        _ud2(1,0,n-1,l,r,v);
    }
    ss _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].v;
        if(ql>r||qr<l) return "0";
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return mx(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    ss qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
}seg;
signed main() {
    IOS();
    int n=read(),q=read();
    // cin>>n>>q;
    seg.init(n);
    vector<string> a(n);
    REP(i,n) a[i]=reads(),reverse(ALL(a[i]));
    REP(i,n) seg.ud1(i,i,a[i]);
    while(q--) {
        int opt=read();
        // cin>>opt;
        if(opt==1) {
            int l=read()-1,r=read()-1;
            // cin>>l>>r,l--,r--;
            ss an=seg.qu(l,r);
            // for(int i=l;i<=r;i++) an=mx(an,a[i]);
            reverse(ALL(an));
            // out(an);PC('\n');
            cout<<an<<'\n';
        }if(opt==2) {
            int l=read()-1,r=read()-1;
            string v=reads();
            // cin>>l>>r>>v,l--,r--;
            reverse(ALL(v));
            seg.ud1(l,r,v);
            // for(int i=l;i<=r;i++) a[i]=mx(a[i],v);
        }if(opt==3) {
            int l=read()-1,r=read()-1;
            string v=reads();
            // cin>>l>>r>>v,l--,r--;
            reverse(ALL(v));
            seg.ud2(l,r,v);
            // for(int i=l;i<=r;i++) a[i]=v;
        }
        // oparr(a)
    }
    return 0;
}