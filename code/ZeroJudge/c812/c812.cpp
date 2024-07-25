#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[5005];
int n,k,q,an=0;
int dfs(int u,int p,int l) {
    int r=0;
    if(p>=q) r++;
    if(v[u].size()>1 || p>1000000001)
        for(auto a:v[u])
            if(a.first!=l)
                r+=dfs(a.first,min(p,a.second),u);
    return r;
}
main()
{
    cin>>n>>k>>q;
    for(int i=0;i<n-1;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    cout<<dfs(k,1000000005,-1)-1;
    return 0;
}
