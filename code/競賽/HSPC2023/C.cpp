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
        int v,s,c;
    };
    void addtag(Seg &a,Seg b) {
        a.v+=b.v+b.s*a.c;
        a.s+=b.s;
        a.c+=b.c;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a);
        addtag(c,a);
        a={0,0,0};
    }
    vector<Seg> s;
    vector<int> an;
    int n;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
        an=vector<int>(n);
    }
    void _ud(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],{v,v,1});
            return;
        }
        if(ql>r||qr<l) return;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        _ud(w<<1,l,m,ql,qr,v);
        _ud(w<<1|1,m+1,r,ql,qr,v);
    }
    void ud(int l,int r,int v) {
        _ud(1,0,n-1,l,r,v);
    }
    void _apush(int w,int l,int r) {
        if(l==r) {
            an[l]=s[w].v;
            return;
        }
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        _apush(w<<1,l,m);
        _apush(w<<1|1,m+1,r);
    }
    void apush() {
        _apush(1,0,n-1);
    }
}seg;
struct mon {
    int x,r,k;
};
bool so_mon(mon a,mon b) {
    return a.x<b.x;
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<mon> mo(n);
    REP(i,n) cin>>mo[i].x>>mo[i].r>>mo[i].k;
    sort(ALL(mo),so_mon);
    vector<pii> y(m);
    REP(i,m) cin>>y[i].f,y[i].s=i;
    sort(ALL(y));
    seg.init(m);
    REP(i,n) {
        int l=lower_bound(ALL(y),make_pair(mo[i].x-mo[i].r,-inf))-y.begin();
        int r=lower_bound(ALL(y),make_pair(mo[i].x+mo[i].r,inf))-y.begin()-1;
        seg.ud(l,r,mo[i].k);
    }
    seg.apush();
    vector<int> an(m);
    REP(i,m) an[y[i].s]=seg.an[i];
    REP(i,m) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}