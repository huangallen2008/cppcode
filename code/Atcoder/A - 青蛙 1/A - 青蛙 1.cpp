#include<bits/stdc++.h>
using namespace std;
int h[100001]={},n,dp[100001]={};
main() {
	cin>>n;
	cin>>h[0]>>h[1];
	dp[1]=abs(h[1]-h[0]);
	for(int i=2;i<n;i++) {
	    cin>>h[i];
		dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
	}
	cout<<dp[n-1]<<endl;
	return 0;
}
