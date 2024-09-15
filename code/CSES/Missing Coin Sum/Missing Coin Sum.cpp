#include<bits/stdc++.h>
using namespace std;
int n,a[200005]={};
long long t=1;
bool o=true;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)  {
        if(t<a[i]) {
            cout<<t<<"\n";
            o=false;
            break;
        }
        t+=a[i];
    }
    if(o) cout<<t<<"\n";
    return 0;
}
