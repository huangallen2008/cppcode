#include<bits/stdc++.h>
using namespace std;
int m[26]={},q,x;
bool bb(int a,int b) {
	return m[a-65]<m[b-65];
}
main() {
	string s,n;
	cin>>n>>s;
	for(int i=0;i<n.size();i++)
	    m[(int)n[i]-65]=i;
	int is[s.size()]={};
	for(int i=0;i<s.size();i++)
	    is[i]=(int)s[i];
	sort(is,is+s.size(),bb);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d",&x);
	    printf("%c\n",(char)is[x]);
	}
	return 0;
} 
