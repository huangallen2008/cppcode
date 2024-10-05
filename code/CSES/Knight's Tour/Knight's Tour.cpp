#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define int long long
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
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
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
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
vector<vector<int>> vis(8,vector<int>(8)),deg(8,vector<int>(8,0));
vector<pii> dir={{2,1},{1,2},{2,-1},{-1,2},{-2,1},{1,-2},{-2,-1},{-1,-2}};
bool ok(int x,int y) {
    if(x<0||y<0||x>=8||y>=8) return 0;
    return 1;
}
void upd(int x,int y,int v) {
    for(auto di:dir) {
        if(ok(x+di.f,y+di.s))deg[x+di.f][y+di.s]+=v;
    }
}
bool dfs(int x,int y) {
    if(vis[x][y]==64) return 1;
    vector<pii> nd;
    REP(i,8) {
        pii di=dir[i];
        int xx=x+di.f,yy=y+di.s;
        if(!ok(xx,yy)) continue;
        if(vis[xx][yy]) continue;
        nd.pb({deg[xx][yy],i});
    }
    if(nd.size()==0) return 0;
    sort(ALL(nd));
    for(auto [dg,id]:nd) {
        pii di=dir[id];
        int xx=x+di.f,yy=y+di.s;
        vis[xx][yy]=vis[x][y]+1;
        upd(xx,yy,1);
        bool ret=dfs(xx,yy);
        if(ret) return 1;
        else {
            vis[xx][yy]=0;
            upd(xx,yy,-1);
        }
    }
    return 0;
}
signed main() {
    IOS();
    REP(i,8) {
        REP(j,8) {
            for(auto di:dir) {
                if(ok(i+di.f,j+di.s)) deg[i][j]++;
            }
        }
    }
    int x,y;
    cin>>x>>y;
    x--,y--;
    swap(x,y);
    vis[x][y]=1;
    bool ret=dfs(x,y);
    if(ret) {
        REP(i,8) {
            REP(j,8) cout<<vis[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}
