#include<bits/stdc++.h>
using namespace std;
int T,n;
pair<int,int> a[20000];
bool t(pair<int,int> a,pair<int,int> b) {
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
        sort(a,a+n,t);
        vector<int> v(n,1001);
        for(int i=0;i<n;i++) v[lower_bound(v.begin(),v.end(),a[i].second)-v.begin()]=a[i].second;
        cout<<lower_bound(v.begin(),v.end(),1001)-v.begin()<<"\n";
    }
    return 0;
}
