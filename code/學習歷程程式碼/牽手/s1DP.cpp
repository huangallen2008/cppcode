#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int mod=1e9+7;
const int maxn=5e3+5;
signed main() {
    IOS();
    vector<int> dp(maxn);
    dp[0]=1;
    for(int i=1;i<maxn;i++)
        for(int j=0;j<i;j++)
            dp[i]=(dp[i]+dp[j]*dp[i-1-j])%mod;
    int T; 
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        cout<<dp[n]<<'\n';
    }
    return 0;
}






