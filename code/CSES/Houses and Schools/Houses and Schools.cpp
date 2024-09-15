#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
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
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<vector<int>> dp,cost;
void f(int now,int l,int r,int d,int u) {
    if(l>r) return;
    int mid=l+r>>1;
    int mnid=0;
    for(int i=d;i<=min(u,mid-1);i++) {
        int t=dp[now-1][i]+cost[i+1][mid];
        if(t<dp[now][mid]) {
            dp[now][mid]=t;
            mnid=i;
        }
    }
    f(now,l,mid-1,d,mnid);
    f(now,mid+1,r,mnid,u);
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),ps(n+1),pre_pol(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) ps[i]=ps[i-1]+a[i];
    REP1(i,n) pre_pol[i]=pre_pol[i-1]+a[i]*i;
//    oparr(a)oparr(ps)oparr(pre_pol)
    dp=vector<vector<int>>(k+1,vector<int>(n+1,inf));
    cost=vector<vector<int>>(n+1,vector<int>(n+1,inf));
    dp[0][0]=0;
    REP1(i,n) {
        for(int j=i;j<=n;j++) {
            int id=lower_bound(ALL(ps),ps[j]+ps[i-1]+1>>1)-ps.begin();
            int r=(pre_pol[j]-pre_pol[id])-(id)*(ps[j]-ps[id]);
            r+=id*(ps[id]-ps[i-1])-(pre_pol[id]-pre_pol[i-1]);
            cost[i][j]=r;
        }
    }
    REP1(i,k) f(i,1,n,0,n);
//    REP1(i,k) {
//        REP1(j,n) cout<<dp[i][j]<<' ';
//        cout<<'\n';
//    }
    cout<<dp[k][n]<<' ';
    return 0;
}
