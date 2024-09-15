#include<bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("O3,unroll-loops,fast-math")
//#pragma GCC target("avx2,popcnt")
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=255;
const int maxv=1e3+5;
const int maxs=1e6;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct DSU {
    vector<int> p,sz;
    void init(int n) {
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
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
    }
    bool same(int a,int b) {
        return find(a)==find(b);
    }
};
int dis2(pii a,pii b){
    return SQ(a.f-b.f)+SQ(a.s-b.s);
}
bool check(vector<pii> &a,int n,int m) {
    DSU dsu;
    dsu.init(n);
    REP(i,n) {
        REP(j,i) {
            if(dis2(a[i],a[j])<=m) dsu.merge(i,j);
        }
    }
    return dsu.same(0,1);
}
void solve() {
    int n;
    int cas=1;
    while(cin>>n) { if(n==0) break;
        vector<pii> a(n);
        REP(i,n) {
            cin>>a[i].f>>a[i].s;
        }
        int l=0,r=5e6,m;
        while(l<r) {
            m=(l+r)>>1;
            if(check(a,n,m)) r=m;
            else l=m+1;
        }
        long double an=sqrt(l);
        cout<<"Scenario #"<<cas<<"\nFrog Distance = "<<fixed<<setprecision(3)<<an<<"\n\n";
        cas++;
    }
}
signed main() {
    IOS();
    solve();
    return 0;
}
