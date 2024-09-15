#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=998244353;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+2),last(n+2);
    REP1(i,n) cin>>a[i];
    vector<int> t;
    t.pb(0);
    REP1(i,n) {
        while(a[i]<a[t.back()]) t.pop_back();
        last[i]=t.back();
        t.pb(i);
    }
//    oparr(last)
    vector<int> dp(n+1),pdp(n+1),smd(n+1);
    dp[0]=1;pdp[0]=1;
    REP1(i,n) {
        dp[i]=md(dp[i]+smd[last[i]]+pdp[i-1]-pdp[last[i]]);
        if(last[i]==0) dp[i]=md(dp[i]+1);
        smd[i]=md(smd[last[i]]+dp[i]);
        pdp[i]=md(pdp[i-1]+dp[i]);
    }
//    oparr(dp)
    int an=0;
    int mn=a[n];
    RREP1(i,n) {
        mn=min(mn,a[i]);
        if(a[i]==mn) an=md(an+dp[i]);
    }
    cout<<an<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
