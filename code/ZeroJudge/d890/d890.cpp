#include<bits/stdc++.h>
using namespace std;
int n,k,a[505]={},b[25005]={},t;
main()
{
    cin>>n>>k; k=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        k+=a[i];
    } t=(k+1)/2;
    for(int i=0;i<n;i++)
        for(int j=t;j>=a[i];j--)
            b[j]=max(b[j],b[j-a[i]]+a[i]);
    cout<<b[t]<<" "<<k-b[t];
    return 0;
}
