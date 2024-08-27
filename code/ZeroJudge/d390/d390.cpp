#include<bits/stdc++.h>
using namespace std;
int n,m,c[100]={};
double a=0;
main() {
	cin>>n;
	while(n--) {
		a=0;
		int p[30000]={};
		cin>>m;
		for(int i=0;i<m;i++) {
		    cin>>c[i];
		    for(int j=30000;j>=c[i];j--)
		    	if(abs((p[j-c[i]]+c[i])-j)<=abs(p[j]-j)) 
				    p[j]=p[j-c[i]]+c[i];
			a+=c[i];
		}
		a/=2;
		if(((int)a)==a)
		    cout<<2*abs(p[(int)a]-(int)a)<<endl;
		else
		    cout<<min(2*abs(p[(int)a]-(int)a),2*abs(p[(int)a+1]-(int)a+1))+1<<endl;
	}
	return 0;
}
