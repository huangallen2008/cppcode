#include<bits/stdc++.h>
using namespace std;
int n,a[1005]={};
long long d[1005]={};
long long dp(int l,int h) {
    if(l>h) return 0;
    if(l==h)
        return a[l];
	int s=l;
	for(int i=l+1;i<h;i++) {
		if((d[h]-d[i])-(d[i]-d[l])<a[i+1]) {
            s=i;
			break;
		}
	}
	return a[l]+max(dp(l+1,s),dp(s+1,h));
}
main()
{
    d[0]=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        d[i]=d[i-1]+a[i];
    }
    cout<<dp(1,n)<<" "<<d[n];
	return 0;
}
