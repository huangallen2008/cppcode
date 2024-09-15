#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    long long a[105]={};
    for(int i=1;i<=100;i++)
        a[i]=a[i-1]+i*i;
    cin>>n;
    while(n!=0) {
        cout<<a[n]<<"\n";
        cin>>n;
    }
    return 0;
}
