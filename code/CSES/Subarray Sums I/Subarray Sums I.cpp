#include<bits/stdc++.h>
using namespace std;
int n,x,t[200005]={},a=0,b=0,s,an=0;
main()
{
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>t[i];
    s=t[0];
    while(b<n) {
        if(s<x) s+=t[++b];
        else if(s>x) s-=t[a++];
        else {
            an++;
            s-=t[a++];
        }
    }
    cout<<an<<"\n";
    return 0;
}
