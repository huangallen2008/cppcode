#include<bits/stdc++.h>
using namespace std;
int n,d,l=0,h,m;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>d;
    h=n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    while(l<h) {
        m=(l+h)/2;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<m;i++) pq.push(0);
        for(int i=0;i<n;i++) {
            int t=pq.top();
            pq.pop();
            pq.push(t+a[i]);
        }
        for(int i=0;i<m-1;i++) pq.pop();
        if(pq.top()<=d) h=m;
        else l=m+1;
    }
    cout<<l<<"\n";
    return 0;
}
