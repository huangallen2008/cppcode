#include<bits/stdc++.h>
using namespace std;
main() {
    int k;
    while(cin>>k) {
	    int dp[101]={},v[k]={},c[k]={};
    	for(int i=0;i<k;i++) {
    		cin>>v[i]>>c[i];
    		for(int j=100;j>=v[i];j--)
    		    dp[j]=max(dp[j],dp[j-v[i]]+c[i]);
		}
		cout<<dp[100]<<endl;
	}
	return 0;
}
