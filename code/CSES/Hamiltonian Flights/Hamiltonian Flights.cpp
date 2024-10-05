#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
//#define int long long
#define ll long long
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
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    Graph g(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
    }
    vector<int> p2(n+1);
    REP(i,n+1) p2[i]=(1<<i);
//    vector<vector<ll>> dp(p2[n],vector<ll>(n));
    vector<vector<ll>> dp(n,vector<ll>(p2[n]));
    for(int i=1;i<p2[n];i++) {
        REP(j,n) {
            if(!((i>>n-1)&1)||!((i>>j)&1)) continue;
            if((i^p2[j])==0) {
                dp[j][i]=1;
            }
            else {
                for(int v:g[j]) {
                    if((i>>v)&1)
                        dp[j][i]+=dp[v][i^p2[j]];
                }
                dp[j][i]%=mod;
            }
        }
    }
    cout<<dp[0][p2[n]-1]<<'\n';
    return 0;
}
