#include<bits/stdc++.h>
using namespace std;
int n=0,t[100005]={},w[100005]={},s=0;
pair<double,int> a[100005]={};
long long an=0;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) a[i]={(double)t[i]/(double)w[i],i};
    sort(a,a+n);
    for(int i=1;i<n;i++) {
        s+=t[a[i-1].second];
        an+=(long long)s*(long long)w[a[i].second];
    }
    cout<<an<<"\n";
    return 0;
}
