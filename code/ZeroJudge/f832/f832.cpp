#include<bits/stdc++.h>
using namespace std;
main()
{
    long long int an=0;
    int n,m;
    cin>>n>>m;
    int w[n],c[m],a=m-1,b=n-1;
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<m;i++)
        cin>>c[i];
    sort(w,w+n);
    sort(c,c+m);
    while(a>=0 && b>=0)
    {
        if(c[a]>=w[b])
        {
            an+=w[b];
            b--;
            a--;
        }
        else
            b--;
    }
    cout<<an<<endl;
    return 0;
}
