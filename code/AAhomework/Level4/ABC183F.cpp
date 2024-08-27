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
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxv=(1ll<<30);
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
vector<int> c;
struct DSU {
    vector<int> p,sz;
    vector<map<int,int>> cnt;
    int n;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
        cnt=vector<map<int,int>>(n);
        REP(i,n) cnt[i][c[i]]++;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        for(auto [u,v]:cnt[x]) cnt[y][u]+=v;
    }
    int qu(int x,int y) {
        int a=find(x);
        if(cnt[a].count(y)==0) return 0;
        return cnt[a][y];
    }
} dsu;
signed main()
{
    IOS();
    //input
    int n,q;
    cin>>n>>q;
    c=vector<int>(n);
    REP(i,n) cin>>c[i];
    //init
    dsu.init(n);

    REP(i,q) {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1) {
            x--,y--;
            dsu.merge(x,y);
        }
        else {
            x--;
            int an=dsu.qu(x,y);
            cout<<an<<'\n';
        }
    }
    return 0;
}
