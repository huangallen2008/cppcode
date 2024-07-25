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
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int cnt=0;
struct DSU{
    vector<int> p,sz;
    int an=0;
    int cnt=0;
    void init(int n) {
        cnt=n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b,int v) {
        int x=find(a),y=find(b);
        if(x==y) return;
        an+=v;
        cnt--;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
    }
} dsu0,dsu;
struct edge {
    int u,v,w;
};
bool so(edge a,edge b) {
    return a.w>b.w;
}
bool sob(edge a,edge b) {
    return a.w<b.w;
}
signed main() {
    IOS();
    vector<edge> edges0,edges1;
    int n,m;
    cin>>n>>m;
    int N=n*m;
    dsu0.init(N),dsu.init(N);
    int cntm=0;
    vector<vector<bool>> tt(n,vector<bool>(m));
    REP(i,n-1) {
        REP(j,m) {
            char c;
            cin>>c;
            if(c=='.') {
                tt[i][j]=1;
                cntm++;
            }
        }
    }
    REP(i,n-1) {
        REP(j,m) {
            int c;
            cin>>c;
            int u=i*m+j,v=(i+1)*m+j;
            if(tt[i][j]) {
                edges1.pb({u,v,c});
                dsu0.merge(u,v,0);
            }
            else edges0.pb({u,v,c});
        }
    }
    tt=vector<vector<bool>>(n,vector<bool>(m));
    REP(i,n) {
        REP(j,m-1) {
            char c;
            cin>>c;
            if(c=='.') {
                tt[i][j]=1;
                cntm++;
            }
        }
    }
    REP(i,n) {
        REP(j,m-1) {
            int c;
            cin>>c;
            int u=i*m+j,v=i*m+j+1;
            if(tt[i][j]) {
                edges1.pb({u,v,c});
                dsu0.merge(u,v,0);
            }
            else edges0.pb({u,v,c});
        }
    }
    int sumw=0;
    sort(ALL(edges0),sob);
    sort(ALL(edges1),so);
    for(auto [u,v,w]:edges1) {
        sumw+=w;
        dsu.merge(u,v,-w);
    }
    for(auto [u,v,w]:edges0) {
        dsu.merge(u,v,w);
    }
    int an=sumw+dsu.an,an1=dsu0.cnt;
    cout<<cntm+an1-N+an1-1<<' '<<an<<'\n';
    return 0;
}
