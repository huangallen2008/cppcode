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
const int inf=(1<<25);
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
Vi pw2(maxn);
struct SEG {
    struct Tag {
        int mx,mn;
    };
    struct Seg {
        int len,mx,mn,smx,smn,s,val;
        Tag t;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mx=max(b.mx,c.mx);
        a.mn=max(b.mn,c.mn);
        a.smx=b.smx+c.smx;
        a.smn=b.smn+c.smn;
        a.s=b.s+c.s;
    }
    void addtag(Seg &a,Tag t) {
        if(t.mx!=-1) {
            a.mx=t.mx;
            a.smx=t.mx*a.len*a.val;
        }
        if(t.mn!=-1) {
            a.mn=t.mn;
            a.smn=t.mn*a.len*a.val;
        }
        if(t.mx!=-1) a.s=t.mx*a.smn;
        else if(t.mn!=-1) a.s=t.mn*a.smx;
        a.t.mx=t.mx;
        a.t.mn=t.mn;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.t);
        addtag(c,a.t);
        a.t={-1,-1};
    }
    int n;
    vector<Seg> s;
    void build(int w,int l,int r) {
        s[w]={r-l+1,-inf,inf,-inf,inf,0,0,{-1,-1}};
        if(l==r) {
            s[w].val=pw2[n-l];
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
        s[w].val=s[w<<1].val+s[w<<1|1].val;
    }
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void _ud(int w,int l,int r,int ql,int qr,Tag t) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],t);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _ud(w<<1,l,m,ql,qr,t);
        _ud(w<<1|1,m+1,r,ql,qr,t);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud_mx(int l,int r,int v) {
        _ud(1,0,n-1,l,r,{v,-1});
    }
    void ud_mn(int l,int r,int v) {
        _ud(1,0,n-1,l,r,{-1,v});
    }
    int _qu_mx(int w,int l,int r,int v) {
        if(l==r) return l;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        if(s[w<<1].mn<v) return _qu_mx(w<<1,l,m,v);
        else return _qu_mx(w<<1|1,m+1,r,v);
    }
    int qu_mx(int v) {
        return _qu_mx(1,0,n-1,v);
    }
    int _qu_mn(int w,int l,int r,int v) {
        if(l==r) return l;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        if(s[w<<1].mx>v) return _qu_mn(w<<1,l,m,v);
        else return _qu_mn(w<<1|1,m+1,r,v);
    }
    int qu_mn(int v) {
        return _qu_mn(1,0,n-1,v);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].s;
        if(ql>r||qr<l) return 0;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return _qu(w<<1,l,m,ql,qr)+_qu(w<<1|1,m+1,r,ql,qr);
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
}seg;
signed main() {
    IOS(); 
    pw2[0]=1;
    REP1(i,maxn-1) pw2[i]=pw2[i-1]*i%mod;
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    seg.init(n);
    vector<pii> mx,mn; 
    mx.pb({inf,-1});
    mn.pb({-inf,-1});
    int an=0;
    REP1(i,n-2) {
        while(mx.back().f<a[i]) mx.pop_back();
        while(mn.back().f>a[i]) mn.pop_back();
        seg.ud_mx(mx.back().s+1,i,a[i]);
        seg.ud_mn(mn.back().s+1,i,a[i]);
        an+=seg.qu(0,i);
    }
    cout<<an<<'\n';
    return 0;
}