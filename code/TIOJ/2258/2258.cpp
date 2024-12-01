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
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
const int inf=(1ll<<63)-1;
const int maxn=6e5+5;
const int mod=1e9+7;
int id(int x) { return x>>1; }
vector<int> h,d0,d1;//0:(n+1)/2,1:n/2
struct seg {
    int l,r;
    int v;
};
// seg s0[maxn*4],s1[maxn*4];//d[i]=abs([i+1]-[i])
// void build0(int w,int l,int r) {
//     s0[w]={l,r,0};
//     if(l==r) {
//         s0[w].v=d0[l];
//         return;
//     }
//     int m=(l+r)/2;
//     build0(w*2,l,m);
//     build0(w*2+1,m+1,r);
//     s0[w].v=max(s0[w*2].v,s0[w*2+1].v);
// }
// int qu0(int w,int ql,int qr) {
//     if(ql>qr) return 0;
//     if(ql<=s0[w].l&&s0[w].r<=qr) return s0[w].v;
//     if(ql>s0[w].r||qr<s0[w].l) return 0;
//     return max(qu0(w*2,ql,qr),qu0(w*2+1,ql,qr));
// }
// void build1(int w,int l,int r) {
//     s1[w]={l,r,0};
//     if(l==r) {
//         s1[w].v=d1[l];
//         return;
//     }
//     int m=(l+r)/2;
//     build1(w*2,l,m);
//     build1(w*2+1,m+1,r);
//     s1[w].v=max(s1[w*2].v,s1[w*2+1].v);
// }
// int qu1(int w,int ql,int qr) {
//     if(ql>qr) return 0;
//     if(ql<=s1[w].l&&s1[w].r<=qr) return s1[w].v;
//     if(ql>s1[w].r||qr<s1[w].l) return 0;
//     return max(qu1(w*2,ql,qr),qu1(w*2+1,ql,qr));
// }
struct SEG {
    Vi s;
    int n;
    void build(int w,int l,int r,Vi &a) {
        if(l==r) {
            s[w]=a[l];
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        s[w]=max(s[w<<1],s[w<<1|1]);
    }
    void init(int _n,Vi &a) {
        n=_n;
        s=Vi(n<<2);
        build(1,0,n-1,a);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return 0;
        int m=l+r>>1;
        return max(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
}seg0,seg1;
signed main()
{
    IOS();
    int n,k,p;
    cin>>n>>k>>p;
    int n0=(n+1)/2-1,n1=n/2-1;
    h=vector<int>(n);
    d0=vector<int>(n);
    d1=vector<int>(n);
    REP(i,n) cin>>h[i];
    sort(ALL(h));
    REP(i,n0) d0[i]=abs(h[i*2]-h[(i+1)*2]);
    REP(i,n1) d1[i]=abs(h[i*2+1]-h[(i+1)*2+1]);
    seg0.init(n0,d0);
    seg1.init(n1,d1);
    int an=inf;
    auto cost=[&](int i) {
        
        int l=i,r=i+k-1;
        int l0=id(l+l%2),r0=id(r-r%2);
        int l1=id(l+(l+1)%2),r1=id(r-(r+1)%2);
//        cout<<l0<<" "<<r0<<"\n";
//        cout<<"Q"<<qu1(1,l1,r1-1)<<endl;
        return max(max(seg0.qu(l0,r0-1),seg1.qu(l1,r1-1)),max(abs(h[i]-h[i+1]),abs(h[i+k-1]-h[i+k-2])));
        // an=min(an,max(max(qu0(1,l0,r0-1),qu1(1,l1,r1-1)),max(abs(h[i]-h[i+1]),abs(h[i+k-1]-h[i+k-2]))));
    }
    // Vi dp(n);
    for(int i=0;i+k-1<n;i++) {
        chmax(an,cost(i));
        // dp[i]=max(dp[i-1],)
    }
    cout<<an<<"\n";
    return 0;
}
