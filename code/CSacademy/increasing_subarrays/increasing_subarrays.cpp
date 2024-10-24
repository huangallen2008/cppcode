#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define iint int32_t
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
const int maxn=100+5;
const int maxx=2e5+5;
const int inf=(1<<25);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int sum;
        iint len;
        int t;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.sum=b.sum+c.sum;
    }
    void addtag(Seg &a,int t) {
        a.sum=t*a.len;
        a.t=t;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t!=-1) {
            addtag(b,a.t);
            addtag(c,a.t);
            a.t=-1;
        }
    }
    int n;
    vector<Seg> s;
    void build(int w,int l,int r,Vi &a) {
        s[w].len=r-l+1;
        s[w].t=-1;
        if(l==r) {
            s[w].sum=a[l];
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,Vi &a) {
        n=_n;
        s=vector<Seg>(n*3.6);
        build(1,1,n,a);
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
        _ud(1,1,n,l,r,v);
    }
    int _qu(int w,int l,int r,int k,Vi &p) {
        if(l==r) return r+(s[w].sum-p[r]+p[l-1]<=k);
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        // op(l)op(r)op(s[w<<1].sum)op(p[m]-p[l-1])ope(k)
        if(s[w<<1].sum-(p[m]-p[l-1])>k) return _qu(w<<1,l,m,k,p);
        else return _qu(w<<1|1,m+1,r,k-s[w<<1].sum+(p[m]-p[l-1]),p);
    }
    int qu(int k,Vi &p) {
        return _qu(1,1,n,k,p);
    }
}seg;
struct SEG2 {
    int n;
    Vi s;
    void init(int _n) {
        n=_n;
        s=Vi(n*3.6);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w]=v;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        s[w]=max(s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    int _qu(int w,int l,int r,int k) {
        if(l==r) return l;
        int m=l+r>>1;
        if(s[w<<1]>=k) return _qu(w<<1,l,m,k);
        else return _qu(w<<1|1,m+1,r,k);
    }
    int qu(int k) {
        return _qu(1,0,n-1,k);
    }
}seg2;
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    Vi a(n+1);
    REP1(i,n) cin>>a[i];
    seg.init(n,a);
    REP1(i,n) a[i]+=a[i-1];
    seg2.init(n+2);seg2.ud(n+1,inf);
    int an=0;
    RREP1(i,n) {
        int ret=seg2.qu(a[i]-a[i-1]);
        seg.ud(i,ret-1,a[i]-a[i-1]);
        // op(i)op(ret-1)ope(a[i])
        an+=seg.qu(m,a)-i;
        // op(i)ope(seg.qu(m))
        seg2.ud(i,a[i]-a[i-1]);
    }
    cout<<an<<'\n';
    return 0;
}