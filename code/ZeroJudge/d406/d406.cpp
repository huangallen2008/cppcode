#include<bits/stdc++.h>
using namespace std;
int s,n,m,a[105][105]={},d[4][2]={{-1,0},{0,1},{1,0},{0,-1}},cc=1,b;
main()
{
    while(cin>>s) {
        s--;
        cin>>n>>m;
        for(int i=0;i<m;i++) {
            cin>>a[0][i];
            if(a[0][i]==1) b=i;
        }
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        queue<pair<int,int>> q;
        q.push({0,b});
        while(q.size()) {
            pair<int,int> r=q.front();
            q.pop();
            for(int i=s;i<4;i++) {
                if(r.first+d[i][0]>=0 && r.first+d[i][0]<n && r.second+d[i][1]>=0 && r.second+d[i][1]<m && a[r.first+d[i][0]][r.second+d[i][1]]==1) {
                    q.push({r.first+d[i][0],r.second+d[i][1]});
                    a[r.first+d[i][0]][r.second+d[i][1]]=a[r.first][r.second]+1;
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j]==1) a[i][j]=0;
        a[0][b]=1;
        cout<<"Case "<<cc++<<":\n";
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<(j<m-1?' ':'\n');
        memset(a,0,sizeof(a));
    }
    return 0;
}
