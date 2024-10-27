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
void solve() {
    int n;
    cin>>n;
    Vi a(n),x0(n+1);
    REP(i,n) cin>>a[i],x0[a[i]]=i;
    int an=inf;
    int n2=n>>1;
    {
        Vi t=a,x=x0;
        int cnt=0;
        if(t[0]!=n2) {
            int xx=x[n2];
            swap(x[t[0]],x[n2]);
            swap(t[0],t[xx]);
            cnt++;
        }
        if(t.back()!=n2+1) {
            int xx=x[n2+1];
            swap(x[t.back()],x[n2+1]);
            swap(t.back(),t[xx]);
            cnt++;
        }
        REP(i,n) cnt+=(i&1)&&t[i]<=n2;
        chmin(an,cnt);
    }
    {
        Vi t=a,x=x0;
        int cnt=0;
        if(t[0]!=n2+1) {
            int xx=x[n2+1];
            swap(x[t[0]],x[n2+1]);
            swap(t[0],t[xx]);
            cnt++;
        }
        if(t.back()!=n2) {
            int xx=x[n2];
            swap(x[t.back()],x[n2]);
            swap(t.back(),t[xx]);
            cnt++;
        }
        REP(i,n) cnt+=(i&1)&&t[i]>n2;
        chmin(an,cnt);
    }
    cout<<an<<'\n';
}  
signed main() {
    IOS(); 
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}