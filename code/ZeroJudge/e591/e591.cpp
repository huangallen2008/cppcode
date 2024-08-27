#include<bits/stdc++.h>
using namespace std;
main() {
    int T;
    cin>>T;
    while(T--) {
    	int n,s=0,an=0;
    	cin>>n;
    	int a[n]={};
    	for(int i=0;i<n;i++) {
    		cin>>a[i];
    		if(s<a[i]) {
    		    an++;
    		    s+=a[i];
			}
		}
		cout<<an<<endl;
	}
    return 0;
}
