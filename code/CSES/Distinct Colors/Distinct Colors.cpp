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
const int maxn=2e5+5;
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
int a[maxn]={};
vector<vector<int>> gr(maxn),v(maxn);
vector<set<int>> c(maxn);
vector<int> an(maxn);
set<int> no;
void mm(int u,int l) {
    REP(i,SZ(gr[u])) {
        if(gr[u][i]==l) continue;
        v[u].pb(gr[u][i]);
        mm(gr[u][i],u);
    }
}
void d(int u) {
    if(v[u].size()==0) {
        an[u]=1;
        c[u]={a[u]};
        return;
    }
    int r=0,mxi=-1;
    REP(i,SZ(v[u])) {
        d(v[u][i]);
        if(mxi==-1 || SZ(c[v[u][i]])>SZ(c[v[u][mxi]]))
            mxi=i;
    }
    set<int> &t=c[v[u][mxi]];
    REP(i,SZ(v[u])) {
        if(i==mxi) continue;
        for(auto p:c[v[u][i]]) {
            t.insert(p);
        }
        c[v[u][i]]=no;
    }
    t.insert(a[u]);
    an[u]=SZ(t);
    swap(c[u],t);
}
main() {
    IOS();
    cin>>n;
    REP1(i,n) cin>>a[i];
    REP(i,n-1) {
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    mm(1,0);
    /*REP1(i,n) {
        cout<<i<<":";
        REP(j,SZ(v[i])) cout<<v[i][j]<<" ";cout<<"\n";
    }*/
    d(1);
    REP1(i,n) cout<<an[i]   <<" ";
    /*cout<<"\n";
    REP1(i,n) {
        cout<<i<<": ";
        for(auto p:c[i]) {
            cout<<p<<" ";
        }cout<<"\n";
    }*/
    return 0;
}
