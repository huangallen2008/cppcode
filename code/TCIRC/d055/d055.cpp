#include<bits/stdc++.h>
using namespace std;
int n,m=0,t=-1,a=0;
main()
{
    cin>>n;
    vector<pair<int,int>> p(n),r;
    for(int i=0;i<n;i++) cin>>p[i].first;
    for(int i=0;i<n;i++) cin>>p[i].second;
    for(int i=0;i<n;i++) if(p[i].first>p[m].first || (p[i].first==p[m].first && p[i].second>p[m].second)) m=i;
    for(int i=0;i<n;i++) if(p[i].second>p[m].second) r.push_back(p[i]);
    sort(r.begin(),r.end());
    for(int i=r.size()-1;i>=0;i--) {
        if(r[i].second>t) { t=r[i].second; a++; }
    }
    cout<<a+1<<"\n";
    return 0;
}
