#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=100+5;
const int N=(int)1e18;
const int mod=1e9+7;
struct DSU {
    vector<int> p,sz,w;
    int n;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        w=vector<int>(n);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        w[x]-=w[y];
        sz[y]+=sz[x];
    }
    void add(int u,int v) {
        int a=find(u);
        w[a]+=v;
    }
    int get(int u) {
        int r=w[u];
        while(p[u]!=u) {
            u=p[u];
            r+=w[u];
        }
        return r;
    }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    DSU dsu;
    dsu.init(n);
    REP(i,m) {
        string opt;
        cin>>opt;
        if(opt[0]=='j') {
            int x,y;
            cin>>x>>y;
            x--,y--;
            dsu.merge(x,y);
        }
        else if(opt[0]=='a') {
            int x,v;
            cin>>x>>v;
            x--;
            dsu.add(x,v);
        }
        else {
            int x;
            cin>>x;
            x--;
            int an=dsu.get(x);
            cout<<an<<'\n';
        }
    }
    return 0;
}
