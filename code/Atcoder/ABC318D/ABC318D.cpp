#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#define Graphw vector<vector<pii>>
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
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
vector<vector<int>> d;
bitset<20> vis;
int val=0,an=0;
void dfs(int u) {
    while(u<n&&vis[u]) u++;
    if(u==n) {
        an=max(an,val);
        return;
    }
    an=max(an,val);
    dfs(u+1);
    vis[u]=1;
    for(int i=u+1;i<n;i++) {
        if(!vis[i]) {
            vis[i]=1;
            val+=d[u][i];
            dfs(u+1);
            val-=d[u][i];
            vis[i]=0;
        }
    }
    vis[u]=0;
}
signed main() {
    IOS();
    vis.reset();
    cin>>n;
    d=vector<vector<int>>(n,vector<int>(n));
    REP(i,n-1) {
        for(int j=i+1;j<n;j++) cin>>d[i][j];
    }
    dfs(0);
    cout<<an<<'\n';
    return 0;
}