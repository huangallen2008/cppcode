#include<bits/stdc++.h>
using namespace std;
int sor[]={4,5,3,6,2,7,1,8},g;
struct so {
	bool operator()(pair<int,int> a,pair<int,int> b) const {
		return sor[a.second/g]>sor[b.second/g];
	}
};
main() {
	int n,x,p=0;
	double y;
	cin>>n;
	g=(n-1)/8+1;
	priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > pq;
	priority_queue<pair<int,int>,vector<pair<int,int> >,so > t[g];
	for(int i=0;i<n;i++) {
		cin>>x>>y;
		pq.push({y,x}); 
	}
	while(pq.size()) {
		t[(p/g)%2*g-(2*((p/g)%2)-1)*(p%g)-(p/g)%2].push({pq.top().second,p});
		pq.pop();
		p++;
	}
	for(int i=0;i<g;i++) {
		cout<<i+1<<" ";
		while(t[i].size()) {
			cout<<t[i].top().first<<" ";
			t[i].pop();
		}
		cout<<endl;
	}
	return 0;
}
