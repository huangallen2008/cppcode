#include<bits/stdc++.h>
using namespace std;
int n,p=0,mp=0,a[200005]={};
map<int,int> m;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i].first.first>>v[i].first.second; v[i].second=i;
        m[v[i].first.first]++; m[v[i].first.second+1]--;
    }
    for(auto x:m) {
        p+=x.second;
        mp=max(mp,p);
    }
    cout<<mp<<"\n";
    for(int i=1;i<=mp;i++) pq.push({0,i});
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        pair<int,int> t=pq.top();
        pq.pop();
        pq.push({v[i].first.second,t.second});
        a[v[i].second]=t.second;
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
