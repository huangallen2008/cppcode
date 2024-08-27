#include<bits/stdc++.h>
using namespace std;
int n,a[100005]={};
long long an=0;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) an+=(long long)a[i]*(long long)(n-i);
    cout<<an<<"\n";
    return 0;
}
