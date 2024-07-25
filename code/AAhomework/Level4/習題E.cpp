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
const int mod=1e9+7;
struct DSU {
    vector<int> p,dis,val,sz;
    int n;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        dis=vector<int>(n);
        sz=vector<int>(n,1);
        val=vector<int>(n,inf);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        int np=find(p[u]);
        dis[u]+=dis[p[u]];
        if(val[np]!=inf) val[u]=val[np]-dis[u];
        p[u]=np;
        return np;
    }
    int merge(int a,int b,int d) {
        int x=find(a),y=find(b);
        int va,vb;
        if(x!=y&&(val[a]==inf||val[b]==inf)) {
            int ds=d-dis[a]+dis[b];
            if(sz[x]>sz[y]) {
                swap(x,y);
                ds=-ds;
            }
            p[x]=y;
            dis[x]=ds;
            sz[y]+=sz[x];
            if(val[x]!=inf) val[y]=val[x]+ds;
            return d;
        }
        if(val[a]==inf) return dis[a]-dis[b];
        return val[b]-val[a];
    }
    int setv(int a,int v) {
        int x=find(a);
        if(val[x]==inf) {
            val[x]=v+dis[a];
            return v;
        }
        else return val[a];
    }
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    DSU dsu;
    dsu.init(n);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int a,b,d;
            cin>>a>>b>>d;
            a--,b--;
            cout<<dsu.merge(b,a,d)<<'\n';
        }
        else {
            int a,v;
            cin>>a>>v;
            a--;
            cout<<dsu.setv(a,v)<<'\n';
        }
    }
    return 0;
}
