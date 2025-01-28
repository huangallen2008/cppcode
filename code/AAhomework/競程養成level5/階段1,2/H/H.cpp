#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
const int inf=(1ll<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<int> h(n);
    REP(i,n) cin>>h[i];
    vector<vector<int>> e(n,vector<int>(n));
    int l=0;
    cin>>l;
    l--;
    REP(i,m-1) {
        int x;
        cin>>x;
        x--;
        e[x][l]++;
        e[l][x]++;
        l=x;
    }
    sort(ALL(h));
    vector<int> dp(1<<n,inf);
    dp[0]=0;
    for(int i=1;i<1<<n;i++) {
        int j=__builtin_popcount(i)-1;
        REP(u,n) {
            if(~(i>>u)&1) continue;
            int r=dp[i^(1<<u)];
            REP(v,n) {
                if((i>>v)&1) r+=h[j]*e[u][v];
                else r-=h[j]*e[u][v];
            }
            chmin(dp[i],r);
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';
    return 0;
}