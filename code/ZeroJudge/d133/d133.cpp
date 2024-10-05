#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m[]={5,10,25,50};
    while(cin>>n) {
        long long a[30005]={};
        for(int i=0;i<4;i++)
            for(int j=m[i];j<=n;j++)
                a[j]+=a[j-m[i]]+1;
        if(a[n]==0)
            cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
        else
            cout<<"There are "<<a[n]+1<<" ways to produce "<<n<<" cents change.\n";
    }
    return 0;
}
