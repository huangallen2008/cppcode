#include<bits/stdc++.h>
using namespace std;
main() {
    int k,dp[1005]={},v[105]={},c[105]={},w;
    cin>>w>>k;
    for(int i=0;i<k;i++) {
        cin>>v[i]>>c[i];
        for(int j=w;j>=v[i];j--)
            dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
    }
	cout<<dp[w];
	return 0;
}
