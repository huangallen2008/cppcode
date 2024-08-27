#include<bits/stdc++.h>
using namespace std;
string t,ts;
stringstream ss1,ss2;
int a[1000005],w[1005],v[1005],l,tt=0;
main()
{
    getline(cin,t);
    ss1<<t;
    while(getline(ss1,ts,' ')) {
        w[tt++]=stoi(ts);
    }tt=0;
    getline(cin,t);
    ss2<<t;
    while(getline(ss2,ts,' ')) {
        v[tt++]=stoi(ts);
    }
    cin>>l;
    for(int i=0;i<tt;i++)
        for(int j=l;j>=w[i];j--)
            a[j]=max(a[j],a[j-w[i]]+v[i]);
    cout<<a[l];
    return 0;
}
