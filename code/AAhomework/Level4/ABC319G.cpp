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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
set<int> g[maxn];
set<int> unvis;
vector<int> dis,way;
vector<vector<int>> le;
Graph g2;
void bfs() {
    queue<int> q;
    q.push(0);
    while(q.size()) {
        int u=q.front();
        q.pop();
        vector<int> del;
        for(int v:unvis) {
            if(g[u].count(v)) continue;
            del.pb(v);
            dis[v]=dis[u]+1;
            q.push(v);
        }
        for(int v:del)unvis.erase(v);
    }
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    g2=Graph(n);
    dis=vector<int>(n,inf);
    way=vector<int>(n);
    dis[0]=0,way[0]=1;
    REP1(i,n-1) unvis.insert(i);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].insert(v);
        g[v].insert(u);
        g2[u].pb(v);
        g2[v].pb(u);
    }
    bfs();
    int spd=dis[n-1];
    if(spd==inf) {
        cout<<"-1\n";
        return 0;
    }
    le=vector<vector<int>>(n+1);
    REP(i,n) le[dis[i]].pb(i);
    REP(i,spd) {
        int sum=0;
        for(int &u:le[i]) {
            for(int &v:g2[u]) {
                if(dis[v]!=dis[u]+1) continue;
                way[v]=md(way[v]-way[u]);
            }
            sum=md(sum+way[u]);
        }
        for(int &v:le[i+1]) way[v]=md(way[v]+sum);
    }
    cout<<way[n-1]<<'\n';
    return 0;
}
