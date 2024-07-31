#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","w",stdout);
	cout<<"200000 200000\n";
	int a=200000,b=1;
	for(int i=1;i<=200000;i++)
	{
		cout<<a;
		if(i<200000) cout<<" ";
		if(i>190000) a=200000/550;
	}
	cout<<"\n";
	int m=50;
	for(int a=0;a<m;a++) for(int i=1;i<=200000/m;i++) cout<<2e5-i+1<<" "<<505+a<<"\n";
}