#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n,a[100][100]={};
int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int t=0,x,y;
char c,dc[4]={'D','L','R','U'};
struct e {
    int x=1000,y=1000;
    char l=' ';
};
e h[100][100]={};
queue<pair<int,int>> q;
string s="";
bool in(int x,int y) {
    if(x>=0 && x<n && y>=0 && y<n) return true;
    return false;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    h[0][0]={-1,-1,' '};
    cin>>n;
    x=n-1; y=n-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>c;
            if(c=='O') a[i][j]=1;
        }
    }
    q.push({0,0});
    while(q.size()) {
        int x=q.front().f,y=q.front().s;
        if(x==y && x==n-1) break;
        q.pop();
        for(int i=0;i<4;i++) {
            if(in(x+d[i][0],y+d[i][1])) {
;                if(a[x+d[i][0]][y+d[i][1]] && h[x+d[i][0]][y+d[i][1]].x>999) {
                    q.push({x+d[i][0],y+d[i][1]});
                    h[x+d[i][0]][y+d[i][1]]={x,y,dc[i]};
                }
            }
        }
    }
    while(x>=0) {
        s+=h[x][y].l;
        int tt=x;
        x=h[x][y].x;
        y=h[tt][y].y;
    }
    reverse(s.begin(),s.end()-1);
    cout<<s;
    return 0;
}
