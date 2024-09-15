#include<bits/stdc++.h>
using namespace std;
int r[40]={},n;
int dp(int a,int u,int b) {
	if(a==n)
	    return b;
	else if(u==0)
	    return max(dp(a+1,1,b),dp(a+1,2,b));
	else if(u==1)
	    return max(dp(a+1,1,b+r[a]),dp(a+1,2,b+r[a]));
	else
	    return dp(a+1,0,b+2*r[a]);
}
main() {
	cin>>n;
	while(n) {
		for(int i=0;i<n;i++)
		    cin>>r[i];
		cout<<max(dp(0,1,0),dp(0,2,0))<<endl;
		cin>>n;
	}
	return 0;
}
