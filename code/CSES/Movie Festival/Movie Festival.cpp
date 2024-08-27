#include<bits/stdc++.h>
using namespace std;
int n,c=0,t=0,an=0;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].second>>v[i].first;
    sort(v.begin(),v.end());
    while(c<n) {
        while(c<n && v[c++].second<t){}
        if(c>=n && v[c-1].second<t) break;
        t=v[c-1].first; an++;
    }
    cout<<an<<"\n";
    return 0;
}
