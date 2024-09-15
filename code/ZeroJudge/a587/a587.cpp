#include<bits/stdc++.h>
using namespace std;
main() {
    int k;
    while(cin>>k) {
	    int dp[10001]={},v[k]={},c[k]={},w;
    	for(int i=0;i<k;i++) cin>>v[i]>>c[i];
		cin>>w;
    	for(int i=0;i<k;i++)
    		for(int j=w;j>=v[i];j--)
    		    dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
		cout<<dp[w]<<endl;
	}
	return 0;
}
