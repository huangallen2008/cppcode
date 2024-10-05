#include<bits/stdc++.h>
using namespace std;
int n,m;
pair<int,int> mi(pair<int,int> o1,pair<int,int> o2) {
	if(o2.first==0)
	    return o1;
	if(o1.first==0)
	    return o2;
	if((double)o1.first/(double)o1.second>(double)o2.first/(double)o2.second)
	    return o1;
	return o2;
}
void p(pair<int,int> p1,pair<int,int> p2) {
	int g;
	if(m==0) {
		cout<<"0\n0";
		return;
	}
	if(p1.first==0)
		cout<<"0\n";
	else {
		g=__gcd(p1.first,p1.second);
		p1.first/=g; p1.second/=g;
	    if(p1.second==1)
	        cout<<"1\n";
	    else
	        cout<<p1.first<<"/"<<p1.second<<"\n";
	}
	if(p2.first==0)
		cout<<"0";
	else {
		g=__gcd(p2.first,p2.second);
		p2.first/=g; p2.second/=g;
	    if(p2.second==1)
	        cout<<"1";
	    else
	        cout<<p2.first<<"/"<<p2.second;
	}
}
main()
{
	cin>>n>>m;
	pair<int,int> d[2][m+1]={};
	for(int i=1;i<=m;i++) {
		int x,y,k=min(i,m);
		cin>>x>>y;
		d[0][k]={d[0][k-1].first+x,d[0][k-1].second+x+y};
		d[1][k]={d[1][k-1].first+y,d[1][k-1].second+x+y};
		for(int j=min(i,m)-1;j>0;j--) {
		    d[0][j]=mi(d[0][j],{d[0][j-1].first+x,d[0][j-1].second+x+y});
			d[1][j]=mi(d[1][j],{d[1][j-1].first+y,d[1][j-1].second+x+y});
		}
	}
	for(int i=m+1;i<=n;i++) {
		int x,y;
		cin>>x>>y;
		for(int j=min(i,m);j>0;j--) {
			    d[0][j]=mi(d[0][j],{d[0][j-1].first+x,d[0][j-1].second+x+y});
				d[1][j]=mi(d[1][j],{d[1][j-1].first+y,d[1][j-1].second+x+y});
		}
	}
	p(d[0][m],d[1][m]);
	return 0;
}
