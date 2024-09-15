#include<bits/stdc++.h>
using namespace std;
int n,k,p[50005]={};
long long a[50005]={},b[50005]={};
int c(int s,int e,int d) {
    if(d>k || e-s<2)
        return 0;
    int ll=p[s],rr=p[e];
    a[s]=p[s]; b[e]=p[e];
    for(int i=s+1;i<=e;i++) {
        ll+=p[i];
        a[i]=a[i-1]+ll;
    }
    for(int i=e-1;i>=s;i--) {
        rr+=p[i];
        b[i]=b[i+1]+rr;
    }
    if(a[s]>b[s+2])
        return p[s+1]+c(s+2,e,d+1);
    else {
        for(int i=s+2;i<e;i++) {
            if(a[i-1]>b[i+1]) {
                if(a[i-1]-b[i+1]<b[i]-a[i-2])
                    return p[i]+c(s,i-1,d+1)+c(i+1,e,d+1);
                else
                    return p[i-1]+c(s,i-2,d+1)+c(i,e,d+1);
            }
        }
        return p[e-1]+c(s,e-2,d+1);
    }
}
main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>p[i];
    cout<<c(0,n-1,1)<<"\n";
    return 0;
}
