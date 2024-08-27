#include<bits/stdc++.h>
using namespace std;
int n,s,t,c=-1,an=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s>>t;
        pq.push({t,s});
    }
    while(pq.size()) {
        while(pq.size() && pq.top().second<=c) pq.pop();
        if(pq.size()) {
            an++;
            c=pq.top().first;
        }
    }
    cout<<an<<"\n";
    return 0;
}
