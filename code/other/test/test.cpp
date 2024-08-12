#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

struct SEG {
    struct Seg {
        int v,mx,mn;
    };
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.mx=max(b.mx,c.mx);
        a.mn=min(b.mn,c.mn);
        a.v=max({b.v,c.v,b.mx-c.mn});
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    vector<Seg> s;
    int n;
    void build(int w,int l,int r) {
        if(l==r) {
            s[w]={-inf,0,0};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
    }
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w]={-inf,v,v};
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
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return {-inf,-inf,inf};
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r).v;
    }
}seg;
int MA(int a,int b) { int c=a+b;if(c>mod) c-=mod;return c; }
int MM(int a,int b) { int c=a-b;if(c<0) c+=mod;return c; }
int MU(int a,int b) { int c=0; if(a<b) swap(a,b); while(b>0) { if(b&1) c=MA(c,a); a=MA(a,a); b>>=1;} return c;}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=MU(r,x);
        x=MU(x,x);
        p>>=1;
    }
    return r;
}
void f(vector<int>&v,int l,int k) {
    if(k==1) return;
    vector<int> t(k);
    REP(i,k>>1) t[i]=v[l+(i<<1)];
    REP(i,k>>1) t[i+(k>>1)]=v[l+(i<<1)+1];
    REP(i,k) v[l+i]=t[i];
    int m=l+(k>>1);
    f(v,l,k>>1),f(v,l+(k>>1),k>>1);
}
signed main() {
    IOS();
    vector<int> v;
    int n;
    while(cin>>n) {
        v.clear();
        int N=1<<n;
        REP(i,N) v.pb(i);
        f(v,0,N);
        oparr(v)
        vector<int> t(N);
        REP(i,N) t[i]=(t[i>>1]>>1)|((i&1)<<n-1);
        vector<int> v2(N);REP(i,N) v2[i]=i;
        REP(i,N) if(i<t[i]) swap(v2[i],v2[t[i]]);
        oparr(v2)
    }
    // int n,q;
    // cin>>n>>q;
    // seg.init(n);
    // REP(i,q) {
    //     int opt;
    //     cin>>opt;
    //     if(opt==1) {
    //         int u,v;
    //         cin>>u>>v;
    //         u--;
    //         seg.ud(u,v);
    //     }
    //     if(opt==2) {
    //         int l,r;
    //         cin>>l>>r,l--,r--;
    //         cout<<seg.qu(l,r)<<'\n';
    //     }
    // }
    return 0;
}
/*
5 4
1 1 5
2 1 4
1 2 10
2 1 2
*/