#include<bits/stdc++.h>
using namespace std;
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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
struct DSU {
    vector<int> p;
    void init(int n) {
        p=vector<int>(n);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    bool merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return 0;
        p[x]=y;
        return 1;
    }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<pipii> edge;
    REP(i,m) {
        int u,v,c;
        cin>>u>>v>>c;
        u--,v--;
        edge.pb({c,{u,v}});
    }
    sort(ALL(edge));
    int p=0,an=0;
    DSU dsu;
    dsu.init(n);
    REP(i,m) {
        if(dsu.merge(edge[i].s.f,edge[i].s.s)) {
            p++;
            an+=edge[i].f;
        }
        if(p>=n-1) break;
    }
    if(p<n-1) cout<<"IMPOSSIBLE\n";
    else cout<<an<<"\n";
    return 0;
}
