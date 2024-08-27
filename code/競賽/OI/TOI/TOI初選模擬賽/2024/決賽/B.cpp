#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxv=4e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
Graph g;
vector<int> p,a,d0,d1,sum,an,dif;
int base=0;
int n,c;
void dfs(int u) {
    for(int v:g[u]) {
        dfs(v);
        sum[u]+=sum[v];
    }
    sum[u]+=a[u];
    int x=0,y=0;
    if(sum[u]%c&&u>0) x++;
    if((sum[u]+1)%c&&u>0) y++;
    base+=x;
    dif[u]=y-x;
}
void dfs2(int u,int d) {
    an[u]=d;
    for(int v:g[u]) {
        dfs2(v,d+dif[v]);
    }
}
signed main() {
    IOS();
    cin>>n>>c;
    g=Graph (n);
    p=vector<int>(n);
    a=vector<int>(n);
    sum=vector<int>(n);
    dif=vector<int>(n);
    an=vector<int>(n);

    REP1(i,n-1) {
        cin>>p[i];
        p[i]--;
        g[p[i]].pb(i);
    }
    REP(i,n) cin>>a[i];
    dfs(0);
//    oparr(sum)
    dfs2(0,base);
    REP(i,n) cout<<an[i]<<'\n';
    return 0;
}
