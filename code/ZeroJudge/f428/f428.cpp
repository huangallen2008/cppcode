#include<bits/stdc++.h>
using namespace std;
void r(int &a,int &b) { int t=a;a=b;b=t; }
main()
{
	int n,a1,a2,b1,b2,X1,X2,Y1,Y2;
	scanf("%d%d%d%d%d",&n,&a1,&b1,&a2,&b2);
	a1-=n; b1-=n; a2-=n; b2-=n;
	if(a1>a2)
		r(a1,a2);
	if(b1>b2)
		r(b1,b2);
	long long s=(a2-a1+1)*(b2-b1+1)*n;
	for(int i=0;i<n-1;i++) {
		X1=max(-i,a1);
		X2=min(i,a2);
		Y1=max(-i,b1);
		Y2=min(i,b2);
		if(X2>=X1 && Y2>=Y1)
		    s-=(X2-X1+1)*(Y2-Y1+1);
	}
	printf("%lld",s);
	return 0;
}
