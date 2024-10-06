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
const int maxn=1.5e7+1;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void exgcd(int a,int b,int &x,int &y) {
    if(b==0) {
        x=1;
        y=0;
        return;
    }
    int x1,y1;
    exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
}
Vi lpf(maxn);
void solve() {
    int a,b;
    cin>>a>>b;
    int A=a,B=b;
    int g=__gcd(a,b);
    if(g!=1) {
        a/=g,b/=g;
        cout<<a+b<<' '<<b<<' '<<1<<' '<<1<<'\n';
        return;
    }
    if(b==1) {
        cout<<"-1 -1 -1 -1\n";
        return;
    }
    int lf=lpf[b],f1=1;
    while(b%lf==0) {
        b/=lf;
        f1*=lf;
    }
    if(b==1) {
        cout<<"-1 -1 -1 -1\n";
        return;
    }
    if(f1>b) swap(f1,b);
    op(b)ope(f1)
    int x,y;
    exgcd(b,f1,x,y);
    op(b)op(f1)op(x)ope(y)
    y=-y*a;x=x*a;
    cout<<x<<' '<<f1<<' '<<y<<' '<<b<<'\n';
    if(-y*f1*B+x*b*B!=A*f1*b) {
        op("!!!")cout<<A<<' '<<B<<'\n';;
    }
}
signed main() {
    IOS();
    // freopen("out.txt","w",stdout);
    // cout<<"100\n";
    // REP1(i,10) REP1(j,10) cout<<i<<' '<<j<<'\n';
    #ifdef LOCAL 
        // freopen("out.txt","r",stdin);
    #endif
    for(int i=2;i<maxn;i++) {
        if(!lpf[i]) {
            for(int j=i;j<maxn;j+=i) lpf[j]=i;
        }
    }
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}