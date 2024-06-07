#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
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
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
int a[maxn];
ll dp[maxn];
int st_mx[21][maxn],st_mn[21][maxn];
void build_st() {
    REP1(i,n) st_mx[0][i]=a[i],st_mn[0][i]=a[i];
    REP1(i,20) {
        REP1(j,n) {
            st_mx[i][j]=max(st_mx[i-1][j],st_mx[i-1][min(n,j+(1<<i-1))]);
            st_mn[i][j]=min(st_mn[i-1][j],st_mn[i-1][min(n,j+(1<<i-1))]);
        }
    }
}
int qu_mx(int &l,int &r) {
    int k=__lg(r-l+1);
    return max(st_mx[k][l],st_mx[k][r+1-(1<<k)]);
}
int qu_mn(int &l,int &r) {
    int k=__lg(r-l+1);
    return min(st_mn[k][l],st_mn[k][r+1-(1<<k)]);
}
int cost(int l,int r) {
    return qu_mx(l,r)-qu_mn(l,r);
}
int bs(int i,int j) {//i>j   last t : dp[i]+cost(i+1,t)<=dp[j]+cost(j+1,t)
    int l=i+1,r=n,m;
    while(l<r) {
        m=l+r+1>>1;
        if(dp[i]+cost(i+1,m)<=dp[j]+cost(j+1,m)) l=m;
        else r=m-1; 
    }
    return l;
}
signed main() {
    IOS();
    cin>>n;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    memset(st_mx,0,sizeof(st_mx));
    memset(st_mn,0,sizeof(st_mn));
    REP1(i,n) cin>>a[i];
    build_st();
    deque<pii> dq;
    dq.push_back({0,n+1});
    REP1(i,n) {
        while(dq.front().s<i) dq.pop_front();
        int j=dq.front().f;
        dp[i]=dp[j]+cost(j+1,i);
        while(dq.size()>=2&&bs(i,dq.back().f)<=dq[dq.size()-2].s) dq.pop_back();
        dq.back().s=bs(i,dq.back().f);
        dq.push_back({i,n+1});
    }
    cout<<dp[n]<<'\n';
    return 0;
}