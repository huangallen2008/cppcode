#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxv=(1ll<<30);
const int high_bit=30;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int mx,t;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mx=max(b.mx,c.mx);
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t) {
            b.mx+=a.t;
            b.t+=a.t;
            c.mx+=a.t;
            c.t+=a.t;
            a.t=0;
        }
    }
    vector<Seg> s;
    void init(int n) {
        s=vector<Seg>(n<<2);
    }
    void ud(int w,int l,int r,int ul,int ur,int v) {
        if(ul<=l&&r<=ur) {
            s[w].mx+=v;
            s[w].t+=v;
            return;
        }
        if(ul>r||ur<l) return ;
        int m=(l+r)>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        ud(w<<1,l,m,ul,ur,v);
        ud(w<<1|1,m+1,r,ul,ur,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    int qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].mx;
        if(ql>r||qr<l) return 0;
        int m=(l+r)>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return max(qu(w<<1,l,m,ql,qr),qu(w<<1|1,m+1,r,ql,qr));
    }
} seg;
struct evn {
    int l,r,v;
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> e(n+1);
    REP(i,m) {
        int l,r,v;
        cin>>l>>r>>v;
        e[r].pb({l,v});
    }
    seg.init(n+1);
    REP1(i,n) {
        seg.ud(1,0,n,i,i,seg.qu(1,0,n,0,i-1));
        for(auto [l,v]:e[i]) {
            seg.ud(1,0,n,l,i,v);
        }
    }
    int an=seg.qu(1,0,n,0,n);
    cout<<an<<'\n';
    return 0;
}
