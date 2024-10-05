#include<bits/stdc++.h>
using namespace std;
#define int long long
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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
int h,w,t;
bool ok(int x,int y) {
    if(x<0||x>=h||y<0||y>=w) return 0;
    return 1;
}
signed main() {
    IOS();
    cin>>h>>w;
    queue<pii> q;
    vector<vector<int>> m(h,vector<int>(w));
    REP(i,h) {
        REP(j,w) {
            char c;
            cin>>c;
            if(c=='*') m[i][j]=-2;
            else {
                m[i][j]=-1;
                q.push({i,j});
            }
        }
    }
    cin>>t;
    vector<pii> dir={{1,0},{0,1},{-1,0},{0,-1}};
    while(q.size()) {
        auto [x,y]=q.front();
        q.pop();
        REP(i,4) {
            int xx=x+dir[i].f,yy=y+dir[i].s;
            if(!ok(xx,yy)) continue;
            if(m[xx][yy]!=-2) continue;
            m[xx][yy]=(m[x][y]+1)%t;
            q.push({xx,yy});
        }
    }
    vector<int> cnt(t);
    REP(i,h) REP(j,w) if(m[i][j]!=-1) cnt[m[i][j]]++;
    REP(i,t) cout<<cnt[i]<<' ';
    cout<<'\n';
    return 0;
}
