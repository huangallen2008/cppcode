#include<bits/stdc++.h>
using namespace std;
int p[2]={};
void dfs(int a,int o,vector<int> v[],int r) {
	if(v[a].size()==1 && r) {
		if(r>p[1]){
			p[0]=a;
			p[1]=r;
		}
		return ;
	}
	for(int i=0;i<v[a].size();i++)
		if(v[a][i]!=o)
		    dfs(v[a][i],a,v,r+1);
}
main() {
	int n,a,b;
	while(cin>>n) {
	    vector<int> v[n];
		for(int i=0;i<n-1;i++) {
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(0,-1,v,0);
		dfs(p[0],-1,v,0);
		printf("%d\n",p[1]);
		p[0]=0;
		p[1]=0;
	}
	return 0;
}
