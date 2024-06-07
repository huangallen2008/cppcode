#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    long long a[100];
    a[1]=1; a[2]=2;
    for(int i=3;i<100;i++)
        a[i]=a[i-1]+a[i-2];
    while(cin>>n) {
        cout<<a[n]<<"\n";
    }
    return 0;
}
