#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) x*x
#define pii pair<int,int>
#define MD(x,m) (x%m+m)%m
#define md(x) MD(x,mod)
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
ll pw(ll x,ll p,ll m=mod) {
    ll r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return r;
};
ll inv(ll x,ll m=mod) {
    return pw(x,m-2,m);
}
struct Bridge {
    vector<int> low,vis,dep;
    vector<pii> an;
    vector<vector<int>> g;
    Bridge(vector<vector<int>> _g) {
        getBridge(_g);
    }
    void dfs(int u,int par) {
        vis[u]=1;
        low[u]=inf;
        for(auto v:g[u]) {
            if(vis[v]) {
                if(v==par) continue;
                low[u]=min(low[u],dep[v]);
                continue;
            }
            dep[v]=dep[u]+1;
            dfs(v,u);
            if(low[v]>dep[u])
                an.pb({u,v});
            low[u]=min(low[u],low[v]);
        }
    }
    vector<pii> getBridge(vector<vector<int>> _g) {
        g=_g;
        int n=SZ(g);
        low=vector<int>(n);
        vis=vector<int>(n);
        dep=vector<int>(n);
        an.clear();
        dfs(0,-1);
        return an;
    }
};
int n,m;
int a,b;
vector<vector<int>> g;
vector<pii> an;
signed main()
{
    IOS();
    cin>>n>>m;
    while(n!=0) {
        g=vector<vector<int>>(n);
        REP(i,m) {
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        Bridge bridge1(g);
        an=bridge1.an;
        REP(i,SZ(an)) if(an[i].f>an[i].s) swap(an[i].f,an[i].s);
        sort(ALL(an));
        cout<<SZ(an);
        REP(i,SZ(an)) cout<<" "<<an[i].f<<" "<<an[i].s;
        cout<<"\n";
        cin>>n>>m;
    }
    return 0;
}
