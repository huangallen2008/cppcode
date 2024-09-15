#include<bits/stdc++.h>
using namespace std;
int n,a[100005]={},b[100005]={},an,l=0,h=0,m;
main()
{
    cin>>n; h=n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    while(l<h) {
        m=(l+h+1)/2;
        bool o=true;
        for(int i=0;i<m;i++)
            if(a[i]>=b[n-m+i]) o=false;
        if(o) l=m;
        else h=m-1;
    }
    cout<<l<<"\n";
    return 0;
}
