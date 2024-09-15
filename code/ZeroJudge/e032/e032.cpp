#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=1e3+5;
const int mod=1e9+7;
int n,k;
int an=0;
vector<vector<pii>> g;
vector<vector<int>> s;
vector<int> vis,dep,dis0;
vector<vector<int>> f;
void build_tree(int u) {
    vis[u]=1;
    REP(i,g[u].size()) {
        if(vis[g[u][i].f]) continue;
//        t[u].pb(g[u][i]);
        dep[g[u][i].f]=dep[u]+1;
        f[g[u][i].f][0]=u;
        dis0[g[u][i].f]=dis0[u]+g[u][i].s;
        build_tree(g[u][i].f);
    }
}
void up(int &a,int x) {
    REP(i,20) if((1<<i)&x) a=f[a][i];
}
int find_lca(int a,int b) {
    if(dep[a]>dep[b]) swap(a,b);
    up(b,dep[b]-dep[a]);
    if(a==b) return a;
    RREP(i,20) {
        if(f[a][i]!=f[b][i]) {
            a=f[a][i];
            b=f[b][i];
        }
    }
    return f[a][0];
}
int dis(int a,int b) {
    return dis0[a]+dis0[b]-2*dis0[find_lca(a,b)];
}
pii max_dis(vector<int> s,int u) {
    pii an={-1,-1};
    REP(i,s.size()) {
        int dist=dis(u,s[i]);
        if(dist>an.f) an={dist,s[i]};
    }
    return an;
}
vector<int> ist;
int dfs(int u) {
    vis[u]=1;
    int an=0;
    REP(i,g[u].size()) {
        if(vis[g[u][i].f]) continue;
        int r=dfs(g[u][i].f);
        if(ist[g[u][i].f]||r>0) an+=g[u][i].s;
        an+=r;
    }
    return an;
}
int sum_dis(vector<int> s) {
    int an=0;
    ist=vector<int>(n);
    REP(i,s.size()) ist[s[i]]=1;
    queue<int> q;
    vis=vector<int>(n);
    return dfs(s[0]);
}
signed main()
{
    IOS();
    cin>>n>>k;
    g=vector<vector<pii>>(n);
    dep=vector<int>(n);
    dis0=vector<int>(n);
    f=vector<vector<int>>(n,vector<int>(20));
    s=vector<vector<int>>(k);
    REP(i,n-1) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
        g[b].pb({a,c});
    }
    REP(i,k) {
        int t;
        cin>>t;
        REP(j,t) {
            int x;
            cin>>x;
            s[i].pb(x);
        }
    }
    vis=vector<int>(n);
    dep[0]=0;
    f[0][0]=0;
    dis0[0]=0;
    build_tree(0);
    REP1(i,19) REP(j,n) f[j][i]=f[f[j][i-1]][i-1];
    REP(i,k) {
        pii p=max_dis(s[i],s[i][0]);
//        cout<<p.f<<" "<<p.s<<"\n";
        p=max_dis(s[i],p.s);
        an+=sum_dis(s[i])*2-p.f;
//        cout<<sum_dis(s[i])<<" "<<p.f<<"\n";
    }
    cout<<an<<"\n";
    return 0;
}
