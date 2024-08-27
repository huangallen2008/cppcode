#include<bits/stdc++.h>
using namespace std;
int n,m,k,an,a[55][55]={},s[55]={};
long long A=LONG_MAX;
int mo(int b) {
	if(b<1000)
		return b*3;
	else
		return 3000+2*(b-1000);
}
int main()
{
	cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int ii=0;ii<k;ii++) {
        int aa[55][55]={};
        an=0;
        for(int i=0;i<n;i++) {
            cin>>s[i];
            for(int j=0;j<m;j++)
                aa[s[i]][j]+=a[i][j];
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                if(i==j)
                    an+=aa[i][j];
                else
                    an+=mo(aa[i][j]);
            }
        }
        if(an<A)
            A=an;
    }
    cout<<A;
    return 0;
}
