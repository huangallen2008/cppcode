#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
// #define int long long
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<pii> dir={{0,1},{0,-1},{1,0},{-1,0}};
int n;
bool ok(int x,int y) {
    if(x<0||y<0||x>=n||y>=n) return 0;
    return 1;
}
signed main() {
    IOS();
    cin>>n;
    vector<vector<bool>> m(n,vector<bool>(n));
    vector<vector<int>> dis(n,vector<int>(n,inf));
    queue<pii> q;
    REP(i,n) {
        REP(j,n) {
            int c;
            cin>>c;
            if(c==1) {
                q.push({i,j});
                dis[i][j]=0;
            }
            if(c!=-1) m[i][j]=1;
        }
    }
    int an=0;
    while(q.size()) {
        auto [x,y]=q.front();
        q.pop();
        for(auto di:dir) {
            int xx=x+di.f,yy=y+di.s;
            if(!ok(xx,yy)) continue;
            if(!m[xx][yy]) continue;
            if(dis[xx][yy]<=dis[x][y]+1) continue;
            dis[xx][yy]=dis[x][y]+1;
            q.push({xx,yy});
        }
    }
    REP(i,n) REP(j,n) if(m[i][j]) an=max(an,dis[i][j]);
    cout<<an<<'\n';
    return 0;
}
/*
3
0 0 1
0 -1 0
-1 1 0

*/
