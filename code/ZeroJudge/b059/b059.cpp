#include<bits/stdc++.h>
using namespace std;
int n,sx,sy,ex,ey,a[105][105]={},d[8][2]={{3,1},{3,-1},{1,3},{-1,3},{-3,1},{-3,-1},{1,-3},{-1,-3}},w[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
main()
{
    while(cin>>n) {
        bool b=true;
        for(int i=0;i<n;i++) {
            int x,y;
            cin>>x>>y;
            a[x][y]=-1;
        }
        cin>>sx>>sy>>ex>>ey;
        a[sx][sy]=1;
        queue<pair<int,int>> q;
        q.push({sx,sy});
        while(q.size()) {
            pair<int,int> r=q.front();
            if(r.first==ex && r.second==ey) { b=false; break; }
            q.pop();
            for(int i=0;i<8;i++) {
                if(r.first+d[i][0]>=0 && r.first+d[i][0]<100 && r.second+d[i][1]>=0 && r.second+d[i][1]<100 && a[r.first+d[i][0]][r.second+d[i][1]]==0 && a[r.first+w[i/2][0]][r.second+w[i/2][1]]>=0) {
                    q.push({r.first+d[i][0],r.second+d[i][1]});
                    a[r.first+d[i][0]][r.second+d[i][1]]=a[r.first][r.second]+1;
                }
            }
        }
        if(b) cout<<"impossible\n";
        else cout<<a[ex][ey]-1<<"\n";
        memset(a,0,sizeof(a));
    }
    return 0;
}
