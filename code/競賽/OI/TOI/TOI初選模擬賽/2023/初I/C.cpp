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
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int>> nps(n+1,vector<int>(n+1));
    REP1(i,n) {
        cin>>a[i];
        REP1(j,n) {
            nps[j][i]=nps[j][i-1];
            if(a[i]!=j&&a[i]!=0) nps[j][i]++;
        }
    }
    vector<int> dp(n+1);
    dp[0]=1;
    REP1(i,n) {
        if(a[i]!=0) {
            if(a[i]<=i&&nps[a[i]][i]-nps[a[i]][i-a[i]]==0) {
                dp[i]=dp[i-a[i]];
            }
        }
        else {
            REP1(j,i) {
                if(nps[j][i]-nps[j][i-j]==0) {
                    dp[i]=md(dp[i]+dp[i-j]);
                }
            }
        }
    }
    int an=md(dp[n]);
    cout<<an<<'\n';
    return 0;
}
