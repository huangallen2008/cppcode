#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
#define oparr2(x) cout<<(#x)<<":";for(auto &[allen1,allen2]:(x)) cout<<'{'<<allen1<<','<<allen2<<"} , ";cout<<"size="<<(x.size())<<endl;
const int mod=1e9+7;
const int maxn=9;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k;
vector<bitset<maxn>> m,vis;
vector<pii> stk;
vector<pii> dir={{1,0},{0,1},{-1,0},{0,-1}};
int an=0;
bool nok(int x,int y) {
    return x<0||x>=n||y<0||y>=n;
}
void dfs(int it,int cnt) {
    if(cnt==k) {
        an++;
        return;
    }
    if(it==stk.size()) return;
    dfs(it+1,cnt);
    int ori_sz=stk.size();
    auto [x,y]=stk[it];
    for(auto [dx,dy]:dir) {
        auto [nx,ny]=make_pair(x+dx,y+dy);
        if(nok(nx,ny)||!m[nx][ny]||vis[nx][ny]) continue;
        vis[nx][ny]=1;
        stk.pb({nx,ny});
    }
    dfs(it+1,cnt+1);
    while(stk.size()>ori_sz) {
        auto &[xx,yy]=stk.back();
        vis[xx][yy]=0;
        stk.pop_back();
    }
}
signed main() {
    IOS();
    cin>>n>>k;
    m=vector<bitset<maxn>>(n);
    vis=vector<bitset<maxn>>(n);
    REP(i,n) {
        REP(j,n) {
            char c;
            cin>>c;
            if(c=='.') m[i][j]=1;
        }
    }
    REP(i,n) { 
        REP(j,n) {
            if(m[i][j]) {
                stk.clear();
                stk.pb({i,j});
                vis[i][j]=1;
                dfs(0,0);
            }
        }
    }
    cout<<an<<'\n';
    return 0;
}
