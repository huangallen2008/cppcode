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
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}

struct median_linklist {
    Vi nxt,pre,a;
    unordered_map<int,int> id;
    int n,mi,mid;
    void init(int _n,Vi _a) {
        n=_n;
        mi=n+1>>1;
        mid=n+1>>1;
        a=_a;
        sort(ALL(a));
        a.insert(a.begin(),0);
        REP1(i,n) id[a[i]]=i;
        nxt=pre=Vi(n+2);
        REP(i,n+1) nxt[i]=i+1;
        REP1(i,n+1) pre[i]=i-1;
        pre[0]=0,nxt[n+1]=n+1;
    }
    void del(int x) {
        n--;
        int u=id[x];
        if(u==mid) {
            mid=nxt[mid];
        }
        else if(u<mid) {
            mi--;
        }
        nxt[pre[u]]=nxt[u];
        pre[nxt[u]]=pre[u];
        if(mi>(n+1>>1)) {
            mi--;
            mid=pre[mid];
        }
    }
}