#include<stdio.h>
using namespace std;
main() {
	int n,a[101]={},b;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
	    scanf("%d",&b);
	    a[b]++;
	}
	for(int i=1;i<=100;i++)
		for(int j=0;j<a[i];j++)
	        printf("%d ",i);
	printf("\n");
	return 0;
}
