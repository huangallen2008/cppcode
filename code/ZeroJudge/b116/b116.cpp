#include<bits/stdc++.h>
using namespace std;
int m,n,a[10][100]={};
int p(int i,int g,int r) {
	if(g==n) {
		if(r==0)
		    return 1;
		else
		    return 0;
	}int x=p(i,g+1,r+a[i][g]),y=p(i,g+1,r-a[i][g]);
	if(x>y)
	    cout<<"+"<<a[i][g];
	else
	    cout<<"-"<<a[i][g];
	return max(x,y/*p(i,g+1,r+a[i][g]),p(i,g+1,r-a[i][g])*/);
}
main() {
	while(scanf("%d%d",&m,&n)) {
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
			cout<<a[i][0];
			printf("%s\n",p(i,1,a[i][0])==1?"Yes":"No");
		}
	}
} 
