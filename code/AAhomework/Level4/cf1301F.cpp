#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
//#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=998244353;
const int maxn=1e3+5;
const int inf=(1ll<<62);
const int iinf=(1<<30);
#define inf iinf
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int n,m,k,q;
pii dir[]={{0,1},{0,-1},{1,0},{-1,0}};
int a[maxn][maxn],dis[41][maxn][maxn];
vector<pii> ci[41];
bool ok(int x,int y) {
    if(x<0||x>=n||y<0||y>=m) return 0;
    return 1;
}
void bfs(int c) {
    REP(i,maxn) REP(j,maxn) dis[c][i][j]=inf;
    deque<pii> dq;
    dq.push_back({n,c});
    dis[c][n][c]=0;
    while(dq.size()) {
        auto [x,y]=dq.front();
        dq.pop_front();
        if(x==n) {
            for(auto [nx,ny]:ci[y]) {
                if(!ok(nx,ny)) continue;
                if(dis[c][nx][ny]<=dis[c][x][y]+1) continue;
                dis[c][nx][ny]=dis[c][x][y]+1;
                dq.push_back({nx,ny});
            }
        }
        else {
            int cx=n,cy=a[x][y];
            if(dis[c][cx][cy]>dis[c][x][y]) {
                dis[c][cx][cy]=dis[c][x][y];
                dq.push_front({cx,cy});
            }
            REP(di,4) {
                int nx=x+dir[di].f,ny=y+dir[di].s;
                if(!ok(nx,ny)) continue;
                if(dis[c][nx][ny]<=dis[c][x][y]+1) continue;
                dis[c][nx][ny]=dis[c][x][y]+1;
                dq.push_back({nx,ny});
            }
        }
    }
}
signed main() {
    IOS();
    cin>>n>>m>>k;
    REP(i,n) {
        REP(j,m) {
            cin>>a[i][j];
            a[i][j]--;
            ci[a[i][j]].pb({i,j});
        }
    }
    REP(i,k) bfs(i);
    cin>>q;
    REP(i,q) {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--,c1--,r2--,c2--;
        int an=abs(r1-r2)+abs(c1-c2);
        REP(c,k) {
            int r=dis[c][r1][c1]+dis[c][r2][c2]-1;
//            int d1=dis[c][r1][c1],d2=dis[c][r2][c2];op(c)op(d1)ope(d2)
            an=min(an,r);
        }
        cout<<an<<'\n';
    }
    return 0;
}
