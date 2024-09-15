#include<bits/stdc++.h>
using namespace std;
int T,n,t;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>T;
    while(T--) {
        bool o=true; t=0;
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) cin>>a[i].second;
        for(int i=0;i<n;i++) cin>>a[i].first;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) {
            t+=a[i].second;
            if(t>a[i].first) { o=false; break; }
        }
        if(o) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
