#include<bits/stdc++.h>
using namespace std;
int n,m,tt1,tt2,h[805]={},a,b;
vector<int> v[805];
void dfs(int u) {
    if(h[u]) return;
    h[u]=1;
    for(int i=0;i<v[u].size();i++) {
        dfs(v[u][i]);
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m) {
        for(int i=0;i<m;i++) {
            cin>>tt1>>tt2;
            v[tt1].push_back(tt2);
        }
        cin>>a>>b;
        dfs(a);
        if(h[b]) cout<<"Yes!!!\n";
        else     cout<<"No!!!\n";
        memset(h,0,sizeof(h));
        for(int i=0;i<n;i++) {
            v[i].clear();
        }
    }
    return 0;
}
