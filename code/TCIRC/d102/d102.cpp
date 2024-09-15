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
const int maxn=5e4+5;
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
int x,y,z;
int cp=0;
vector<vector<int>> g(maxn),v(maxn);
void mt(int u,int l) {
    if(u!=0 && SZ(g[u])==1) return;
    sort(ALL(g[u]));
    REP(i,SZ(g[u])) {
        if(g[u][i]==l) continue;
        v[u].pb(g[u][i]);
        mt(g[u][i],u);
    }
}
void d(int u) {
    if(SZ(v[u])==0) {
        cout<<u<<" ";
        return;
    }
    cout<<u<<" ";
    REP(i,SZ(v[u])) {
        d(v[u][i]);
        cout<<u<<" ";
    }
}
main() {
    IOS();
    cin>>n;
    REP(i,n-1) {
        cin>>x>>y>>z;
        cp+=z;
        g[x].pb(y);
        g[y].pb(x);
    }
    cout<<cp*2<<"\n";
    mt(0,-1);
    d(0);
    return 0;
}
