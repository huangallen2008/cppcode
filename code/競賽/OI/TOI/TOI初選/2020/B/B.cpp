#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
vector<vector<pii>> g;
pii p1={-inf,-1},p2={-inf,-1};
void dfs(int u,int d,int l) {
    if(d>p1.f) {
        p2=p1;
        p1={d,u};
    }
    else if(d>p2.f&&d<p1.f) {
        p2={d,u};
    }
    if(SZ(g[u])==1&&l!=-1) return;
    for(auto [v,w]:g[u]) {
        if(v==l) continue;
        dfs(v,d+w,u);
    }
}
void dfs1(int u,int d,int l) {
    p1={-inf,-1},p2={-inf,-1};
    dfs(u,d,l);
}
signed main()
{
    IOS();
    int n,x,y,z;
    cin>>n;
    g=vector<vector<pii>>(n);
    REP(i,n-1) {
        cin>>x>>y>>z;
        g[x].pb({y,z});
        g[y].pb({x,z});
    }
    dfs1(0,0,-1);
//    cout<<p1.f<<" "<<p1.s<<"\n"<<p2.f<<" "<<p2.s<<"\n\n";
    pii a=p1,b=p2;
    dfs1(a.s,0,-1);
    int an1=p2.f;
//    cout<<p1.f<<" "<<p1.s<<"\n"<<p2.f<<" "<<p2.s<<"\n\n";
    dfs1(b.s,0,-1);
//    cout<<p1.f<<" "<<p1.s<<"\n"<<p2.f<<" "<<p2.s<<"\n\n";
    int an2=p1.f;
    cout<<max(an1,an2)<<"\n";
    return 0;
}
