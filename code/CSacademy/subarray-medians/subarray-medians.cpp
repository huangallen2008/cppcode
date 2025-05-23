#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
#define ll long long
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
const int maxn=1e5+1;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define Vl vector<ll>
struct median_linklist {
    Vi nxt,pre;
    Vl a;
    int n,mi,mid;
    void init(int _n) {
        n=_n;
        mi=n+1>>1;
        mid=n+1>>1;
        // sort(ALL(a));
        // a.insert(a.begin(),0);
        nxt=pre=Vi(n+2);
        REP(i,n+1) nxt[i]=i+1;
        REP1(i,n+1) pre[i]=i-1;
        pre[0]=0,nxt[n+1]=n+1;
    }
    void del(ll u) {
        n--;
        if(u==mid) {
            mid=nxt[mid];
        }
        else if(u<mid) {
            mi--;
        }
        nxt[pre[u]]=nxt[u];
        pre[nxt[u]]=pre[u];
        while(mi>(n+1>>1)) {
            mi--;
            mid=pre[mid];
        }
        while(mi<(n+1>>1)) {
            mi++;
            mid=nxt[mid];
        }
    }
    ll get_m() { return mid; }
}mll;
signed main() {
    IOS(); 
    int n;
    cin>>n;
    Vl a(n);
    REP(i,n) cin>>a[i];
    Vl t=a;
    sort(ALL(t));
    t.insert(t.begin(),0);
    // mll.init(n,a);
    ll an=0;
    REP(i,n) {
        int R=n-1-(n-1-i&1);
        mll.init(n);
        REP(j,i) mll.del(a[j]);
        if(n-1>R) mll.del(a[n-1]);
        an+=(i+1)*(ll)(R+1)*mll.get_m();
        for(int j=R-2;j>=i;j-=2) {
            mll.del(a[j+1]);
            mll.del(a[j+2]);
            an+=(i+1)*(ll)(j+1)*mll.get_m();
        }
    }
    cout<<an<<'\n';
    return 0;
}