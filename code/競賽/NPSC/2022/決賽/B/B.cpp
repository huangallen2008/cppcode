#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e5+5;
const ll mod=1e9+7;
struct P {
    int x,y,b;
};
int n,m,b;
int si,sj,ei,ej;
vector<vector<int>> a,c;
vector<vector<vector<int>>> an;
vector<pii> di={{0,1},{1,0},{0,-1},{-1,0}};
bool ok(int x,int y){
    if(x<0||x>=n||y<0||y>=m) return 0;
    return 1;
}
int aan() {
    REP(i,b) if(a[ei][ej]) return a[ei][ej];
}
signed main()
{
    IOS();
    cin>>n>>m>>b;
    a=vector<vector<int>>(n,vector<int>(m));
    c=vector<vector<int>>(n,vector<int>(m));
    an=vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(b+1,inf)));
    REP(i,n) {
        REP(j,m) {
            cin>>a[i][j];
            if(a[i][j]==n*m) {
                si=i;sj=j;
            }
            if(a[i][j]==1) {
                ei=i;ej=j;
            }
        }
    }
    REP(i,n) REP(j,m) cin>>c[i][j];
    queue<P> q;
    q.push({si,sj,b});
    an[si][sj][b]=1;
    while(q.size()) {
        int x=q.front().x,y=q.front().y,r=q.front().b;
        q.pop();
        cout<<x<<" "<<y<<" "<<r<<"\n";
        if(r<0) continue;
        REP(d,4) {
            int xx=x+di[d].f,yy=y+di[d].s;
            if(ok(xx,yy)) {
                if(a[xx][yy]==a[x][y]-1) {
                    an[xx][yy][r]=an[x][y][r]+1;
                    q.push({xx,yy,r});
                }
                else if(a[xx][yy]==a[x][y]+1) continue;
                else {
                    if(r<c[xx][yy]) continue;
                    an[xx][yy][r-c[xx][yy]]=an[x][y][r]+1;
                    q.push({xx,yy,r-c[xx][yy]});
                }
            }
        }
    }
    REP(i,n) {
        REP(j,m) cout<<an[i][j][0]<<" ";cout<<"\n";
    }
    cout<<aan<<"\n";
    return 0;
}
/*
4 4 5
12 11 2 1
13 10 3 4
14 9 8 5
15 16 7 6
5 5 4 4
3 5 1 5
2 5 2 4
4 4 3 2

8

5 6 11
1 2 3 4 5 6
22 21 20 19 18 7
23 14 15 16 17 8
24 13 12 11 10 9
25 26 27 28 29 30
2 7 3 6 2 3
7 5 2 7 2 2
5 4 1 5 6 10
4 7 4 6 5 4
1 7 5 10 3 5

10
*/
