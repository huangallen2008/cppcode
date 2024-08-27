#include<bits/stdc++.h>
using namespace std;
main()
{
	int n,an=0,m=0;
	cin>>n;
	int a[n]={};
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]>m)
		    m=a[i];
		if(m-a[i]>an)
		    an=m-a[i];
	}
	cout<<an<<endl;
    return 0;
}
