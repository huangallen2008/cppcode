#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    pair<int,int> v[200005];
    vector<int> a;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&v[i].first,&v[i].second);
    sort(v,v+n);
    a.push_back(v[0].second);
    for(int i=1;i<n;i++) {
        if(v[i].second>=a[a.size()-1])
            a.push_back(v[i].second);
        else
            a[upper_bound(a.begin(),a.begin()+a.size()-1,v[i].second)-a.begin()]=v[i].second;
    }
    printf("%d",a.size());
    return 0;
}
