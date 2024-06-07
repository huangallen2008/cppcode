#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,m,c=1;
    while(cin>>n>>m) {
        int a[105][105]={},b[105][105]={};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            b[i][1]=b[i-1][1]+a[i][1];
        for(int i=1;i<=m;i++)
            b[1][i]=b[1][i-1]+a[1][i];
        for(int i=2;i<=n;i++) {
            for(int j=2;j<=m;j++) {
                b[i][j]=min(b[i-1][j],b[i][j-1])+a[i][j];
            }
        }
        cout<<"Case #"<<c++<<" :\n";
        cout<<b[n][m]<<"\n";
    }
    return 0;
}
