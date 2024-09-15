#include<bits/stdc++.h>
using namespace std;
int n,x,d[200002]={};
vector<int> v[200002];
int a(int u) {
    if(v[u].size()==0) {
		d[u]=0;
		return 0;
	}
	int an=0;
	for(int i=0;i<v[u].size();i++)
		an+=a(v[u][i])+1;
	d[u]=an;
	return an;
}
main() {
	cin>>n;
	for(int i=2;i<=n;i++) {
		cin>>x;
		v[x].push_back(i);
	}
	cout<<a(1)<<" ";
	for(int i=2;i<=n;i++)
		cout<<d[i]<<" ";
	return 0;
}
