#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
#define ld double
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
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct S {
    long long p,q;
    int id;
};
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    Vi l(n);
    REP(i,n) cin>>l[i];
    Vi v(m),s(m);
    REP(i,m) cin>>v[i];
    REP(i,m) cin>>s[i];
    vector<pair<ld,int>> t;
    REP(i,m) {
        if(v[i]>s[i])t.pb({(ld)v[i]/(v[i]*1ll*v[i]-s[i]*1ll*s[i]),i});
    }
    if(t.size()<n) {
        cout<<"-1\n";
        return 0;
    }
    sort(ALL(t));
    vector<pii> li(n);
    REP(i,n) li[i]={l[i],i};
    sort(ALL(li),greater<pii>());
    // for(auto [x,y,z]:t) cout<<"{"<<x<<","<<y<<","<<z<<"} ";entr
    // for(auto [x,y]:li) cout<<"{"<<x<<","<<y<<"} ";entr
    Vi an(n);
    REP(i,n) an[li[i].s]=t[i].s;
    REP(i,n) cout<<an[i]+1<<' ';
    cout<<'\n';
    return 0;
}