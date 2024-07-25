#include<bits/stdc++.h>
using namespace std;
struct Al
{
	string s;
	int a;
	Al(){}
	Al(string ss,int n)
	{
		s=ss;
		a=0;
		int b[n]={};
		for(int i=0;i<n;i++)
		{
			b[i]=ss[i];
			for(int j=0;j<=i;j++)
				if(b[j]>b[i])
					a++;
		}
	}
};
int main()
{
	int t;
    string sss,ans="";
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m;
		cin>>n>>m;
		Al a[m];
		int b[m]={},bc=0;
		for(int j=0;j<m;j++)
		{
			cin>>sss;
			a[j]=Al(sss,n);
		}
		for(int j=0;j<m;j++)
		{
			for(int k=m-1;k>j;k--)
		    {
		    	if(a[k].a<a[k-1].a)
		    	{
		    		int ii=a[k].a;
		    		a[k].a=a[k-1].a;
		    		a[k-1].a=ii;
		    		string ss=a[k].s;
		    		a[k].s=a[k-1].s;
		    		a[k-1].s=ss;
				}
			}
			ans+=a[j].s+"\n";
		}
		ans+"\n";
	}
	cout<<ans;
	return 0;
}
