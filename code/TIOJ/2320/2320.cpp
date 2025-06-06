#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int maxn=500+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int cl(vector<int>&v,int x) {
    auto it=lower_bound(ALL(v),x);
    if(*it-x>x-*prev(it)) return it-v.begin()-1;
    else it-v.begin();
}
struct BIT {
    vector<int> a,b;
    int n;
    void init(int _n) {
        n=_n;
        a=vector<int>(n+1);
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    void ad(int u,int v) {
        ud(u,v);
        a[u]+=v;
    }
    void as(int u,int v) {
        ud(u,v-a[u]);
        a[u]=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int sum(int l,int r) {
        return pre(r)-pre(l);
    }
}sb,sb2;
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n+1),b(m+1);
    a[0]=b[0]=-inf;
    REP1(i,n) cin>>a[i];
    REP1(i,m) cin>>b[i];
    vector<int> r(n+1);
    REP1(i,n) {
        r[i]=cl(b,a[i]);
    }

    return 0;
}