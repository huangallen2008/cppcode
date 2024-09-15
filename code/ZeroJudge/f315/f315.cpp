#include<bits/stdc++.h>
int b[100002]={},h[100002]={},d[100002]={},n,t;
long long an=0;
void a(int p,int v) {
	while(p<=n) {
		b[p]+=v;
		p+=p&-p;
	}
}
int s(int p) {
	int a=0;
	while(p>0) {
		a+=b[p];
		p-=p&-p; 
	}
	return a;
}
main() {
	scanf("%d",&n);
	for(int i=0;i<n*2;i++) {
		scanf("%d",&t);
		a(t,1);
		h[t]+=(d[t]*2-1)*s(t-1);
		an+=d[t]*h[t];
		d[t]++;
	}
	printf("%lld",an);
	return 0;
} 
