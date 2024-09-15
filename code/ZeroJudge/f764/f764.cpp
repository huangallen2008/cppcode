/*#include<bits/stdc++.h>
using namespace std;
main() {
	int s=0,e=0,n;
	scanf("%d",&n);
	int a[n][2]={};
	for(int i=0;i<n;i++) {
		scanf("%d%d",&a[i][0],&a[i][1]);
		if(a[i][0]<a[s][0])
		    s=i;
		if(a[i][0]>a[e][0])
			e=i;
	}
	printf("%d %d\n",a[s][0],a[s][i]);
	while(s!=e) {
		double c=0;
		int b=0;
		for(int i=0;i<n;i++) {
			if(i!=s && a[i][0]>a[s][0] && a[i][1]>a[s][1] && ((double)a[i][1]-(double)a[s][1])/((double)a[i][0]-(double)a[s][0]<c)) {
			    b=i;
				c=((double)a[i][1]-(double)a[s][1])/((double)a[i][0]-(double)a[s][0]<c);
			}
		}
		s=b;
		printf("%d %d\n",a[s][0],a[s][1]);
	}
	return 0;
} */
#include<bits/stdc++.h>
using namespace std;
main() {
    int T;
    scanf("%d",&T);
    while(T--) {
    	int n,s=0,an=0,a=0,b=0;
    	scanf("%d",&n);
    	for(int i=0;i<n;i++) {
    	    scanf("%d",&a);
    	    if(s<a)
    		    an++;
            else
                s-=b;
    	    s+=a;
    	    b=a;
        }
	    printf("%d\n",an);
    }
    return 0;
}
