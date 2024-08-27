#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
double n;
double c,s[N];
int ss(int a)
{
	double r=0;
	for(int i=0;i<n;i++)
	{
		if(a-(int)s[i]>0)
	        r+=pow(a-(int)s[i],2);
	    if(r>c)
	        return 0;
	}
	if(r<=c)
	    return 1;
	return 0;
}
main()
{
	cin>>n>>c;
	long long int l=0,h=0,m=0,ans=0;
	for(int i=0;i<n;i++)
	{
	    cin>>s[i];
	    if(s[i]>h)
	        h=s[i];
	}
	h+=sqrt(c);
	while(l<=h)
	{
		m=(l+h)/2;
		if(ss(m))
		{
		    l=m+1;
		    if(ans<m)
		        ans=m;
		}
		else
		    h=m-1;
	}
	cout<<ans<<endl;
	return 0;
}
