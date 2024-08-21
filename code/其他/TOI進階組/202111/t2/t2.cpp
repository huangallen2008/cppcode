#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m,an=0;
    cin>>n>>m;
    priority_queue<pair<int,pair<int,int> > > pq;
    for(int i=0;i<n+m;i++) {
        int x,y;
        cin>>x>>y;
        pq.push({y-x,{x,y}});
    }
    for(int i=0;i<n;i++) {
        an+=pq.top().second.first;
        pq.pop();
    }
    for(int i=0;i<m;i++) {
        an+=pq.top().second.second;
        pq.pop();
    }
    cout<<an;
	return 0;
}
