#include<bits/stdc++.h>
using namespace std;
int n,x,y,c=0,a=0;
bool o=true;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>x>>y;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    while(x<y) {
        int m=0,tt=c;
        while(c<n && v[c].first<=x) m=max(m,v[c++].second);
        if(tt==c) { o=false; break; }
        x=m;
        a++;
    }
    if(o) cout<<a<<"\n";
    else cout<<"-1\n";
    return 0;
}
