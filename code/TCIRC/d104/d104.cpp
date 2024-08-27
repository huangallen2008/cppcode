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
#define lbs(x,y) *lower_bound(ALL(x),y)
#define lb(x,y) lower_bound(ALL(x),y)-x.begin()
#define ubs(x,y) *upper_bound(ALL(x),y)
#define ub(x,y) upper_bound(ALL(x),y)-x.begin()
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=1ll<<62;
const int maxn=1e5+5;
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
}
int n;
int x,y;
int rt=0;
vector<vector<pii>> v(maxn),g(maxn);
int c[maxn]={};
void ce(int u) {
    int r=0;
    REP(i,SZ(v[u])) {
        ce(v[u][i].f);
        r+=c[v[u][i].f];
    }
    c[u]=r+1;
}
int d(int u,int cl) {
    REP(i,SZ(v[u])) {
        if(c[v[u][i].f]>=(c[u]+cl+1)/2) {
            return d(v[u][i].f,cl+c[u]-c[v[u][i].f]);
        }
    }
    return u;
}
int rm(int u,int l) {
    REP(i,SZ(g[u])) {
        if(g[u][i].f==l) continue;
        v[u].pb(g[u][i]);
        rm(g[u][i].f,u);
    }
}
int sm(int u) {
    int r=0;
    REP(i,SZ(v[u])) {
        r+=sm(v[u][i].f)+c[v[u][i].f]*v[u][i].s;
    }
    return r;
}
main() {
    IOS();
    cin>>n;
    REP1(i,n-1) {
        cin>>x>>y;
        v[x].pb({i,y});
        g[i].pb({x,y});
        g[x].pb({i,y});
    }
    ce(0);
    rt=d(0,0);
    v=vector<vector<pii>>(maxn);
    rm(rt,-1);
    ce(rt);
    cout<<rt<<"\n"<<sm(rt)<<"\n";
    return 0;
}
