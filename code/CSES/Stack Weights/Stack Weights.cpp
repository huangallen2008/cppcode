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
//shuffle(a,a+n,rng)
struct SEG {
    struct Seg {
        int mx,mn,t;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mx=max(b.mx,c.mx);
        a.mn=min(b.mn,c.mn);
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t) {
            b.mn+=a.t;
            b.mx+=a.t;
            b.t+=a.t;
            c.mn+=a.t;
            c.mx+=a.t;
            c.t+=a.t;
            a.t=0;
        }
    }
    vector<Seg> s;
    void init(int n) {
        s=vector<Seg>(n<<2);
//        build(1,0,n-1);
    }
    void ud(int w,int l,int r,int ul,int ur,int v) {
        if(ul<=l&&r<=ur) {
            s[w].mx+=v;
            s[w].mn+=v;
            s[w].t+=v;
            return ;
        }
        if(ul>r||ur<l) return ;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=(l+r)>>1;
        ud(w<<1,l,m,ul,ur,v);
        ud(w<<1|1,m+1,r,ul,ur,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    pii get_an() {
        return {s[1].mx,s[1].mn};
    }
} seg;
signed main() {
    IOS();
    int n;
    cin>>n;
    seg.init(n);
    REP(i,n) {
        int v,t;
        cin>>v>>t;
        v--;
        if(t==1) seg.ud(1,0,n-1,0,v,1);
        else seg.ud(1,0,n-1,0,v,-1);
        pii ret=seg.get_an();
        if(ret.f<=0) cout<<"<\n";
        else if(ret.s>=0) cout<<">\n";
        else cout<<"?\n";
    }
    return 0;
}
