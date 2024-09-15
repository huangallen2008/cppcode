#include <bits/stdc++.h>
using namespace std;
int n,m,a[101][101],d[4][2]={{0,1},{0,-1},{1,0},{-1,0}},h[101][101]={};
pair<int,pair<int,int>> p;
int dfs(int x,int y) {
    int t=-1;
    h[x][y]=1;
    for(int i=0;i<4;i++) if(x+d[i][0]>=0 && x+d[i][0]<n && y+d[i][1]>=0 && y+d[i][1]<m && (t==-1?true:a[x+d[i][0]][y+d[i][1]]<a[x+d[t][0]][y+d[t][1]]) && h[x+d[i][0]][y+d[i][1]]==0) t=i;
    if(t==-1) return a[x][y];
    return dfs(x+d[t][0],y+d[t][1])+a[x][y];
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    p.first=1000001;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
            if(a[i][j]<p.first) {
                p.first=a[i][j];
                p.second.first=i;
                p.second.second=j;
            }
        }
    }
    cout<<dfs(p.second.first,p.second.second);
    return 0;
}
