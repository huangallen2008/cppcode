#include<bits/stdc++.h>
using namespace std;
int n=0,a[200005]={};
long long an=0;
priority_queue<long long,vector<long long>,greater<long long>> pq;
main()
{
    cin>>n;
    for(int i=0;i<n;i++) { cin>>a[i]; pq.push(a[i]); }
    while(pq.size()>1) {
        long long t=pq.top();
        pq.pop();
        t+=pq.top();
        pq.pop();
        an+=t;
        pq.push(t);
    }
    cout<<pq.top()<<"\n"<<an<<"\n";
    return 0;
}
