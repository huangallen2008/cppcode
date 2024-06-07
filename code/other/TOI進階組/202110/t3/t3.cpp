#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005]={},g=0,s=0;
vector<int> v[100005];
void d(int u) {
    if(a[u]==1)
        return;
    a[u]=1;
    if(v[u].size()==0) {
        g=1;
        return;
    }
    for(auto t : v[u]) {
        if(g) break;
        d(t);
    }
}
main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    d(1);
    for(int i=1;i<=n;i++)
        if(a[i]==0)
            s++;
    if(s==0)
        cout<<"Yes";
    else
        cout<<"No";
	return 0;
}
