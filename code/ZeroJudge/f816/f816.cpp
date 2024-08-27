#include<bits/stdc++.h>
using namespace std;
main() {
	int d,v,e;
    priority_queue<long long,vector<long long>,greater<long long> > pq;
	long long s=0,t=0;
	cin>>d;
	for(int i=0;i<d;i++) {
	    scanf("%d%d",&v,&e);
		while(pq.size() && pq.top()<t+e) {
	    	s-=pq.top()-t;
	    	pq.pop();
		}
	    t+=e;
	    s-=e*pq.size()-v;
	    pq.push(v+t);
	    printf("%lld\n",s);
	}
	return 0;
} 
