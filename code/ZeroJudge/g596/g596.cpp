#include<bits/stdc++.h>
using namespace std;
int m,n,h,an=0,ba=0;
struct s {
    bool g=0,c=0,r=0;
};
s a[105][105];
int sum(s a) { return a.g+a.c+a.r; }
bool ht(s a) { return a.g||a.c||a.r; }
main()
{
    cin>>m>>n>>h;
    for(int i=0;i<h;i++) {
        an=0;
        int x,y,z,x1,y1;
        cin>>x>>y>>z;
        if(z==0) {
            a[x][y]={1,0,0};
            x1=x;
            y1=y;
            while(--x1>=0)
                if(a[x1][y1].g) {
                    for(int j=x1+1;j<x;j++) {
                        a[j][y1].c=1;
                    }
                    break;
                }
            x1=x;
            y1=y;
            while(++x1<m)
                if(a[x1][y1].g) {
                    for(int j=x+1;j<x1;j++)
                        a[j][y1].c=1;
                    break;
                }
            x1=x;
            y1=y;
            while(--y1>=0)
                if(a[x1][y1].g) {
                    for(int j=y1+1;j<y;j++)
                        a[x1][j].r=1;
                    break;
                }
            x1=x;
            y1=y;
            while(++y1<n)
                if(a[x1][y1].g) {
                    for(int j=y+1;j<y1;j++)
                        a[x1][j].r=1;
                    break;
                }
        }
        else {
            a[x][y]={0,0,0};
            x1=x;
            y1=y;
            while(--x1>=0)
                if(a[x1][y1].g) {
                    for(int j=x1+1;j<x;j++)
                        a[j][y1].c=0;
                    break;
                }
            x1=x;
            y1=y;
            while(++x1<m)
                if(a[x1][y1].g) {
                    for(int j=x+1;j<x1;j++)
                        a[j][y1].c=0;
                    break;
                }
            x1=x;
            y1=y;
            while(--y1>=0)
                if(a[x][y1].g) {
                    for(int j=y1+1;j<y;j++)
                        a[x][j].r=0;
                    break;
                }
            x1=x;
            y1=y;
            while(++y1<n)
                if(a[x1][y1].g) {
                    for(int j=y+1;j<y1;j++)
                        a[x1][j].r=0;
                    break;
                }
        }
        for(int j=0;j<m;j++)
            for(int k=0;k<n;k++)
                if(ht(a[j][k]))
                    an++;
        ba=max(ba,an);
    }
    cout<<ba<<"\n"<<an<<"\n";
    return 0;
}
