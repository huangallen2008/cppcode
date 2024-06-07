#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
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
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxs=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
struct B {
    int w,s,v;
};
bool so(B a,B b) {
    return a.w+a.s<b.w+b.s;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<B> a(n);
    int ms=0;
    REP(i,n) {
        cin>>a[i].w>>a[i].s>>a[i].v;
        ms=max(ms,a[i].s);
    }
    ms++;
    sort(ALL(a),so);
    vector<vector<int>> dp(n,vector<int>(ms));
    for(int i=a[0].w;i<ms;i++) dp[0][i]=a[0].v;
    REP1(i,n-1) {
        REP(j,ms) {
            int t=min(j-a[i].w,a[i].s);
            dp[i][j]=dp[i-1][j];
            if(t>=0)dp[i][j]=max(dp[i][j],dp[i-1][t]+a[i].v);
        }
    }
    int an=a[0].v;
    REP1(i,n-1) an=max(an,dp[i-1][a[i].s]+a[i].v);
    cout<<an<<'\n';
    return 0;
}
