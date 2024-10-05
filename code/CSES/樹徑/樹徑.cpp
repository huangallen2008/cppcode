#include<bits/stdc++.h>
using namespace std;
pair<int,int> p;
vector<int> v[200001];
void dfs(int a,int o,int r) {
	if(v[a].size()==1 && r) {
		if(r>p.second){
			p.first=a;
			p.second=r;
		}
		return ;
	}
	for(int i=0;i<v[a].size();i++)
		if(v[a][i]!=o)
		    dfs(v[a][i],a,r+1);
}
main() {
	int n,a,b;
	p.first=0;
	p.second=0;
	cin>>n;
	for(int i=0;i<n-1;i++) {
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,-1,0);
	dfs(p.first,-1,0);
	cout<<p.second<<endl;
	return 0;
}
