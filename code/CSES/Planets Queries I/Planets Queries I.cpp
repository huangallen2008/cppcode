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
int n,q;
int x,k;
int f[maxn][31];
main() {
    IOS();
    cin>>n>>q;
    REP1(i,n) cin>>f[i][0];
    REP1(i,30)
        REP1(j,n)
            f[j][i]=f[f[j][i-1]][i-1];
    while(q--) {
        cin>>x>>k;
        REP(i,31)
            if(k&(1<<i))
                x=f[x][i];
        cout<<x<<"\n";
    }
    return 0;
}
