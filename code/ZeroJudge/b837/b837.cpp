#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,c[40]={},a,b,ta,tb;
    c[1]=1;
    for(int i=2;i<=31;i++)
        c[i]=c[i-1]+c[i-2];
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a>>b;
        if(a>b) swap(a,b);
        ta=lower_bound(c,c+32,a)-c;
        tb=upper_bound(c,c+32,b)-c;
        for(int j=ta;j<tb;j++)
            cout<<c[j]<<"\n";
        cout<<tb-ta<<"\n";
        if(i<n-1)
            cout<<"------\n";
    }
    return 0;
}
