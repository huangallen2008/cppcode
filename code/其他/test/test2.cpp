#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ld long double
const int inf=1e14+5;
const int maxn=2e5+5;
const int mod=1e9+7;
vector<int> a;
struct SEG {
    struct Seg {
        int l,r,sum,t,td;
//        Seg(int _l,int _r,int _sum,int _t,int _td) : l(_l),r(_r),sum(_sum),t(_t),td(_td) {}
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.sum=b.sum+c.sum;
        a.l=b.l;
        a.r=c.r;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        b.t+=a.t;
        b.td+=a.td;
        b.sum+=(b.r-b.l+1)*(a.t*2+(b.r-b.l)*a.td)/2;
        c.t+=a.t+(c.l-a.l)*a.td;
        c.td+=a.td;
        c.sum+=(c.r-c.l+1)*((a.t+(c.l-a.l)*a.td)*2+(c.r-c.l)*a.td)/2;
        a.t=0;
        a.td=0;
    }
    int n;
    vector<Seg> s;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n*4);
    }
    void build(int w,int l,int r) {
        if(l==r) {
            s[w]={l,r,a[l],0,0};
            return;
        }
        int m=(l+r)/2;
        build(w*2,l,m);
        build(w*2+1,m+1,r);
        pull(s[w],s[w*2],s[w*2+1]);
    }
    void ud(int w,int l,int r,int ul,int ur) {
        if(ul<=l&&r<=ur) {
            s[w].sum+=(r-l+1)*((l-ul+1)*2+(r-l))/2;
            s[w].t+=l-ul+1;
            s[w].td++;
            return;
        }
        if(ul>r||ur<l) return;
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        ud(w*2,l,m,ul,ur);
        ud(w*2+1,m+1,r,ul,ur);
        pull(s[w],s[w*2],s[w*2+1]);
    }
    int qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].sum;
        if(ql>r||qr<l) return 0;
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        return qu(w*2,l,m,ql,qr)+qu(w*2+1,m+1,r,ql,qr);
    }
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    SEG seg;
    seg.init(n);
    seg.build(1,0,n-1);
    REP(i,q) {
        int x,l,r;
        cin>>x>>l>>r;
        l--,r--;
        if(x==1) seg.ud(1,0,n-1,l,r);
        else cout<<seg.qu(1,0,n-1,l,r)<<"\n";
    }
    return 0;
