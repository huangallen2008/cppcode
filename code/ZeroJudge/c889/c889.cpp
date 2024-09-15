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
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
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
};
ll inv(ll x,ll m=mod) {
    return pw(x,m-2,m);
}
int n,m,x,y;
int an=0;
vector<vector<int>> v(maxn);
int h[maxn]={};
int c[maxn]={};
int f(int u) {
    queue<pii> q;
    c[u]=1;
    int a=0,b=0;
    q.push({u,0});
    while(q.size()) {
        int t=q.front().f,tc=q.front().s;
        q.pop();
        if(h[t]&&c[t]!=(tc%2)+1) return 0;
        if(h[t]) continue;
        c[t]=(tc%2)+1;
        REP(i,SZ(v[t])) q.push({v[t][i],(tc%2)+1});
        if(tc%2==0) a++;
        else b++;
        h[t]=1;
    }
    return min(a,b);
}
signed main()
{
    IOS();
    cin>>n>>m;
    REP(i,m) {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    REP1(i,n) {
        if(h[i]==0) {
            int t=f(i);
            if(t==0) {
                an=0;
                break;
            }
            an+=t;
        }
    }
    cout<<an<<"\n";
    return 0;
}
