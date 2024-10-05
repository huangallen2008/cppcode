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
const int maxn=2e3+5e2+5;
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
struct eg {
    int u,v,x;
};
int n,m,x,y,z;
int a[maxn]={};
vector<eg> e,no;
vector<int> an,p;
main() {
    IOS();
    cin>>n>>m;
    REP1(i,n) a[i]=inf;
    p=vector<int>(n+1);
    a[0]=0;
    REP(i,m) {
        cin>>x>>y>>z;
        e.pb({x,y,z});
    }
    REP1(i,n) e.pb({0,i,0});
    REP(rd,n+1) {
        x=0;
        for(auto d:e) {
            if(a[d.u]==inf) continue;
            if(a[d.v]>a[d.u]+d.x) {
                a[d.v]=a[d.u]+d.x;
                p[d.v]=d.u;
                x=d.v;
            }
        }
    }
    if(x) {
        cout<<"YES\n";
        REP(i,n) x=p[x];
        for(int cr=x;;cr=p[cr]) {
            an.pb(cr);
            if(cr==x && an.size()>1) break;
        }
        RREP(i,SZ(an)) cout<<an[i]<<" ";
        cout<<"\n";
    }
    else cout<<"NO"<<"\n";
    return 0;
}
