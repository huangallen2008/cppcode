#include<bits/stdc++.h>
using namespace std;
int n;
long long s=0,a=0;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        s+=v[i].first;
        a+=v[i].second-s;
    }
    cout<<a<<"\n";
    return 0;
}
