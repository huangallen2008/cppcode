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
const int maxn=5;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    Vi p(n);
    REP(i,n) cin>>p[i];
    vector<pii> a(k);
    REP(i,k) cin>>a[i].f>>a[i].s,a[i].f--,a[i].s--;
    Vi b(n);
    REP(i,n) b[i]=i+1;
    int dif=0;
    REP(i,n) dif+=p[i]!=b[i];
    auto _upd=[&](Vi &v,int u) {
        swap(v[a[u].f],v[a[u].s]);
    };
    auto updp=[&](int u) {
        auto [x,y]=a[u];
        if(p[x]==b[x]) dif++;
        if(p[y]==b[y]) dif++;
        _upd(p,u);
        if(p[x]==b[x]) dif--;
        if(p[y]==b[y]) dif--;
    };
    auto updb=[&](int u) {
        auto [x,y]=a[u];
        if(p[x]==b[x]) dif++;
        if(p[y]==b[y]) dif++;
        _upd(b,u);
        if(p[x]==b[x]) dif--;
        if(p[y]==b[y]) dif--;
    };
    for(int i=k-1;i>0;i--) updb(i);
    Vi an;
    REP(i,k-1) {
        if(dif==0) an.pb(i+1);
        updp(i);
        updb(i+1);
    }
    if(dif==0) an.pb(k);
    for(int x:an) cout<<x<<' ';
    cout<<'\n';
    return 0;
}
