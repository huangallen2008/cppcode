#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+9;
int n,m,si,sj,z;
vector<vector<int>> c;
vector<vector<bool>> vis;
int a;
bool ok(int i,int j) {
    if(i<0||i>=n||j<0||j>=m) return 0;
    return 1;
}
signed main()
{
    IOS();
    cin>>n>>m>>si>>sj>>z;
    si--,sj--;
    c=vector<vector<int>>(n,vector<int>(m));
    vis=vector<vector<bool>>(n,vector<bool>(m));
    REP(i,n) REP(j,m) cin>>c[i][j];
    a=c[si][sj];
    queue<pii> q;
    q.push({si,sj});
    while(q.size()) {
        int i=q.front().f,j=q.front().s;
        q.pop();
        if(!ok(i,j)||vis[i][j]) continue;
        vis[i][j]=1;
        if(c[i][j]==a) c[i][j]=z;
        else continue;
        q.push({i+1,j});
        q.push({i,j+1});
        q.push({i-1,j});
        q.push({i,j-1});
    }
    REP(i,n) {
        REP(j,m) cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
