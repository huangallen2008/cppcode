#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=3e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n;
    cin>>n;
    Vi b(n+1),d(n+1),p(n+1),x(n+1),pd(n+1);
    REP1(i,n) cin>>b[i];
    REP1(i,n-1) cin>>d[i],pd[i]=pd[i-1]+d[i];
    REP1(i,n) cin>>p[i];
    REP1(i,n) cin>>x[i];
    int vt=inf;
    REP1(i,n) {
        chmin(b[i],vt);
        chmin(vt,b[i]);
        vt+=d[i];
    }
    vt=inf;
    RREP1(i,n) {
        chmin(b[i],vt);
        chmin(vt,b[i]);
        vt+=d[i-1];
    }
    map<int,int> mp;
    mp[-inf]=0,mp[inf]=0;
    REP1(i,n) {
        int id=p[i];
        auto [x1,y1]=*mp.lower_bound(id);//y1-
        auto [x2,y2]=*prev(mp.lower_bound(id));
        int dif1=pd[x1-1]-pd[id-1],dif2=pd[id-1]-pd[x2-1];
        int l1=y1-dif1,r1=y1+dif1,l2=y2-dif2,r2=y2+dif2;
        int l=1,r=b[id];
        chmax(l,max(l1,l2));
        chmin(r,min(r1,r2));
        if(x[i]==1) mp[id]=l;
        else mp[id]=r;
    }
    REP1(i,n) cout<<mp[i]<<' ';
    cout<<'\n';
    return 0;
}