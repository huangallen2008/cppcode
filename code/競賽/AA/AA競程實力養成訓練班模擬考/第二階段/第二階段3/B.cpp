#include<bits/stdc++.h>
// #include<bits/extc++.h>
// using namespace __gnu_pbds;
using namespace std;
// using pbds = tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>;
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
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct BIT {
    int n;
    Vi b;
    void init(int _n) {
        n=_n;
        b=Vi(n+1);
    }
    void ud(int u,int v) {
        if(u<=0) return;
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int pre(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
    int qu(int l,int r) {
        return pre(r)-pre(l-1);
    }
}bit;
signed main() {
    IOS(); 
    // pbds c;
    int n;
    cin>>n;
    bit.init(n);
    Vi a(n+1),b(n+1);
    REP1(i,n) cin>>a[i];
    Vi t;
    REP1(i,n) t.pb(a[i]);
    sort(ALL(t));
    REP1(i,n) b[i]=n-(lower_bound(ALL(t),a[i])-t.begin());
    BIT bit0;
    bit0.init(n);
    unordered_map<int,int> las;
    int cnt=0;
    REP1(i,n) {
        int an=0;
        if(bit0.qu(b[i],b[i])==0)bit0.ud(b[i],1);
        if(las[a[i]]==0) {
            an=a[i]+bit0.qu(1,b[i]-1);
        }
        else {
            an=bit.qu(las[a[i]],i);
        }
        bit.ud(las[a[i]],-1);
        las[a[i]]=i;
        bit.ud(i,1);
        cout<<an<<'\n';
    }
    return 0;
}