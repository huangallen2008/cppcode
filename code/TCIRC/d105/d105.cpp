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
};
struct e {
    int s=0;
    int l=0,r=0;
};
int n,m,x,y,z;
int an=0;
int th[maxn]={};
vector<e> v(maxn);
void st(int u) {
    if(u>=n) return;
    st(v[u].l); st(v[u].r);
    v[u].s=v[v[u].l].s+v[v[u].r].s;
}
void p(int u,int w) {
    if(u>=n) {
        v[u].s+=w;
        an=u;
        return;
    }
    if(v[v[u].l].s<=v[v[u].r].s) p(v[u].l,w);
    else p(v[u].r,w);
    v[u].s=v[v[u].l].s+v[v[u].r].s;
}
main() {
	cin>>n>>m;
	REP(i,n) cin>>v[n+i].s;
	REP(i,m) cin>>th[i];
	REP(i,n-1) {
	    cin>>x>>y>>z;
	    v[x].l=y; v[x].r=z;
	}
	st(1);
	REP(i,m) {
	    p(1,th[i]);
	    cout<<an<<" ";
	}
	return 0;
}
