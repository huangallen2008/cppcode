#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
const int maxn=1e6+5;
const ll inf=1ll<<62;
int e,x,y,z;
int st;
pair<int,int> p={-1,-1};
vector<pair<int,int>> v[maxn];
void dfs(int u,int l,int g) {
    if(u!=st && SZ(v[u])==1) {
        if(l>p.f) p={l,u};
        return;
    }
    REP(i,SZ(v[u])) {
        if(v[u][i].f!=g)
            dfs(v[u][i].f,l+v[u][i].s,u);
    }
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>e;
    REP(i,e) {
        cin>>x>>y>>z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    st=0;
    dfs(st,0,-1);
    st=p.s;
    p={0,0};
    dfs(st,0,-1);
    cout<<p.f<<"\n";
    return 0;
}
