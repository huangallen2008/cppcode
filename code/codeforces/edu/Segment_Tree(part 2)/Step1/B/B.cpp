#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    void push(int &a,int &b,int &c) {
        chmax(b,a);
        chmax(c,a);
        a=0;
    }
    vector<int> s;
    void init(int n) {
        s=vector<int>(n<<2);
    }
    void ud(int w,int l,int r,int ul,int ur,int v) {
        if(ul<=l&&r<=ur) {
            chmax(s[w],v);
            return;
        }
        if(ul>r||ur<l) return;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        ud(w<<1,l,m,ul,ur,v);
        ud(w<<1|1,m+1,r,ul,ur,v);
    }
    int qu(int w,int l,int r,int u) {
        if(l==r) return s[w];
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        if(u<=m) return qu(w<<1,l,m,u);
        else return qu(w<<1|1,m+1,r,u);
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    seg.init(n);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,v;
            cin>>l>>r>>v;
            seg.ud(1,0,n-1,l,r-1,v);
        }
        else {
            int u;
            cin>>u;
            cout<<seg.qu(1,0,n-1,u)<<'\n';
        }
    }
    return 0;
}