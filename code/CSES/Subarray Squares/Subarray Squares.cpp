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
vector<int> dp,ndp,a,ps;
void f(int l,int r,int d,int u) {
    if(l>r) return;
    int mid=(l+r)>>1,mnid=0;
    for(int i=d;i<=min(u,mid-1);i++) {
        int nv=dp[i]+SQ(ps[mid]-ps[i]);
        if(nv<ndp[mid]) {
            ndp[mid]=nv;
            mnid=i;
        }
    }
    f(l,mid-1,d,mnid);
    f(mid+1,r,mnid,u);
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    a=vector<int>(n+1);
    ps=vector<int>(n+1);
    dp=vector<int>(n+1,inf);//dp[0][?]
    ndp=vector<int>(n+1,inf);
    REP1(i,n) cin>>a[i];
    REP1(i,n) ps[i]=ps[i-1]+a[i];
    dp[0]=0;
    REP(i,k) {
        f(1,n,0,n);
        swap(dp,ndp);
        ndp=vector<int>(n+1,inf);
    }
    cout<<dp[n]<<'\n';
    return 0;
}
