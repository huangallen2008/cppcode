#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=998244353;
const int maxn=1e7+5;
const int maxv=1e9+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int s[maxn]={inf};
iint lc[maxn];
iint rc[maxn];
int node_id=1;
struct SEG {
    iint root;
    int n;
    void pull(int w) {
        s[w]=min(s[lc[w]],s[rc[w]]);
    }
    void init(int _n) {
        n=_n;
        root=node_id++;
        s[root]=inf;
    }
    void _ud(iint &w,int l,int r,int u,int v) {
        if(!w) w=node_id++,s[w]=inf;
        if(l==r) {
            s[w]=v;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(lc[w],l,m,u,v);
        else _ud(rc[w],m+1,r,u,v);
        pull(w);
    }
    void ud(int u,int v) {
        _ud(root,0,n-1,u,v);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(!w) return inf;
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return inf;
        int m=l+r>>1;
        return min(_qu(lc[w],l,m,ql,qr),_qu(rc[w],m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(root,0,n-1,l,r);
    }
}seg1,seg2;
signed main() {
    IOS();
    seg1.init(maxv);//-a[j]
    seg2.init(maxv);//+a[j]
    int k,n;
    cin>>k>>n;
    vector<pii> a(n+1);
    REP1(i,n) cin>>a[i].f>>a[i].s;
    if(k==1) {
        int an=0;
        REP1(i,n) an+=abs(a[i].f-a[i-1].s)+abs(a[i].f-a[i].s);
        cout<<an<<'\n';
        return 0;
    }
    Vi p(n+1);
    REP1(i,n) p[i]=p[i-1]+abs(a[i].f-a[i-1].s);
    vector<int> dp(n+1);
    seg1.ud(0,-p[1]);
    seg2.ud(0,-p[1]);
    REP1(i,n-1) {
        dp[i]=min(p[i]+a[i+1].f+seg1.qu(0,a[i+1].f),p[i]-a[i+1].f+seg2.qu(a[i+1].f,maxv-1));
        seg1.ud(a[i].s,dp[i]-p[i+1]-a[i].s);
        seg2.ud(a[i].s,dp[i]-p[i+1]+a[i].s);
    }
    // oparr(dp)oparr(p)
    int an=inf;
    REP(i,n) chmin(an,dp[i]+p[n]-p[i+1]);
    int base=abs(a[1].f);
    REP1(i,n) base+=abs(a[i].f-a[i].s);
    an+=base;
    cout<<an<<'\n';
    return 0;
} 