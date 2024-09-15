#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005]={},l=1,h,m;
main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    h=a[n-1]-a[0]+1;
    while(l<h) {
        m=(l+h)/2;
        int t=0,c=0;
        for(int i=0;i<k;i++) {
            while(c<n && a[c]<=a[t]+m) { c++; }
            t=c;
        }
        if(c<n) l=m+1;
        else h=m;
    }
    cout<<l<<"\n";
    return 0;
}
