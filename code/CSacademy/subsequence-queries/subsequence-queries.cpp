#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=3e6+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define Mat vector<Vi> 
Mat operator*(Mat a,Mat b) {
    int n=a.size(),m=b.size(),k=b[0].size();
    Mat c(n,Vi(k));
    REP(i,n) REP(j,m) REP(l,k) (c[i][l]+=a[i][j]*b[j][l])%=mod;
    return c;
}
Mat pw(Mat x,int p) {
    int n=x.size();
    Mat r(n,Vi(n));
    REP(i,n) r[i][i]=1;
    while(p>0) {
        if(p&1) r=r*x;
        x=x*x;
        p>>=1;
    }
    return r;
}
Mat M_z;
struct SEG {
    vector<Mat> s;
    int n,ms;
    void build(int w,int l,int r,vector<Mat> &a) {
        if(l==r) {
            s[w]=a[l];
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        s[w]=s[w<<1]*s[w<<1|1];
    }
    void init(int _n,int _ms,vector<Mat> a) {
        n=_n;
        ms=_ms;
        s=vector<Mat>(n<<2);
        build(1,0,n-1,a);
    }   
    void _qu(int w,int l,int r,int ql,int qr,Mat &an) {
        if(ql<=l&&r<=qr) {
            an=an*s[w];
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        _qu(w<<1,l,m,ql,qr,an);
        _qu(w<<1|1,m+1,r,ql,qr,an);
    }
    Mat qu(int l,int r) {
        Mat an(1,Vi(ms));
        an[0].back()=1;
        _qu(1,0,n-1,l,r,an);
        return an;
    }
}seg;
signed main() {
    IOS();
    string s;
    cin>>s;
    int n=s.size();
    M_z=Mat(10,Vi(10));
    REP(i,10) M_z[i][i]=1;
    vector<Mat> ch(9,M_z);
    REP(i,10) REP(j,10) ch[i][j][i]=1;
    vector<Mat> a(n);
    REP(i,n) a[i]=ch[s[i]-'a'];
    seg.init(n,10,a);
    int q;
    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r,l--,r--;
        Mat ret=seg.qu(l,r);
        int sum=0;
        REP(i,9) (sum+=ret[0][i])%=mod;
        cout<<sum<<'\n';
    }
    return 0;
}