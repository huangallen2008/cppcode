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
vector<vector<int>> g;
vector<int> cur;
string an="";
vector<bool> vis;
void dfs(int u) {
    for(;cur[u]<2;cur[u]++) {
        int v=g[u][cur[u]];
        int id=(u<<1)|cur[u];
        if(vis[id]) continue;
        vis[id]=1;
        dfs(v);
        an+='0'+(v&1);
    }
}
signed main() {
    IOS();
    int n;
    cin>>n;
    if(n==1) {
        cout<<"01\n";
        return 0;
    }
    int N=1<<n-1;
    g=vector<vector<int>>(N);
    cur=vector<int>(N);
    vis=vector<bool>(N<<1);
    REP(i,N) {
        int k=(i<<1)&~N;
        g[i].pb(k);
        g[i].pb(k|1);
    }
    dfs(0);
    REP(i,n-1) an+='0';
    reverse(ALL(an));
    cout<<an<<'\n';
    return 0;
}
