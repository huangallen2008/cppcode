#include<bits/stdc++.h>
using namespace std;
main() {
	priority_queue<int,vector<int>,greater<int> > pq1;
	priority_queue<int> pq2;
	int n,a,l=-1;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a;
		pq1.push(a);
		pq2.push(a);
	}
	while(pq1.size()) {
		cout<<pq1.top()<<" ";
		pq1.pop();
	}
	cout<<endl;
	while(pq2.size()) {
		int u=pq2.top();
		if(u!=l)
			cout<<u<<" ";
		l=u;
		pq2.pop();
	}
	cout<<endl;
	return 0;
}
