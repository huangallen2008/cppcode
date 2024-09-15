#include<bits/stdc++.h>
using namespace std;
char t1,t2;
vector<pair<int,int>> v[26];
int n,s,t,an=0;
int dfs(int u,int p) {
    if(v[u].size()==0) return p;
    int r=p;
    for(auto a:v[u]) {
        int tt=dfs(a.first,p+a.second);
        if(tt>r) r=tt;
    }
    return r;
}
main()
{
    cin>>t1>>n;
    s=t1-'A';
    for(int i=0;i<n;i++) {
        cin>>t1>>t2>>t;
        v[t1-'A'].push_back({t2-'A',t});
    }
    cout<<dfs(s,0);
    return 0;
}
