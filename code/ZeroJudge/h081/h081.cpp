#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,d,a[105]={},an=0,c;
    bool s=true;
    cin>>n>>d>>c;
    for(int i=1;i<n;i++) {
        cin>>a[i];
        if(a[i]>=c+d && s) {
            an+=a[i]-c;
            s=false;
            c=a[i];
        }
        if(a[i]<=c-d && !s) {
            s=true;
            c=a[i];
        }
    }
    cout<<an;
    return 0;
}
