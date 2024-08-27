#include<bits/stdc++.h>
using namespace std;
int n,a[105]={105},an=0;
main()
{
    cin>>n;
    a[n+1]=105;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        if(a[i]==0)
            an+=min(a[i-1],a[i+1]);
    cout<<an;
    return 0;
}
