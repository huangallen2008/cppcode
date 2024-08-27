#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N]={},n,k,dc[N]={},d[5*N]={};
void cc() {
	int b=n-2,c=n-1;
	int m[100001]={};
	m[a[n-1]]++;
	while(c>=0) {
		while(b>0 && m[a[b]]==0) {
			m[a[b]]++;
			b--;
		}
		dc[c]=c-b;
		m[a[c]]=0;
		c--;
	}
}
int& dp(int i,int p) {
    static int z=0;
    if(i<0 || p==0)
        return z;
    return d[i*k+p];
}
main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	cc();
	for(int i=0;i<n;i++)
        for(int j=1;j<=k;j++)
            dp(i,j)=max(dp(i-dc[i],j-1)+dc[i],dp(i-1,j) );
	printf("%d",dp(n-1,k));
	return 0;
}
