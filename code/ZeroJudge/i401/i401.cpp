#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,(n))
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define MD(x,m) ((x)%(m)+(m))%(m)
#define md(x) MD(x,mod)
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll inf = 1ll<<62;
const int iinf=2147483647;
const ll mod = 1e9+9;
const ll maxn=250000;
const double PI=acos(-1);
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
}
int n;
vector<vector<pii>> ax(60001),ay(60001);
vector<vector<int>> x(60001),y(60001),cx(60001),cy(60001);
int a,b,c;
int nx=30000,ny=30000,d=3;//0:u 1:d 2:l 3:r
int an=1;
int id(int x) { return x+30000; }
signed main() {
    IOS();
    cin>>n;
    REP(i,n) {
        cin>>a>>b>>c;
        ax[id(a)].pb({id(b),c});
        ay[id(b)].pb({id(a),c});
    }
    REP(i,60001) {
        sort(ALL(ax[i]));
        for(auto [p,q]:ax[i]) {
            x[i].pb(p);
            cx[i].pb(q);
        }
        sort(ALL(ay[i]));
        for(auto [p,q]:ay[i]) {
            y[i].pb(p);
            cy[i].pb(q);
        }
    }
    int tt=lower_bound(ALL(y[ny]),nx)-y[ny].begin();
    if(tt>=SZ(y[ny])) an=0;
    else {
        nx=y[ny][tt];
        if(cy[ny][tt]==0) d=0;
        else d=1;
    }
    while(true) {
        if(an==0) break;
        if(d<=1) {//x
            int in=lower_bound(ALL(x[nx]),ny)-x[nx].begin();
            if(d==0) {
                if(in>=SZ(x[nx])-1) break;
                ny=x[nx][in+1];
                if(cx[nx][in+1]==0) d=3;
                else d=2;
            }
            else {
                if(in==0) break;
                ny=x[nx][in-1];
                if(cx[nx][in-1]==0) d=2;
                else d=3;
            }
        }
        else {//y
            int in=lower_bound(ALL(y[ny]),nx)-y[ny].begin();
            if(d==3) {
                if(in>=SZ(y[ny])-1) break;
                nx=y[ny][in+1];
                if(cy[ny][in+1]==0) d=0;
                else d=1;
            }
            else {
                if(in==0) break;
                nx=y[ny][in-1];
                if(cy[ny][in-1]==0) d=1;
                else d=0;
            }
        }
        //cout<<nx-30000<<" "<<ny-30000<<" "<<d<<"\n";
        an++;
    }
    cout<<an<<"\n";
    return 0;
}
