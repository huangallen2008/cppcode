#include<bits/stdc++.h>
using namespace std;
int n,m=1000000001,a=0;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        int t;
        cin>>t;
        if(t<m) m=t;
        a=max(a,t-m);
    }
    cout<<a<<"\n";
    return 0;
}
