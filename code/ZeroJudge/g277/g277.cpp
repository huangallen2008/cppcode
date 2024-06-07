#include<bits/stdc++.h>
using namespace std;
int n,a[300005];
long long d[300005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
void s(int l,int h) {
    if(l==h-1) {
        printf("%d",a[l]);
        return;
    }
    pq.pop();
    while(pq.top().second>=h || pq.top().second<l) { pq.pop(); }
    if(d[h-1]-d[pq.top().second]>=d[pq.top().second-1]-d[l-1])
        s(pq.top().second+1,h);
    else
        s(l,pq.top().second);
}
main()
{
    d[0]=0;
    pq.push({0,0});
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        d[i]=d[i-1]+a[i];
        pq.push({a[i],i});
    }
    s(1,n+1);
	return 0;
}
