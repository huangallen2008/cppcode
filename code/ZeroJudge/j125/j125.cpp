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
#define Graph vector<vector<int>>
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
int n;
Graph m;
vector<vector<pii>> g;
vector<pii> a;
vector<pii> d={{0,1},{1,0},{0,-1},{-1,0}};
vector<int> an;
int an1;
priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
bool ok(int x,int y) {
    if(x<0||y<0||x>=n||y>=n) return 0;
    return 1;
}
signed main()
{
    IOS();
    cin>>n;
    m=Graph(n,vector<int>(n));
    g=vector<vector<pii>>(n*n);
    a=vector<pii>(n*n,{inf,inf});
    an=vector<int>(n*n);
    REP(i,n) {
        REP(j,n) {
            cin>>m[i][j];
        }
    }
    REP(i,n) {
        REP(j,n) {
            if(i==n-1&&j==n-1) continue;
            REP(di,4) {
                int x=i+d[di].f,y=j+d[di].s;
                if(ok(x,y)) g[i*n+j].pb({x*n+y,abs(m[i][j]-m[x][y])});
            }
        }
    }
    pq.push({0,{0,0}});
    while(pq.size()) {
        int x=pq.top().f,y=pq.top().s.f,z=pq.top().s.s;
        pq.pop();
        if(x>a[y].f) continue;
        else if(x==a[y].f && z>=a[y].s) continue;
        else a[y]={x,z};
        for(auto [p,q]:g[y]) pq.push({max(q,x),{p,z+1}});
    }
    an1=a[SQ(n)-1].f;
    queue<int> q;
    q.push(0);
    while(q.size()) {
        int r=q.front();
        q.pop();
        for(auto [p,q1]:g[r]) {
            if(q1<=an1&&an[p]==0) {
                q.push(p);
                an[p]=an[r]+1;
            }
        }
    }
    cout<<an1<<"\n"<<an[SQ(n)-1]<<"\n";
    return 0;
}
