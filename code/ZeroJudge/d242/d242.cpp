#include<bits/stdc++.h>
using namespace std;
int n,b,tt,t=0,d[600000]={1},l=1;
vector<int> a,v,an;
main()
{
    while (cin>>tt){
        a.push_back(tt);
    }
    v.push_back(a[0]);
    for(int i=1;i<a.size();i++) {
        if(a[i]>v[v.size()-1]) {
            v.push_back(a[i]);
            d[i]=++l;
        }
        else {
            int u=lower_bound(v.begin(),v.begin()+v.size()-1,a[i])-v.begin();
            v[u]=a[i];
            d[i]=u+1;
        }
    }
    cout<<v.size()<<"\n-\n";
    for(int i=a.size()-1;i>=0;i--) {
        if(d[i]==l) {
            an.insert(an.begin(),a[i]);
            l--;
        }
    }
    for(int i=0;i<an.size();i++)
        cout<<an[i]<<"\n";
    return 0;
}
