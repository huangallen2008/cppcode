#include<bits/stdc++.h>
using namespace std;
int n,a[200005]={},t;
long long an=0;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    t=(a[(n-1)/2]+a[n/2])/2;
    for(int i=0;i<n;i++) an+=abs(t-a[i]);
    cout<<an<<"\n";
    return 0;
}
