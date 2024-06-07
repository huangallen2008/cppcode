#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],k[5001][5001]={},s[5001]={};
int d() {
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n-1;i++) dp[i][i+1]=a[i]+a[i+1];
    for(int i=n-3;i>=0;i--) {
        for(int j=i+2;j<n;j++) {
            pair<int,long long> t={-1,100000000000000001};
            for(int l=k[i][j-1];l<=k[i+1][j];l++) {
                if(dp[i][l]+dp[l+1][j]+s[j]-(i==0?0:s[i-1])<t.second) t={l,dp[i][l]+dp[l+1][j]+s[j]-(i==0?0:s[i-1])};
            }
            k[i][j]=t.first;
            dp[i][j]=t.second;
        }
    }
    return dp[0][n-1];
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++) k[i][i+1]=i;
    s[0]=a[0];
    for(int i=1;i<n;i++) s[i]=s[i-1]+a[i];
    cout<<d();
    return 0;
}
