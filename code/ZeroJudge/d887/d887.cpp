#include<bits/stdc++.h>
using namespace std;
int n;
long long a[30]={};
main()
{
    for(int i=1;i<=25;i++)
        a[i]=i;
    for(int i=3;i<=25;i++)
        for(int j=i;j<=25;j++)
            a[j]+=a[j-1];
    while(cin>>n) {
        cout<<a[n]<<"\n";
    }
    return 0;
}
