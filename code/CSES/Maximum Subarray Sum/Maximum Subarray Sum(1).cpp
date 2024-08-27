#include<bits/stdc++.h>
using namespace std;
int n,x;
long long s=0,m=0;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    s=max(s,m);
    for(int i=1;i<n;i++) {
        int x;
        cin>>x;
        s+=x;
        if(m<0 || s>=0) m=max(m,s);
        else s=0;
    }
    cout<<m<<"\n";
    return 0;
}
