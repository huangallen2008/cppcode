#include<bits/stdc++.h>
using namespace std;
const int N = 3000 + 5;
const long long aa = 1000000000 + 1;
int n,an=0;
long long u,f[N][N]={};
main() {
    scanf("%d%lld",&n,&u);
    for(int i=1;i<=n;i++) {
    	for(int j=1;j<=n;j++) {
    		scanf("%lld",&f[i][j]);
    		if(f[i][j]==-1)
    		    f[i][j]=aa;
    		f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=an+1;i+k<=n && j+k<=n && f[i+k][j+k]-f[i][j+k]-f[i+k][j]+f[i][j]<=u;k++)
			    an=k;
	printf("%d\n",an*an);
    return 0;
}
