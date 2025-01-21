#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=1e6+5;
struct DSU {
    vector<int> p,sz;
    int n;
    int cnt=0;
    void init(int _n) {
        n=_n;
        cnt=n;
        p=vector<int>(n);
        REP(i,n) p[i]=i;
        sz=vector<int>(n,1);
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        cnt--;
        p[x]=y;
        sz[y]+=sz[x];
    }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<pii> edge;
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        edge.pb({u,v});
    }
    int q;
    cin>>q;
    int x=0;
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        l=(l-1+x)%m+1,r=(r-1+x)%m+1;
        if(l>r) swap(l,r);
        l--,r--;
        DSU dsu;
        dsu.init(n);
        for(int i=l;i<=r;i++) dsu.merge(edge[i].f,edge[i].s);
        x=dsu.cnt;
        cout<<dsu.cnt<<'\n';
    }
    return 0;
}
