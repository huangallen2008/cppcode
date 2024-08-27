#include<bits/stdc++.h>
using namespace std;
int n,t,x,y,l[100005]={},d[100005]={};
long long s;
vector<int> v[100005];
int h(int u) {
	if(v[u].size()==0)
	    return 0;
	else {
		int a=0;
		for(int i=0;i<v[u].size();i++)
		    a=max(a,h(v[u][i])+1);
		d[u]=a;
		return a;
	}
}
main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x;
		for(int j=0;j<x;j++) {
			cin>>y;
			v[i].push_back(y);
			l[y]=1;
		}
	}
	for(int i=1;i<=n;i++) {
		if(!l[i]) {
		    t=i;
		    cout<<t<<endl;
			break;
		}	
	}
	x=h(t);
	for(int i=1;i<=n;i++)
	    s+=d[i];
	cout<<s<<endl;
	return 0;
}
