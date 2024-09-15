#include<bits/stdc++.h>
using namespace std;
int m,n,h,a[105]={},an=0,ba=0;
main()
{
    cin>>n>>m>>h;
    for(int i=0;i<h;i++) {
        an=0;
        int x,y,z,y1;
        cin>>y>>x>>z;
        if(z==0) {
            a[y]=2;
            y1=y;
            while(y1-1>=0) {
                y1--;
                if(a[y1]==2) {
                    for(int j=y1+1;j<y;j++)
                        a[j]=1;
                    break;
                }
            }
            y1=y;
            while(y1+1<n) {
                y1++;
                if(a[y1]==2) {
                    for(int j=y+1;j<y1;j++)
                        a[j]=1;
                    break;
                }
            }
        }
        else {
            a[y]=0;
            y1=y;
            while(y1-1>=0) {
                y1--;
                if(a[y1]==2) {
                    for(int j=y1+1;j<y;j++)
                        a[j]=0;
                    break;
                }
            }
            y1=y;
            while(y1+1<n) {
                y1++;
                if(a[y1]==2) {
                    for(int j=y+1;j<y1;j++)
                        a[j]=0;
                    break;
                }
            }
        }
        for(int j=0;j<n;j++)
            if(a[j])
                an++;
        if(an>ba)
            ba=an;
    }
    cout<<ba<<"\n"<<an<<"\n";
    return 0;
}
