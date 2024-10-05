#include<bits/stdc++.h>
using namespace std;
int n;
long long s=0,a=0;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        int t;
        cin>>t;
        s+=t;
        if(s<0) s=0;
        a=max(a,s);
    }
    cout<<a<<"\n";
    return 0;
}
