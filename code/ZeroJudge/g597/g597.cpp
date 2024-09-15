#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
int n,m,a[N]={},t[N]={},h[N]={},p=0;
long long an=0;
main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[x]+=z;
        a[y+1]-=z;
    }
    for(int i=1;i<=n;i++) {
        cin>>t[i];
        p+=a[i];
        h[i]=p;
    }
    sort(t+1,t+1+n);
    sort(h+1,h+1+n);
    for(int i=1;i<=n;i++)
        an+=t[i]*h[n-i+1];
    cout<<an;
    return 0;
}
