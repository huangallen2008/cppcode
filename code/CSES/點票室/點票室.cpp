#include<bits/stdc++.h>
using namespace std;
int n,m,h[1005][1005]={},d[4][2]={{0,1},{1,0},{0,-1},{-1,0}},an=0;
string a[1005];
void g(int i,int j) {
	if(i<0 || i>=n || j<0 || j>=m || h[i][j]!=0) return;
	h[i][j]=1;
	for(int x=0;x<4;x++)
	    g(i+d[x][0],j+d[x][1]);
	
}
main() {
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			char t;
			cin>>t;
			if(t=='#')
			    h[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(h[i][j]==0) {
			    g(i,j);
			    an++;
			}
		}
	}
	cout<<an;
    return 0;
}
