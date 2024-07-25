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
int x,y;
int f[maxn][31];
int h[maxn]={0};
int tag[maxn]={};
int an[maxn]={};
vector<vector<int>> v(maxn),g(maxn),p(maxn);
void mm(int u,int l) {
    REP(i,SZ(v[u])) {
        if(v[u][i]==l) continue;
        f[v[u][i]][0]=u;
        p[u].pb(v[u][i]);
        g[u].pb(v[u][i]);
        mm(v[u][i],u);
    }
}
void mh(int u) {
    REP(i,SZ(p[u])) {
        if(h[p[u][i]]) continue;
        h[p[u][i]]=h[u]+1;
        mh(p[u][i]);
    }
}
int co(int u) {
    int r=0;
    REP(i,SZ(g[u])) {
        r+=co(g[u][i]);
    }
    return an[u]=r+tag[u];
}
main() {
    IOS();
    cin>>n>>q;
    REP(i,n-1) {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    f[1][0]=0;
    mm(1,0);
    REP1(i,30)
        REP1(j,n)
            f[j][i]=f[f[j][i-1]][i-1];
    mh(1);
    //REP1(i,n) cout<<i<<" ";cout<<"\n\n";
    /*REP1(i,n) {
        cout<<i<<":";
        REP(j,SZ(g[i])) cout<<g[i][j]<<" ";cout<<"\n";
    }cout<<"\n";*/
    //REP1(i,n) cout<<h[i]<<" ";cout<<"\n";
    while(q--) {
        cin>>x>>y;
        if(h[x]>h[y]) swap(x,y);
        int x0=x,y0=y;
        int t=h[y]-h[x];
        REP(i,19)
            if(t&(1<<i))
                y=f[y][i];
                //cout<<x<<" "<<y<<"  ";
        if(x==y) {
            tag[f[x][0]]--;
            tag[y0]++;
            //cout<<f[x][0]<<"-1 ";
            //cout<<y0<<"+1\n";
        }
        else {
            RREP(i,19) {
                if(f[x][i]!=f[y][i]) {
                    x=f[x][i];
                    y=f[y][i];
                }
            }
            tag[f[y][0]]--;
            tag[f[x][1]]--;
            tag[x0]++;
            tag[y0]++;
            //cout<<f[y][0]<<"-1 ";
            //cout<<f[x][1]<<"-1 ";
            //cout<<x0<<"+1 ";
            //cout<<y0<<"+1\n";
        }
    }
    co(1);
    //REP1(i,n) cout<<tag[i]<<" ";cout<<"\n";
    REP1(i,n) cout<<an[i]<<" ";
    return 0;
}
