#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
}bit;
signed main() {
    IOS();
    int n;
    cin>>n;
    bit.init(n<<1);
    vector<int> an(n+1);
    vector<int> a(n<<1|1);
    REP1(i,n<<1) cin>>a[i];
    vector<int> l(n+1,-1),r(n+1,-1);
    REP1(i,n<<1) {
        if(l[a[i]]==-1) l[a[i]]=i;
        else r[a[i]]=i;
    }
    REP1(i,n<<1) {
        if(l[a[i]]==i) {
            an[a[i]]+=bit.qu(r[a[i]])-bit.qu(i);
            bit.ud(r[a[i]],1);
        }
    }
    bit.init(n<<1);
    RREP1(i,n<<1) {
        if(r[a[i]]==i) {
            an[a[i]]+=bit.qu(i-1)-bit.qu(l[a[i]]);
            bit.ud(l[a[i]],1);
        }
    }
    REP1(i,n) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}