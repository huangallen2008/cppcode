#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
int n,d[2001][2001]={};
char s[2001];
int dp(int i,int k) {
    if(k<0)
        return 0;
    if(i<0) {
        if(k==0)
            return 1;
        else
            return 0;
    }
    if(d[i][k])
        return d[i][k]-1;
    if(s[i]=='?')
        return (d[i][k]=(dp(i-1,k-1)%m+dp(i-1,k+1)%m)+1)-1;
    else if(s[i]==']')
        return (d[i][k]=dp(i-1,k+1)%m+1)-1;
    else
        return (d[i][k]=dp(i-1,k-1)%m+1)-1;
}
main()
{
    scanf("%d%s",&n,&s);
    printf("%d",dp(n-1,0));
    return 0;
}
