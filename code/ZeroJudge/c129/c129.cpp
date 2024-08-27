#include<bits/stdc++.h>
using namespace std;
int m,n,a[105][105]={},d[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}},an=0;
void dfs(int i,int j) {
    if(i<0 || j<0 || i>=m || j>=n || a[i][j]==0) return;
    a[i][j]=0;
    for(int k=0;k<8;k++)
        dfs(i+d[k][0],j+d[k][1]);
}
main()
{
    cin>>m>>n;
    while(m!=0) {
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                char tt;
                cin>>tt;
                a[i][j]=(tt=='*'?0:1);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(a[i][j]) { dfs(i,j); an++; }
            }
        }
        cout<<an<<"\n";
        memset(a,0,sizeof(a));
        an=0;
        cin>>m>>n;
    }
    return 0;
}
