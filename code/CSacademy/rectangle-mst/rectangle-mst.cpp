#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
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
struct edge {
    int u,v,w;
};
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
        int x=find(a),y=find(b);
        if(x==y) return ;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        cc--;
        an+=w;
    }
    void merge(edge x) {
        merge(x.u,x.v,x.w);
    }
};
struct SEG {
    struct Seg {
        int sum;
        pii mn,mn2;
    };
    // const Seg zero={inf};

    int n;
    vector<Seg> s;
    Vi gp;
    bool sg(int a,int b) { return gp[a]==gp[b]; }
    void pull(Seg &a,Seg b,Seg c) {
        a.sum=b.sum+c.sum;
        c.mn.f+=b.sum,c.mn2.f+=b.sum;
        a.mn=min(b.mn,c.mn);
        if(b.mn>c.mn) swap(b,c);
        a.mn=b.mn;
        if(gp[b.mn.s]==gp[c.mn.s]) a.mn2=min(b.mn2,c.mn2);
        else a.mn2=min(b.mn2,c.mn);
    }

    void build(int w,int l,int r) {
        if(l==r) {
            s[w].sum=0;
            s[w].mn={0,l};
            s[w].mn2={inf,-1};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,Vi &_gp) {
        n=_n;
        gp=_gp;
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w].sum+=v;
            s[w].mn.f=s[w].sum;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        if(u>=n) return;
        _ud(1,0,n-1,u,v);
    }
    pii qu(int u) {//return {v,w}
        Seg ret=s[1];
        if(gp[u]!=gp[ret.mn.s]) return ret.mn;
        return ret.mn2;
    }
};
signed main() {
    IOS();
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    #endif
    int n=read(),m=read();
    // cin>>n>>m;
    struct qur {
        int l,r,w;
    };
    vector<vector<qur>> qu(n+1);
    REP(i,m) {
        int x1=read()-1,x2=read()-1,y1=read()-1,y2=read()-1,w=read();
        // cin>>x1>>x2>>y1>>y2>>w,x1--,x2--,y1--,y2--;
        qu[x1].pb({y1,y2,w});
        qu[x2+1].pb({y1,y2,-w});
        qu[y1].pb({x1,x2,w});
        qu[y2+1].pb({x1,x2,-w});
    }
    DSU dsu;
    dsu.init(n);
    while(dsu.cc>1) {
        Vi gp(n);
        REP(i,n) gp[i]=dsu.find(i);
        SEG seg;
        seg.init(n,gp);
        vector<pii> add(n,{inf,-1});
        REP(i,n) {
            for(auto &oo:qu[i]) {
                seg.ud(oo.l,oo.w);
                seg.ud(oo.r+1,-oo.w);
            }
            chmin(add[gp[i]],seg.qu(i));
        }
        REP(i,n) if(add[i].s!=-1) {
            dsu.merge(i,add[i].s,add[i].f);
        }
    }
    cout<<dsu.an<<'\n';
    return 0;
}