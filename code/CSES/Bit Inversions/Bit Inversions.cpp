#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
const int maxn=500+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int len,mx_c,pre_c0,pre_c1,suf_c0,suf_c1;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.len=b.len+c.len;
        a.pre_c0=(b.pre_c0==b.len?b.len+c.pre_c0:b.pre_c0);
        a.pre_c1=(b.pre_c1==b.len?b.len+c.pre_c1:b.pre_c1);
        a.suf_c0=(c.suf_c0==c.len?c.len+b.suf_c0:c.suf_c0);
        a.suf_c1=(c.suf_c1==c.len?c.len+b.suf_c1:c.suf_c1);
        a.mx_c=max(max(b.mx_c,c.mx_c),max(b.suf_c0+c.pre_c0,b.suf_c1+c.pre_c1));
    }
    vector<Seg> s;
    string a;
    void build(int w,int l,int r) {
        if(l==r) {
            if(a[l]=='0') s[w]={1,1,1,0,1,0};
            else s[w]={1,1,0,1,0,1};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int n,string &_a) {
        a=_a;
        s=vector<Seg>(n<<2);
        build(1,0,n-1);
    }
    void ud(int w,int l,int r,int u) {
        if(l==r) {
            swap(s[w].pre_c0,s[w].pre_c1);
            swap(s[w].suf_c0,s[w].suf_c1);
            return ;
        }
        int m=l+r>>1;
        if(u<=m) ud(w<<1,l,m,u);
        else ud(w<<1|1,m+1,r,u);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    int get_an() {
        return s[1].mx_c;
    }
}seg;
signed main() {
    IOS();
    string s;
    cin>>s;
    int n=s.size();
    seg.init(n,s);
    int m;
    cin>>m;
    REP(i,m) {
        int x;
        cin>>x;
        x--;
        seg.ud(1,0,n-1,x);
        cout<<seg.get_an()<<' ';
    }
    cout<<'\n';
    return 0;
}