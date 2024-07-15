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
        int mcs=0,mp=0,ms=0,sum=0,len=0,t=-inf;
    };
    Seg zero={-1,-1,-1,-1,-1,-1};
    void addtag(Seg &a,int t) {
        a.sum=t*a.len;
        a.mp=a.ms=a.mcs=max(0ll,a.sum);
        a.t=t;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t==-inf) return;
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=-inf;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mp=max(b.mp,b.sum+c.mp);
        a.ms=max(c.ms,c.sum+b.ms);
        a.sum=b.sum+c.sum;
        a.mcs=max({b.mcs,c.mcs,b.ms+c.mp});
    }
    vector<Seg> s;
    void build(int w,int l,int r) {
        s[w]={0,0,0,0,r-l+1,-inf};
        if(l==r) return;
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
    }
    void init(int n) {
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void ud(int w,int l,int r,int ul,int ur,int v) {
        if(ul<=l&&r<=ur) {
            addtag(s[w],v);
            return;
        }
        if(ul>r||ur<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        ud(w<<1,l,m,ul,ur,v);
        ud(w<<1|1,m+1,r,ul,ur,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    int get_an() {
        return s[1].mcs;
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    seg.init(n);
    REP(i,q) {
        int l,r,v;
        cin>>l>>r>>v;
        seg.ud(1,0,n-1,l,r-1,v);
        cout<<seg.get_an()<<'\n';
    }
    return 0;
}