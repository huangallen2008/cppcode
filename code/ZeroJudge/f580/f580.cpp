#include<bits/stdc++.h>
using namespace std;
int n,m;
struct S {
    int u=1,d=6,l=5,r=2,f=4,b=3;
    void tf() {
        int t=u; u=b; b=d; d=f; f=t;
    }
    void tr() {
        int t=u; u=l; l=d; d=r; r=t;
    }
};
main()
{
    cin>>n>>m;
    S p[n];
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        if(b>0) {
            S t=p[a-1]; p[a-1]=p[b-1]; p[b-1]=t;
        }
        else if(b==-1)
            p[a-1].tf();
        else
            p[a-1].tr();
    }
    for(int i=0;i<n;i++)
        cout<<p[i].u<<" ";
	return 0;
}
