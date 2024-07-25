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
struct edge {
    int u,v,d;
    edge(int u,int v,int d):u(u),v(v),d(d) {}
};
bool st(edge a,edge b) {
    return a.d<b.d;
}
int an=0;
vector<int> p;
vector<bool> ir;
int find(int u) {
    if(p[u]==u) return u;
    return p[u]=find(p[u]);
}
void merge(edge e) {
    int a=e.u,b=e.v;
    int x=find(a),y=find(b);
    if(x==y||(ir[x]&&ir[y])) return;
    if(ir[x]) p[y]=x;
    else p[x]=y;
    an+=e.d;
}
signed main()
{
    IOS();
    int n,m,k,x;
    cin>>n>>m>>k;
    p=vector<int>(n);
    ir=vector<bool>(n);
    REP(i,n) p[i]=i;
    vector<edge> e;
    REP(i,k) {
        cin>>x;
        ir[x-1]=1;
    }
    REP(i,m) {
        int x,y,z;
        cin>>x>>y>>z;
        e.pb({x-1,y-1,z});
    }
    sort(ALL(e),st);
    REP(i,m) merge(e[i]);
    cout<<an<<"\n";
    return 0;
}
