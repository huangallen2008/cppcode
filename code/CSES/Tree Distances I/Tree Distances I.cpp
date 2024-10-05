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
int p[maxn]={};
int mc[maxn]={};
int ttt;
int fh[maxn]={};
vector<vector<int>> c,gr;
vector<pii> fs(maxn,{0,0});
int h(int u) {
    int r=0;
    REP(i,SZ(c[u])) r=max(r,h(c[u][i])+1);
    return dn[u]=r;
}
void mfs(int u) {
    int r=0;
    int mx=-2,mx2=-2,mxc=-1;
    REP(i,SZ(c[u])) {
        int t=dn[c[u][i]];
        if(mx==-2) { mx=t; mxc=c[u][i]; }
        else if(t>mx) { mx2=mx; mx=t; mxc=c[u][i]; }
        else if(mx2==-2) mx2=t;
        else if(t>mx2) mx2=t;
    }
    mc[u]=mxc;
    fs[u]={mx,mx2};
}
int f(int u) {
    if(u==0) return 0;
    if(fh[u]) return fh[u];
    int r=f(p[u])+1;
    if(u==mc[p[u]]) r=max(r,fs[p[u]].s+2);
    else r=max(r,fs[p[u]].f+2);
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
    memset(mc,-1,sizeof(mc));
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
    ttt=h(0);
    REP(i,n) mfs(i);
    /*
    q.push(0);
    while(q.size()) {
        int t=q.front();
        q.pop();
        REP(i,SZ(v[t])) {
            if(dn[v[t][i]]) continue;
            q.push(v[t][i]);
            dn[v[t][i]]=dn[t]+1;
        }
    }
    cout<<" p:";
    REP(i,n) cout<<p[i]<<" ";cout<<"\ndn:";
    REP(i,n) cout<<dn[i]<<" ";cout<<"\nmc:";
    REP(i,n) cout<<mc[i]<<" ";cout<<"\nmx:";
    REP(i,n) cout<<fs[i].f<<" ";cout<<"\nm2:";
    REP(i,n) cout<<fs[i].s<<" ";cout<<"\n";
    */
    cout<<dn[0]<<" ";
    REP1(i,n-1) {
        cout<<max(dn[i],f(i))<<" ";
    }
    //cout<<"\nfh:";
    //REP(i,n) cout<<fh[i]<<" ";cout<<"\n";
    return 0;
}
