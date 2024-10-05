#include<bits/stdc++.h>
using namespace std;
int n,c=0,a=0;
map<int,int> m;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) {
        int p,s,t;
        cin>>p>>s>>t;
        m[s]+=p;
        m[1+t]-=p;
    }
    for(auto b:m) {
        c+=b.second;
        a=max(a,c);
    }
    cout<<a<<"\n";
    return 0;
}
