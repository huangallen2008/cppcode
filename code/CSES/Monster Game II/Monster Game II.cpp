#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=255;
const int maxv=1e5+5;
const int maxs=1e6;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct LCSEG {
    struct line {
        int m,k;
    };
    int cal(line l,int x) {
        return l.m*x+l.k;
    }
    line mnl(line a,line b,int x) {
        if(cal(a,x)<cal(b,x)) return a;
        else return b;
    }
    vector<line> s;
    void init(int n) {
        s=vector<line>(n<<2,{0,inf});
    }
    void ud(int w,int l,int r,line v) {
        if(l==r) {
            s[w]=mnl(s[w],v,l);
            return;
        }
        int m=l+r>>1;
        line l1=v,l2=s[w];
        if(l1.m>l2.m) swap(l1,l2);
        int v1=cal(l1,m),v2=cal(l2,m);
        if(v1<v2) {
            s[w]=l1;
            ud(w<<1,l,m,l2);
        }
        else {
            s[w]=l2;
            ud(w<<1|1,m+1,r,l1);
        }
    }
    int qu(int w,int l,int r,int x) {
        int an=cal(s[w],x);
        if(l==r) return an;
        int m=l+r>>1;
        if(x<=m) return min(an,qu(w<<1,l,m,x));
        else return min(an,qu(w<<1|1,m+1,r,x));
    }
} lcseg;
int solve(vector<pii> &a) {
    lcseg.init(maxs);
    vector<int> dp(a.size());
    lcseg.ud(1,0,maxs-1,{a[0].f,dp[0]});
    for(int i=1;i<a.size();i++) {
        dp[i]=lcseg.qu(1,0,maxs-1,a[i].s);
        lcseg.ud(1,0,maxs-1,{a[i].f,dp[i]});
    }
    return dp[a.size()-1];
}
bool so(pii a,pii b) {
    return a.f>b.f;
}
signed main() {
    IOS();
    int n,x;
    cin>>n>>x;
    vector<pii> a(n+1),na;
    a[0].f=x;
    REP1(i,n) cin>>a[i].s;
    REP1(i,n) cin>>a[i].f;
    a[n].f=0;
    na.pb(a[0]);
    REP1(i,n-1) if(a[i].s<a[n].s&&a[i].f<x) na.pb(a[i]);
    na.pb(a[n]);
    cout<<solve(a)<<'\n';
    return 0;
}
