#include<bits/stdc++.h>
using namespace std;
int n,m,p[100005]={};
long long l=0,h=10000000005,a;
main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>p[i];
    while(l<h) {
        a=(l+h)/2;
        bool o=true;
        long long t=a,c=m;
        for(int i=0;i<n;i++) {
            if(a<p[i]) { o=false; break; }
            if(t<p[i]) {
                if(c>0) { t=a; c--; }
                else { o=false; break; }
            }
            t-=p[i];
        }
        if(o) h=a;
        else l=a+1;
    }
    cout<<l<<"\n";
    return 0;
}
