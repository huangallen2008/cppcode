#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,p=0,a=0,an=0;
	map<int,int> m;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		m[x]++;
		m[y]--;
	}
	for(auto u : m) {
		if(p==0 && u.second>0)
		    a=u.first;
        else if(p>0 && p+u.second==0)
            an+=u.first-a;
        p+=u.second;
	}
	printf("%d",an);
	return 0;
}
