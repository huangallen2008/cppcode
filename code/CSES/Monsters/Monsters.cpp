#include<bits/stdc++.h>
using namespace std;
struct ed {
    int g=-1,li,lj;
    string s="";
    int mt=-1;
};
int n,m,a[1001][1001],si,sj,ct=1;
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int t[1001][1001];
string sd[4]={"R","L","D","U"},as="";
vector<vector<ed>> e;
char c;
bool no=true;
queue<pair<int,int>> q;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(t,-1,sizeof(t));
    e=vector<vector<ed>>(1001,vector<ed>(1001,{-1,-1,-1,"",-1}));
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>c;
            if(c=='#') a[i][j]=1;
            else a[i][j]=0;
            if(c=='M') {
                q.push({i,j});
                t[i][j]=0;
            }
            else if(c=='A') {
                si=i; sj=j;
            }
        }
    }
    while(q.size()) {
        pair<int,int> f=q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int x=f.first+d[i][0],y=f.second+d[i][1];
            if(x>=0 && x<n && y>=0 && y<m && a[x][y]==0) {
                if(t[x][y]!=-1) continue;
                t[x][y]=t[f.first][f.second]+1;
                q.push({x,y});
            }
        }
    }
    q=queue<pair<int,int>>();
    q.push({si,sj});
    e[si][sj]={0,-1,-1,"",0};
    ct=1;
    while(q.size()) {
        pair<int,int> f=q.front();
        //cout<<f.first<<" "<<f.second<<"\n";
        q.pop();
        int x,y;
        for(int i=0;i<4;i++) {
            int x=f.first+d[i][0],y=f.second+d[i][1];
            if(x>=0 && x<n && y>=0 && y<m && a[x][y]==0) {
                if(e[x][y].g!=-1) continue;
                e[x][y]={e[f.first][f.second].g+1,f.first,f.second,sd[i],t[x][y]};
                q.push({x,y});
            }
        }
    }//cout<<"\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 || i==n-1 || j==0 || j==m-1) {
                if((e[i][j].g<t[i][j] || t[i][j]<0) && e[i][j].g>=0) {
                    cout<<"YES\n"<<e[i][j].g<<"\n";
                    int ti=i,tj=j;
                    while(e[ti][tj].li!=-1) {
                        as+=e[ti][tj].s;
                        int tt=ti;
                        ti=e[ti][tj].li;
                        tj=e[tt][tj].lj;
                    }
                    reverse(as.begin(),as.end());
                    cout<<as<<"\n";
                    no=false;
                    break;
                }
            }
        }
        if(!no) break;
    }
    if(no) cout<<"NO\n";
    /*for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<(t[i][j]==-1?"":" ")<<t[i][j]<<" ";
        }cout<<"\n";
    }cout<<"\n\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout<<(e[i][j].g==-1?"":" ")<<e[i][j].g<<" ";cout<<"\n";
    }*/
    return 0;
}
