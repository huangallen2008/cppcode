#include<bits/stdc++.h>
using namespace std;
int n,x,a[20];
int d() {
    vector<pair<int,int>> dp(1<<n,{100,0});
    dp[0]={1,0};
    for(int i=1;i<(1<<n);i++) {
        for(int j=0;j<n;j++) {
            if((i>>j)&1) {
                if(dp[i&~(1<<j)].second+a[j]<=x) dp[i]=min(dp[i],{dp[i&~(1<<j)].first,dp[i&~(1<<j)].second+a[j]});
                else dp[i]=min(dp[i],{dp[i&~(1<<j)].first+1,a[j]});
            }
        }
    }
    return dp[(1<<n)-1].first;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<d();
    return 0;
}
