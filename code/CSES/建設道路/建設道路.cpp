#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,a[100005]={};
vector<int> v[100005],an;
void d(int u) {
	a[u]=1;
	for(int i=0;i<v[u].size();i++)
		if(a[v[u][i]]==0)
		    d(v[u][i]);
}
main() {
	cin>>n>>m;
	for(int i=0;i<m;i++) {
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++) {
		if(a[i]==0) {
			d(i);
			an.push_back(i);
		}
	}
	if(an.size()>1) {
		cout<<an.size()-1<<endl<<an[0]<<" ";
		for(int i=1;i<an.size()-1;i++)
		    cout<<an[i]<<endl<<an[i]<<" ";
		cout<<an[an.size()-1];
	}
	else
	    cout<<"0";
    return 0;
}

