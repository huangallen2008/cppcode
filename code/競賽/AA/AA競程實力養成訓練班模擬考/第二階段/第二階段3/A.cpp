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
const int mod=998244353;
const int maxn=1e6+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
Vi lpf(maxn),pm;
void exgcd(int a,int b,int &x,int &y) {
    if(b==0) {
        x=1,y=0;
        return;
    }
    int x1,y1;
    exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
}
void solve() {
    int n,x;
    cin>>n>>x;
    ///////x=1
    Vi f;
    for(int p:pm) {
        if(x%p==0) {
            int r=1;
            while(x%p==0) {
                x/=p;
                r*=p;
            }
            if(p==2) r*=2;
            f.pb(r);
        }
    }
    if(x>1) f.pb(x);
    int k=f.size();
    int an=0;
    REP(i,1<<k) {
        int f1=1,f2=1;
        REP(j,k) {
            if((i>>j)&1) f1*=f[j];
            else f2*=f[j];
        }
        int x,y;
        exgcd(f1,f2,x,y);
        // op(f1)op(f2)op(x)ope(y)
        if(x<=0) {
            int tt=(-x+f2)/f2;
            x+=tt*f2,y-=tt*f1;
        }
        y=-y;
        if(x==0||y==0) x+=f2,y+=f1;
        // op(f1)op(f2)op(x)ope(y)
        // int r1=(n-x*f1)/f2+1,r2=(n+1-y*f2)/f1+1,rr=min(r1,r2);
        // if(x*f1>n||y*f2>n+1) rr=0;
        int r21=((n+1)/f1-x)/f2+1,r22=((n/f2)-y)/f1+1,rr2=min(r21,r22);
        if(x*f1>n+1||y*f2>n) rr2=0;
        an+=rr2;
        // ope(rr2)
    }
    cout<<an<<'\n';
    // entr
}
void init() {
    lpf[0]=lpf[1]=1;
    for(int i=2;i<maxn;i++) {
        if(lpf[i]==0) {
            pm.pb(i);
            for(int j=i;j<maxn;j+=i) if(lpf[j]==0) lpf[j]=i;
        }
    }
}
signed main() {
    IOS(); 
    init();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
5
1 1
1000000000000000000 1
1 1000000000000
1000000000000000000 1000000000000
1000000000000000000 100

*/