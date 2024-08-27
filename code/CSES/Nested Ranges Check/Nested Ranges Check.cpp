#include<bits/stdc++.h>
using namespace std;
int n,a[2][200005]={},mi=10000000001;
bool so(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b) {
    if(a.first.first==b.first.first) return a.first.second>=b.first.second;
    return a.first.first<b.first.first;
}
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n);
    vector<pair<int,int>> b;
    for(int i=0;i<n;i++) { cin>>v[i].first.first>>v[i].first.second; v[i].second=i; }
    sort(v.begin(),v.end(),so);
    b.push_back({1000000002,0});
    for(int i=n-1;i>=0;i--) {
        while(b.back().first<=v[i].first.second) {
            a[0][v[i].second]=1;
            a[1][b.back().second]=1;
            b.pop_back();
        }
        if(v[i].first.second>=mi) a[0][v[i].second]=1;
        b.push_back({v[i].first.second,v[i].second});
        mi=min(mi,v[i].first.second);
    }
    for(int i=0;i<n;i++) cout<<a[0][i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<a[1][i]<<" ";
    cout<<"\n";
    return 0;
}
