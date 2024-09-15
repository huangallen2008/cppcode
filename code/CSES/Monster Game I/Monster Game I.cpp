#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt")
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
const int maxn=5e4+5;
const int maxv=1e5+5;
const int inf=(1<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,x;
vector<int> s,f;
struct line {
    int m,k;
};
int val(line l,int x) {
    return x*l.m+l.k;
}
bool check(line a,line b,line c) {
    return (b.k-a.k)*(b.m-c.m)>=(c.k-b.k)*(a.m-b.m);
}
int solve() {
    vector<int> dp(n+1);
    deque<line> dq;
    dq.pb({x,0});
    REP1(i,n) {
        while(dq.size()>1&&val(dq[0],s[i])>val(dq[1],s[i])) dq.pop_front();
        dp[i]=val(dq[0],s[i]);
        line nl={f[i],dp[i]};
        while(dq.size()>1&&check(dq[dq.size()-2],dq.back(),nl)) dq.pop_back();
        dq.pb(nl);
    }
    return dp[n];
}
signed main() {
    IOS();
    cin>>n>>x;
    s=vector<int>(n+1);
    f=vector<int>(n+1);
    f[0]=x;
    REP1(i,n) cin>>s[i];
    REP1(i,n) cin>>f[i];
    cout<<solve()<<'\n';
    return 0;
}
