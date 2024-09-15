#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
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
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
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
const int maxn=2e5+5;
const int maxv=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n<<1),nxt(n<<1|1);
    REP(i,n) cin>>a[i];
    REP(i,n) a[i+n]=a[i];
    int r=-1,now=0;
    REP(i,n<<1) {
        while(r<(n<<1)&&now<=k) now+=a[++r];
        nxt[i]=r;
        now-=a[i];
    }
    nxt[n<<1]=n<<1;
    vector<vector<int>> st(20,vector<int>(n<<1|1));
    REP(i,n<<1|1) st[0][i]=nxt[i];\
    REP1(i,19) {
        REP(j,n<<1|1) {
            st[i][j]=st[i-1][st[i-1][j]];
        }
    }

    int an=inf;
    REP(i,n) {
        int r=0;
        int now=i;
        RREP(j,20) {
            if(st[j][now]<n+i) {
                now=st[j][now],r|=1<<j;
            }
        }
        an=min(an,r+1);
    }
    cout<<an<<'\n';
    return 0;
}