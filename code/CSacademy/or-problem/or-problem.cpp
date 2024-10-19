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
const int maxn=2e5+5;
const int maxb=18;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k;
int st[maxb][maxn];
Vi a;
void st_init() {
    REP1(i,n) st[0][i]=a[i];
    REP1(i,maxb-1) {
        REP1(j,n-(1<<i-1)) st[i][j]=st[i-1][j]|st[i-1][j+(1<<i-1)];
    }
}
int qur(int l,int r) {
    int lg=__lg(r-l+1);
    return st[lg][l]|st[lg][r-(1<<lg)+1];
}
Vi dp;
int m;
int cost(int l,int r) {
    return qur(l,r)-m;
}
int bs(int i,int j) {//i<j, last t : cost(i+1,t)>cost(j+1,t)
    int l=j+1,r=n,mid;
    while(l<r) {
        mid=l+r+1>>1;
        if(dp[i]+cost(i+1,mid)>dp[j]+cost(j+1,mid)) l=mid;
        else r=mid-1;
    }
    return l;
}
pii check(int _m) {
    m=_m;
    dp=Vi(n+1);
    Vi t(n+1);
    deque<pii> dq;
    dq.push_back({0,n+1});
    REP1(i,n) {
        while(i>dq.front().s) dq.pop_front();
        int j=dq.front().f;
        op(i)ope(j)
        for(auto [x,y]:dq) cout<<"{"<<x<<","<<y<<"} ";entr
        dp[i]=dp[j]+cost(j+1,i);
        t[i]=t[j]+1;
        while(dq.size()>1&&bs(dq.back().f,i)<=dq[SZ(dq)-2].s) dq.pop_back();
        dq.back().s=bs(dq.back().f,i);
        dq.pb({i,n+1});
    }
    op(m)oparr(dp)
    op(m)op(dp[n])ope(t[n])
    return {dp[n],t[n]};
}
signed main() {
    IOS(); 
    cin>>n>>k;
    a=Vi(n+1);
    REP1(i,n) cin>>a[i];
    st_init();
    check(0);
    // for(int i=-5;i<=5;i++) check(i);
    // int l=-1e10,r=1e10,mid;
    // while(l<r) {
    //     mid=(r-l+1>>1)+l;
    //     if(check(mid).s>=k) l=mid;
    //     else r=mid-1;
    // }
    // ope(l)
    // cout<<check(l).f+k*l<<'\n';
    return 0;
}