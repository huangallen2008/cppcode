#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define MD(x,m) ((x)%(m)+(m))%(m)
#define md(x) MD(x,mod)
#define lbs(x,y) *lower_bound(ALL(x),y)
#define lb(x,y) lower_bound(ALL(x),y)-x.begin()
#define ubs(x,y) *upper_bound(ALL(x),y)
#define ub(x,y) upper_bound(ALL(x),y)-x.begin()
const int mod=1e9+7;
const ll inf=2ll<<62;
const int maxn=2e5+5;
ll pw(ll x,ll p,ll m=mod) {
    ll ret=1;
    while(p>0) {
        if(p&1) {
            ret*=x;
            ret%=m;
        }
        x*=x;
        p>>=1;
    }
}
int n;
int a,b;
int dn[maxn]={};
int sz[maxn]={};
int p[maxn]={};
int mc[maxn]={};
int fh[maxn]={};
vector<vector<int>> c,gr;
void h(int u) {
    int r=0;
    REP(i,SZ(c[u])) {
        h(c[u][i]);
        r+=dn[c[u][i]];
    }
    dn[u]=r+sz[u]-1;
}
void ms(int u) {
    int r=0;
    REP(i,SZ(c[u])) {
        ms(c[u][i]);
        r+=sz[c[u][i]];
    }
    sz[u]=r+1;
}
int f(int u) {
    if(u==0) return 0;
    if(fh[u]) return fh[u];
    int r=f(p[u])+n-sz[u]-dn[u]+sz[p[u]]-sz[u]-1;
    REP(i,SZ(c[p[u]])) r+=dn[c[p[u]][i]];
    return fh[u]=r;
}
void mg(int u,int l) {
    REP(i,SZ(gr[u])) {
        if(gr[u][i]==l) continue;
        p[gr[u][i]]=u;
        c[u].pb(gr[u][i]);
        mg(gr[u][i],u);
    }
}
main() {
    cin>>n;
    c=vector<vector<int>>(n);
    gr=vector<vector<int>>(n);
    REP(i,n-1) {
        cin>>a>>b;
        a--,b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    mg(0,-1);
    ms(0);
    h(0);
    //REP(i,n) cout<<sz[i]<<" ";cout<<"\n";
    //REP(i,n) cout<<dn[i]<<" ";cout<<"\n";
    //REP(i,n) cout<<f(i)<<" ";cout<<"\n";
    REP(i,n) cout<<dn[i]+f(i)<<" ";
    return 0;
}
