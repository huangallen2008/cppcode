#include<bits/stdc++.h>
using namespace std;
int n,k,a=0;
main()
{
	queue<int> q;
	map<int,bool> m;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		q.push(x);
		while(m[x]) {
			m[q.front()]=false;
			q.pop();
		}
		m[x]=true;
		if(q.size()>a)
            a=q.size();
	}
	printf("%d",a);
	return 0;
}
