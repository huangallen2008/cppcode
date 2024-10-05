#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
// #define int long long
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int M;
// #define Matrix vector<vector<int>>
struct Matrix {
    int a,b,c,d;
};
Matrix operator*(Matrix a,Matrix b) {
    Matrix c;
    c.a=(a.a*b.a+a.b*b.c)%M;
    c.b=(a.a*b.b+a.b*b.d)%M;
    c.c=(a.c*b.a+a.d*b.c)%M;
    c.d=(a.c*b.b+a.d*b.d)%M;
    return c;
}
struct SEG {
    vector<Matrix> s;
    void build(int w,int l,int r,vector<Matrix> &a) {
        if(l==r) {
            s[w]=a[l];
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        s[w]=s[w<<1]*s[w<<1|1];
    }
    void init(int n,vector<Matrix> &a) {
        s=vector<Matrix>(n<<2);
        build(1,0,n-1,a);
    }
    Matrix qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return {1,0,0,1};
        int m=l+r>>1;
        return qu(w<<1,l,m,ql,qr)*qu(w<<1|1,m+1,r,ql,qr);
    }
}seg;
signed main() {
    IOS();
    cin>>M;
    int n,q;
    cin>>n>>q;
    vector<Matrix> a(n);
    REP(i,n) {
        cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
    }
    seg.init(n,a);
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        l--,r--;
        Matrix an=seg.qu(1,0,n-1,l,r);
        cout<<an.a<<' '<<an.b<<'\n'<<an.c<<' '<<an.d<<'\n'<<'\n';
    }
    return 0;
}