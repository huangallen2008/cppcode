#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,k,s[N]={},w[N]={},l=0,b=0,an=0;
main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&w[i]);
    for(int i=0;i<n;i++) {
        if(l!=w[i]) {
            an+=b;
            l=w[i];
            b=s[i];
        }
        else
            b=max(b,s[i]);
    }
    printf("%d",an+b);
	return 0;
}
