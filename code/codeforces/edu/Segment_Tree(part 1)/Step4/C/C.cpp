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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int inv=0;
        vector<int> c;
        Seg() {
            c=vector<int>(41);
        }
    }zero;
    Seg merge(Seg b,Seg c) {
        Seg a;
        REP1(i,40) a.c[i]=b.c[i]+c.c[i];
        a.inv=b.inv+c.inv;
        int s=0;
        REP1(i,40) {
            a.inv+=s*b.c[i];
            s+=c.c[i];
        }
        return a;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    vector<Seg> s;
    vector<int> a;
    void build(int w,int l,int r) {
        if(l==r) {
            s[w].c[a[l]]++;
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
        push(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int n,vector<int> &_a) {
        a=_a;
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w].c[a[l]]--;
            a[l]=v;
            s[w].c[a[l]]++;
            return;
        }
        int m=l+r>>1;
        if(u<=m) ud(w<<1,l,m,u,v);
        else ud(w<<1|1,m+1,r,u,v);
        push(s[w],s[w<<1],s[w<<1|1]);
    }
    Seg qu0(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return zero;
        int m=l+r>>1;
        return merge(qu0(w<<1,l,m,ql,qr),qu0(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int w,int l,int r,int ql,int qr) {
        return qu0(w,l,r,ql,qr).inv;
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    seg.init(n,a);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<seg.qu(1,0,n-1,l,r)<<'\n';
        }
        else {
            int u,v;
            cin>>u>>v;
            u--;
            seg.ud(1,0,n-1,u,v);
        }
    }
    return 0;
}