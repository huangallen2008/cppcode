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
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxc=512;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int dp[maxc<<1][maxc<<1][maxc];
signed main() {
    IOS();
    int n,k,c;
    cin>>n>>k>>c;
    vector<pii> a(n);
    vector<int> b[maxc],sum(maxc);
    REP(i,n) cin>>a[i].f>>a[i].s,b[a[i].f].pb(a[i].s),sum[a[i].f]+=a[i].s;
    REP(i,maxc) sort(ALL(b[i]),greater<int>());
    vector<pii> all;
    REP(i,maxc) REP1(j,b[i].size()-1) all.pb({b[i][j],i});
    sort(ALL(all),greater<pii>());
    int basei=0,basea=0;
    int ncc=max(0ll,k-maxc),inc=k-ncc;
    vector<pii> cl;
    REP(i,ncc) {
        basei^=all[i].s;
        basea+=all[i].f;
        b[all[i].s].pop_back();
    }
    for(int i=ncc;i<ncc+inc&&i<all.size();i++) {
        cl.pb(all[i]);
        b[all[i].s].pop_back();
    }
    REP(i,maxc) if(b[i].size()) {
        cl.pb({b[i].back(),i});
    }
    REP(i,maxc) REP(j,maxc) dp[0][i][j]=-inf;
    dp[0][0][0]=0;
    if(b[0].size()) dp[0][1][0]=b[0][0];
    REP1(i,cl.size()-1) {
        REP(j,i+1) {
            REP(k,maxc) {
                dp[i][j][k]=dp[i-1][j][k];
                chmax(dp[i][j][k],dp[i-1][j-1][k^cl[i].s]+cl[i].f);
            }
        }
    }
    // int basei=0,basea=0;
    REP(i,c+1) {
        int an=basea+dp[cl.size()-1][inc][i^basei];
        cout<<an<<' ';
    }
    cout<<'\n';
    return 0;
}