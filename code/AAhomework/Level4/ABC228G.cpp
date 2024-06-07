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
    vector<int> p;
    int n;
    void init(int _n) {
        n=_n+1;
        p=vector<int>(n);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        p[x]=y;
    }
    void del(int x) {
        merge(x,x+1);
    }
};
signed main() {
    IOS();
    int q;
    cin>>q;
    int n=(1ll<<20);
    DSU dsu;
    dsu.init(n);
    dsu.merge(n,0);
    vector<int> a(n,-1);
    REP(i,q) {
        int opt,x;
        cin>>opt>>x;
        int id=(x-1)%n;
        if(opt==1) {
            int t=dsu.find(id);
            a[t]=x;
            dsu.del(t);
        }
        else {
            cout<<a[id]<<'\n';
        }
    }
    return 0;
}
