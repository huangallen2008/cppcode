#include<bits/stdc++.h>
using namespace std;
int T,n,m,sx,sy,ex,ey,a[105][105]={},h[105][105]={},d[4][2]={{0,1},{0,-1},{1,0},{-1,0}},an;
main()
{
    cin>>T;
    while(T--) {
        an=0;
        cin>>n>>m>>sx>>sy>>ex>>ey;
        sx--;sy--;ex--;ey--;
        d[sx][sy]=1;
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            for(int j=0;j<m;j++) {
                a[i][j]=s[j]-'0';
            }
        }
        queue<pair<int,int>> q;
        q.push({sx,sy});
        h[sx][sy]=1;
        while(q.size()) {
            pair<int,int> r=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                if(r.first+d[i][0]>=0 && r.first+d[i][0]<n && r.second+d[i][1]>=0 && r.second+d[i][1]<m && a[r.first+d[i][0]][r.second+d[i][1]]==0 && h[r.first+d[i][0]][r.second+d[i][1]]==0) {
                    q.push({r.first+d[i][0],r.second+d[i][1]});
                    h[r.first+d[i][0]][r.second+d[i][1]]=h[r.first][r.second]+1;
                }
            }
        }
        cout<<h[ex][ey]<<"\n";
        for(int i=0;i<n;i++) {
            memset(h[i],0,sizeof(h[i]));
            memset(a[i],0,sizeof(a[i]));
        }
    }
    return 0;
}
