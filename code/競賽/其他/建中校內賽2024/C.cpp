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
const int maxn=505;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG { //淦我寫這個衝啥小
    struct Seg {
        int sum,mp,ms,mc;
    }zr={0,0,0,0};
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.sum=b.sum+c.sum;
        a.mp=max(b.mp,b.sum+c.mp);
        a.ms=max(c.ms,c.sum+b.ms);
        a.mc=max({b.mc,c.mc,b.ms+c.mp});
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    int n;
    vector<Seg >s;
    void build(int w,int l,int r,vector<int>&a) {
        if(l==r) {
            s[w]={a[l],a[l],a[l],a[l]};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,vector<int> &a) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,a);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return zr;
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    } 
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r).mc;
    }
}seg;
int dp[maxn][maxn],ou[maxn][maxn],in[maxn][maxn];
int ndp[maxn][maxn],nou[maxn][maxn],nin[maxn][maxn];
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<Vi> a(n+1,Vi(m+1)),p(n+1,Vi(m+1));
    REP1(i,n) REP1(j,m) cin>>a[i][j];
    REP1(i,n) REP1(j,m) p[i][j]=p[i][j-1]+a[i][j];
    REP1(i,n) {
        // memset();////////////////
        REP(i,n+2) REP(j,m+2) nin[i][j]=nou[i][j]=-inf;
        for(int l=1;l<=m;l++) {
            for(int r=l;r<=m;r++) ndp[l][r]=p[i][r]-p[i][l-1]+max(in[l][r],ou[l][r]);
        }
        // for(auto x:Vi{0,n+1}) {
        //     for(auto y:Vi{0,m+1}) {
        //         nin[x][y]=nou[x][y]=-inf;
        //     }
        // }
        for(int r=1;r<=m;r++) {
            for(int l=r;l>0;l--) {
                if(l==r) nin[l][r]=ndp[l][r];
                else {
                    nin[l][r]=max({nin[l][r-1],nin[l+1][r],ndp[l][r]});
                    // for(int k=l;k<r;k++) chmax(in[i][l][r],dp[i][k][r]);
                }
            }
        }
        for(int l=1;l<=m;l++) {
            for(int r=m;r>=l;r--) {
                // if(r==m) {
                //     if(l==1) {
                //         ou[i][l][r]=dp[i][l][r];
                //         continue;
                //     }
                //     ou[i][l][r]=max(ou[i][l-1][r],ou[i][l][r+1],dp[i][l][r]);
                // }
                // else {
                    nou[l][r]=max({nou[l][r+1],nou[l-1][r],ndp[l][r]});
                // }
            }
        }
        swap(dp,ndp);
        swap(in,nin);
        swap(ou,nou);
        // REP1(l,m) {
        //     REP1(r,m) cout<<dp[i][l][r]<<' ';entr
        // }entr
        // REP1(l,m) {
        //     REP1(r,m) cout<<in[i][l][r]<<' ';entr
        // }entr
        // REP1(l,m) {
        //     REP1(r,m) cout<<ou[i][l][r]<<' ';entr
        // }entr entr entr
    }
    int mx=-inf;
    REP1(i,m) for(int j=i;j<=m;j++) chmax(mx,dp[i][j]);
    cout<<mx<<'\n';
    return 0;
}