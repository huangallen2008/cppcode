#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
long long f(int *a,int *b,int l,int r) {
    if(r==l) return 0;
    long long m=(l+r)/2,an=(f(a,b,l,(l+r)/2)+f(a,b,(l+r)/2+1,r))%10000019,ca=l,cb=m+1,s=0,c=l;
    while(ca<=m) {
        while(cb<=r && a[ca]>a[cb]) s+=a[cb++];
        an+=(a[ca++]*(cb-m-1)+s)%10000019;
    }
    ca=l; cb=m+1;
    while(ca<=m && cb<=r) {
        if(a[ca]<a[cb]) b[c++]=a[ca++];
        else b[c++]=a[cb++];
    }
    while(ca<=m) b[c++]=a[ca++];
    while(cb<=r) b[c++]=a[cb++];
    for(int i=l;i<=r;i++) a[i]=b[i];
    return an%10000019;
}
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<f(a,b,0,n-1)%10000019<<"\n";
    return 0;
}
