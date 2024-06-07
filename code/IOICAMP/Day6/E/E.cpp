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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=998244353;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}

Graph g0,g;
int n,k;
vector<int> sz;
vector<vector<int>> t;
void dfs(int u,int p) {
    for(int v:g[u]) {
        if(v==p) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        t[u].pb(sz[v]);
    }
    t[u].pb(n-sz[u]);
}
signed main() {
    IOS();
    cin>>n>>k;
    g0=Graph(n);
    g=Graph(n);
    sz=vector<int>(n,1);
    t=vector<vector<int>>(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    int an=0;
//    oparr(sz)
//    REP(i,n) {
//        cout<<i<<":";
//        for(int v:t[i]) cout<<v<<' ';cout<<'\n';
//    }
    REP(i,n) {
        int r=0;
        for(int v=0;v<t[i].size();v++) {
            r=md(r-pw(t[i][v],k));
//                op(t[i][v])
        }
        for(int u=0;u<t[i].size();u++) {
            int x=pw(t[i][u],k);
            int y=pw(n-t[i][u],k);
            int l=md(y+r+pw(t[i][u],k));
//            op(y)
//            entr
            an=(an+x*l)%mod;
//            op(i)ope(x*y)
        }
    }
    an=((an*pw(2,k-1))%mod+mod)%mod;
    cout<<an<<'\n';
//    REP1(i,20) cout<<(an*i)%mod<<'\n';
    return 0;
}
