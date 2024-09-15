#include<bits/stdc++.h>
using namespace std;
int n,t=0;
long long an=0;
pair<int,int> a[100005]={};
main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].first;
    for(int i=0;i<n;i++) cin>>a[i].second;
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        t+=a[i].first;
        an+=(long long)(a[i].second-t);
    }
    cout<<an<<"\n";
    return 0;
}
