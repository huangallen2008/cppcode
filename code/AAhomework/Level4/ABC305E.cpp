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
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
bool vis[maxn];
vector<int> c[maxn],g[maxn];
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
//    Graph g(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
//    vector<vector<int>> c(n+1);
//    vector<bool> vis(n);
    REP(i,k) {
        int p,h;
        cin>>p>>h;
        p--;
        c[h].pb(p);
    }
    RREP1(i,n) {
        for(int &u:c[i]) {
            vis[u]=1;
            for(int &v:g[u]) {
                if(vis[v]) continue;
                vis[v]=1;
                if(i>1)c[i-1].pb(v);
            }
        }
    }
    vector<int> an;
    REP(i,n) if(vis[i]) an.pb(i+1);
    cout<<an.size()<<'\n';
    for(int &x:an) cout<<x<<' ';
    cout<<'\n';
    return 0;
}
