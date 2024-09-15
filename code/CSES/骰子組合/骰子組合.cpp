#include<bits/stdc++.h>
using namespace std;
int n,q,a=0,b=0,c=0,d=0;
main() {
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>q;
		if(q==1) {
			a++;
			c=max(c,b)+1;
		}
		else {
			b=max(b,a)+1;
			d=max(d,c)+1;
		}
	}
	cout<<max(max(a,b),max(c,d));
	return 0;
}
