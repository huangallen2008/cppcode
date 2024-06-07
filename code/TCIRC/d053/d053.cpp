#include<bits/stdc++.h>
using namespace std;
int n,m;
priority_queue<int,vector<int>,greater<int>> pq;
main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++) pq.push(0);
    for(int i=0;i<n;i++) {
        int t,c=pq.top();
        cin>>t;
        pq.pop();
        pq.push(c+t);
    }
    for(int i=0;i<m-1;i++) pq.pop();
    cout<<pq.top()<<"\n";
    return 0;
}
