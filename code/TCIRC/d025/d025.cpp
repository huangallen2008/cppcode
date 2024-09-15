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
int n,k,x;
int rt;
bool a[maxn]={};
int h[maxn]={};
vector<vector<int>> v(maxn);
int d(int u) {
    int r=0,t=0;
    REP(i,SZ(v[u])) {
        t+=d(v[u][i]);
        r=max(r,h[v[u][i]]+1);
    }
    h[u]=r;
    return t+r;
}
main() {
    IOS();
    cin>>n;
    REP1(i,n) {
        cin>>k;
        REP(j,k) {
            cin>>x;
            v[i].pb(x);
            a[x]=1;
        }
    }
    REP1(i,n) {
        if(a[i]==0) {
            rt=i;
            break;
        }
    }
    cout<<rt<<"\n"<<d(rt)<<"\n";
    return 0;
}
