#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int mod=1e9+7;
const int maxn=1e5+5;
signed main() {
    IOS();
    vector<int> dp(maxn);
    dp[0]=1,dp[1]=1;
    for(int i=2;i<maxn;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
    int n;
    while(cin>>n) cout<<dp[n]<<'\n';
    return 0;
}
