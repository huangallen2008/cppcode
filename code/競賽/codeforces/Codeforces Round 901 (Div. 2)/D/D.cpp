#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<int> c(5001);
    REP(i,n) {
        int x;
        cin>>x;
        c[min(x,(int)5000)]++;
    }
    int mex=0;
    REP(i,5001) {
        if(c[mex]==0) break;
        mex++;
    }
    vector<int> dp(5001,inf);
    dp[5000]=0;
    RREP(i,5000) {
        for(int j=i+1;j<=5000;j++) {
            dp[i]=min(dp[i],c[i]*j+dp[j]);
            if(dp[j]==0) break;
        }
    }
    cout<<dp[0]-mex<<"\n";
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
