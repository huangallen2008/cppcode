#include<bits/stdc++.h>
using namespace std;
int n,m,a[400005]={},r=0;
main()
{
    cin>>n>>m>>a[0];
    for(int i=1;i<n;i++) {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=0;i<n;i++)
        a[i+n]=a[n-1]+a[i];
    for(int i=0;i<m;i++) {
        int x,l=1,h=n,m=(n+1)/2+r;
        cin>>x;
        x%=a[n-1];
        r=((lower_bound(a+r,a+r+n,x+a[r-1])-a)+1)%n;
    }
    cout<<r;
    return 0;
}
