#include<bits/stdc++.h>
using namespace std;
int n,t,a[200005]={};
long long l=1,h=1e18,m;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>t;
    for(int i=0;i<n;i++) cin>>a[i];
    while(l<h) {
        m=(l+h)/2;
        long long r=0;
        for(int i=0;i<n;i++) {
            r+=max((long long)0,m/(long long)a[i]);
            if(r>=t) break;
        }
        if(r>=t) h=m;
        else l=m+1;
    }
    cout<<l<<"\n";
    return 0;
}
