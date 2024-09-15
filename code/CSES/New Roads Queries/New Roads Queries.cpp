#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
//#define int long long
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
const int maxn=2e5+5;
const int inf=(1ll<<62);
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//int rd(int l,int r) {
//    return uniform_int_distribution<int>(l,r)(rng);
//}
//shuffle(a,a+n,rng)
int p[maxn],sz[maxn],mx[maxn];
int find(int u) {
    if(p[u]==u) return u;
    return find(p[u]);
}
signed main() {
    IOS();
    int n,m,q;
    cin>>n>>m>>q;
    auto it=sz;
    int cnt=n;
    while(cnt--) {*it=1;it++;}
    REP(i,n) p[i]=i;
    REP1(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        int x=find(u),y=find(v);
        if(x==y) continue;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        mx[x]=i;
    }
    while(q--) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(find(a)==find(b)) {
            int an=0;
            while(a!=b) {
                if(sz[a]>sz[b]) swap(a,b);
                an=max(an,mx[a]);
                a=p[a];
            }
            cout<<an<<'\n';
        }
        else cout<<"-1\n";
    }
    return 0;
}
