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
const int mod=998244353;
const int maxn=1e7+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k;
Vi sz;
vector<vector<int>> a;
int an=0;
Vi dp;
void dfs(int l,int r) {
    if(l==r) {
        REP(i,min(sz[l]+1,k)) chmax(an,a[l][i]+dp[k-i]);
        return;
    }
    int m=l+r>>1;
    auto tmp=dp;
    for(int i=m+1;i<=r;i++) {
        for(int j=k;j>=sz[i];j--) {
            chmax(dp[j],dp[j-sz[i]]+a[i][j]);
        }
    }
    dfs(l,m);
    dp=tmp;
    for(int i=l;i<=m;i++) {
        for(int j=k;j>=sz[i];j--) {
            chmax(dp[j],dp[j-sz[i]]+a[i][j]);
        }
    }
    dfs(m+1,r);
    dp=tmp;
}
signed main() {
    IOS(); 
    cin>>n>>k;
    dp=Vi(k+1);
    a=vector<Vi>(n);
    sz=Vi(n);
    REP(i,n) {
        cin>>sz[i];
        a[i]=Vi(sz[i]+1);
        REP1(j,sz[i]) cin>>a[i][j],op(j);
        ope("ok")
        REP1(j,sz[i])a[i][j]+=a[i][j-1];
    }
    dfs(0,n-1);
    cout<<an<<'\n';
    return 0;
}