#include<bits/stdc++.h>
using namespace std;
main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        int a[7],b[7],c=1;
        for(int i=0;i<7;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<7;i++)
            scanf("%d",&b[i]);
        if(a[1]==a[3] || a[1]!=a[5] || b[1]==b[3] || b[1]!=b[5]) {
            printf("A"); c=0;
        }
        if(a[6]!=1 || b[6]!=0) {
            printf("B"); c=0;
        }
        if(a[1]==b[1] || a[3]==b[3] || a[5]==b[5]) {
            printf("C"); c=0;
        }
        if(c)
            printf("None");
        printf("\n");
    }
	return 0;
}
