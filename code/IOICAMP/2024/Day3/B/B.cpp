#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
const int inf=(1ll<<62);
Graph g;
vector<int> in,out,dep;
int cnt=1;
void dfs(int u) {
    in[u]=cnt++;
    for(int v:g[u]) {
        dep[v]=dep[u]+1;
        dfs(v);
    }
    out[u]=cnt++;
}
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u,int v) {
        for(;u<=n;u+=u&-u) b[u]+=v;
    }
    int qu(int u) {
        int r=0;
        for(;u>0;u-=u&-u) r+=b[u];
        return r;
    }
};
vector<vector<int>> f;
int go(int x,int p) {
    REP(i,18)
        if((p>>i)&1)
            x=f[x][i];
    return x;
}
int find_lca(int a,int b) {
    if(dep[a]>dep[b]) swap(a,b);
    b=go(b,dep[b]-dep[a]);
    if(a==b) return a;
    RREP(i,18) {
        int x=f[a][i],y=f[b][i];
        if(x!=y) {
            a=x;
            b=y;
        }
    }
    return f[a][0];
}
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    in=vector<int>(n);
    out=vector<int>(n);
    dep=vector<int>(n);
    f=vector<vector<int>>(n,vector<int>(18));
    g=Graph(n);
    REP1(i,n-1) {
        int x;
        cin>>x;
        x--;
        f[i][0]=x;
        g[x].pb(i);
    }
    REP1(i,17) {
        REP(j,n) f[j][i]=f[f[j][i-1]][i-1];
    }
    dfs(0);
//    oparr(in) oparr(out)
    vector<int> va(n);
    BIT bit,bit2;
    bit.init(n*2);
    bit2.init(n*2);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int u,c;
            cin>>u>>c;
            u--;
            va[u]+=c;
            bit.ud(in[u],c);
            bit.ud(out[u],-c);
            bit2.ud(out[u],c);
        }
        else if(opt==2) {
            int u,v;
            cin>>u>>v;
            u--,v--;
            int x=bit.qu(in[v]);
            int y=bit.qu(in[u]);
            int lca=find_lca(u,v);
            int z=bit.qu(in[lca]);
            int an=x+y-z*2+va[lca];
//            op(x)op(y)ope(z)
            cout<<an<<'\n';
        }
        else if(opt==3) {
            int u;
            cin>>u;
            u--;
            int an=bit2.qu(out[u])-bit2.qu(in[u]);
            cout<<an<<'\n';
        }
    }
    return 0;
}
