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
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define MD(x,m) (x%m+m)%m
#define md(x) MD(x,mod)
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
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
ll inv(ll x,ll m=mod) {
    return pw(x,m-2,m);
}
int n,m,k;
int xi,yi,vi;
struct Ts {
    int x,y,v;
    Ts(int _x,int _y,int _v) {
        x=_x; y=_y; v=_v;
    }
};
vector<Ts> g,s;//gold,silver
vector<int> x,y;
int an=0;
unordered_map<int,int> vx,vy,hx,hy;//v:no重複,h:對應排名
vector<vector<int>> v(5001,vector<int>(5001));//v:value
vector<vector<int>> gd(5001,vector<int>(5001));//gd:gold
signed main()
{
    IOS();
    cin>>n>>m>>k;
    REP(i,n) {
        cin>>xi>>yi>>vi;
        g.pb(Ts(xi,yi,vi));
        if(vx[xi]==0) x.pb(xi);
        vx[xi]=1;
        if(vy[yi]==0) y.pb(yi);
        vy[yi]=1;
    }
    REP(i,m) {
        cin>>xi>>yi>>vi;
        s.pb(Ts(xi,yi,vi));
    }
    sort(ALL(x));
    sort(ALL(y));
    REP(i,SZ(x)) hx[x[i]]=i+1;
    REP(i,SZ(y)) hy[y[i]]=i+1;
    REP(i,n) {
        v[hx[g[i].x]][hy[g[i].y]]=g[i].v;
        gd[hx[g[i].x]][hy[g[i].y]]=1;
    }
    REP(i,m) {
        int idx=lower_bound(ALL(x),s[i].x)-x.begin()+1;
        int idy=lower_bound(ALL(y),s[i].y)-y.begin()+1;
        v[idx][idy]+=s[i].v;
    }
    REP1(i,SZ(x)) {
        REP1(j,SZ(y)) {
            v[i][j]+=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
            gd[i][j]+=gd[i-1][j]+gd[i][j-1]-gd[i-1][j-1];
            REP(a,i) {
                REP(b,j) {
                    if(gd[i][j]-gd[a][j]-gd[i][b]+gd[a][b]>k) continue;
                    an=max(an,v[i][j]-v[a][j]-v[i][b]+v[a][b]);
                }
            }
        }
    }
    cout<<an<<"\n";
    return 0;
}
