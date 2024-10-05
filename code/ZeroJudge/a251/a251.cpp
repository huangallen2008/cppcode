#include<bits/stdc++.h>
using namespace std;
main() {
	int n,b;
	cin>>n;
	while(n--) {
		cin>>b;
		int a[b+1]={};
		for(int i=1;i<=4;i++)
		    cin>>a[i];
		for(int i=5;i<=b;i++)
		    a[i]=a[i-1]+a[i-4];
		sort(a,a+b+1);
		cout<<a[(b*2+3)/4]<<endl;
	}
	return 0;
}
