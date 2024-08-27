#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3")
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
#define md(x,m) (((x)%(m)+(m))%(m))
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(idd,(x).size()) cout<<x[idd]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=100+5;
const int N=1e18;
const int mod=1e9+7;
struct DSU {
    vector<int> p,sz,dis;
    int n;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        dis=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        int np=find(p[u]);
        dis[u]+=dis[p[u]];
        return p[u]=np;
    }
    bool merge(int x,int y,int v) {
        int a=find(x),b=find(y);
        if(a==b) {
//            op(x)op(y)op(a)ope(b)
            return md(dis[x]-dis[y],3)==md(v,3);
        }
        if(sz[a]>sz[b]) {
            swap(a,b);
            swap(x,y);
            v=-v;
        }
        p[a]=b;
        dis[a]=md(v-dis[x]+dis[y],3);
        sz[b]+=sz[a];
        return 1;
    }
};
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    DSU dsu;
    dsu.init(n);
    int an=0;
    REP(i,k) {
//        ope(an)
        int opt,x,y;
        cin>>opt>>x>>y;
        if(x>n||y>n) {
            an++;
            continue;
        }
        x--,y--;
        if(opt==1) {
            if(!dsu.merge(x,y,0)) an++;
        }
        else {
            if(x==y) {
                an++;
                continue;
            }
            if(!dsu.merge(x,y,1)) an++;
        }
    }
    cout<<an<<'\n';
    return 0;
}
