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
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
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
int qu(auto &mp,auto x) {
    if(mp.find(x)==mp.end()) return 0;
    return mp[x];
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> c(n+1);
    REP1(i,n) cin>>c[i];
    vector<int> dp0(n+1),dp1(n+1);
    REP1(i,n) {
        if(i==3)  {
            dp0[i]=c[i]+min({dp0[i-1],i>1?dp0[i-2]:inf});
            dp1[i]=min(c[i]+min({dp1[i-1],i>1?dp1[i-2]:inf}),min({dp0[i-1],i>1?dp0[i-2]:inf}));
        }
        else {
            dp0[i]=c[i]+min({dp0[i-1],i>1?dp0[i-2]:inf,i>2?dp0[i-3]:inf});
            dp1[i]=min(c[i]+min({dp1[i-1],i>1?dp1[i-2]:inf,i>2?dp1[i-3]:inf}),min({dp0[i-1],i>1?dp0[i-2]:inf,i>2?dp0[i-3]:inf}));
        }
    }
    // oparr(dp0)oparr(dp1)
    int an=min(dp1[n],dp1[n-1]);
    cout<<an<<'\n';
    return 0;
}
