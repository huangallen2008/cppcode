#include<bits/stdc++.h>
using namespace std;
int n,l,p=0,a=0;
map<int,int> m;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        m[x]++; m[y]--;
    }
    for(auto t:m) {
        if(p==0 && t.second>0) l=t.first;
        if(p>0 && p+t.second==0) a+=t.first-l;
        p+=t.second;
    }
    cout<<a<<"\n";
    return 0;
}
