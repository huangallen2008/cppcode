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
int inv(int x) {
    int p=mod-2;
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
void solve() {
    int n;
    cin>>n;
    if(n*(n+1)%4!=0) cout<<"0\n";
    else {
        int k=(n+1)*n/4;
        vector<int> dp(k+1);
        dp[0]=1;
        REP1(i,n) {
            for(int j=k;j>=i;j--) {
                dp[j]=(dp[j]+dp[j-i])%mod;
            }
        }
        cout<<(dp[k]*inv(2))%mod<<"\n";
    }
}
signed main() {
    IOS();
    solve();
    return 0;
}
