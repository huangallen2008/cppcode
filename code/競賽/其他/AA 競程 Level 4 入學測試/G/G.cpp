#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
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
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
vector<int> a;
struct SEG {
    struct Seg {
        int v,l0r0,l0r1,l1r0,l1r1;
    };
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.l0r0=max(max(b.l0r1+c.l0r0,b.l0r0+c.l1r0),b.l0r0+c.l0r0);
        a.l0r1=max(max(b.l0r1+c.l0r1,b.l0r0+c.l1r1),b.l0r0+c.l0r1);
        a.l1r0=max(max(b.l1r1+c.l0r0,b.l1r0+c.l1r0),b.l1r0+c.l0r0);
        a.l1r1=max(max(b.l1r1+c.l0r1,b.l1r0+c.l1r1),b.l1r0+c.l0r1);
        a.v=max(max(a.l0r0,a.l0r1),max(a.l1r0,a.l1r1));
        a.v=max(a.v,max(b.v,c.v));
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.l0r0=max(max(b.l0r1+c.l0r0,b.l0r0+c.l1r0),b.l0r0+c.l0r0);
        a.l0r1=max(max(b.l0r1+c.l0r1,b.l0r0+c.l1r1),b.l0r0+c.l0r1);
        a.l1r0=max(max(b.l1r1+c.l0r0,b.l1r0+c.l1r0),b.l1r0+c.l0r0);
        a.l1r1=max(max(b.l1r1+c.l0r1,b.l1r0+c.l1r1),b.l1r0+c.l0r1);
        a.v=max(max(a.l0r0,a.l0r1),max(a.l1r0,a.l1r1));
        a.v=max(a.v,max(b.v,c.v));
    }
    vector<Seg> s;
    vector<int> a;
    void init(int n,vector<int> _a) {
        s=vector<Seg>(n*4);
        a=_a;
    }
    void build(int w,int l,int r) {
        if(l==r) {
            s[w]={a[l],0,0,0,max((int)0,a[l])};
            return;
        }
        int m=(l+r)/2;
        build(w*2,l,m);
        build(w*2+1,m+1,r);
        pull(s[w],s[w*2],s[w*2+1]);
    }
    Seg qu(int w,int l,int r,int ql,int qr) {
        if(ql>qr||ql>r||qr<l) return {0,0,0,0,0};
        if(ql<=l&&r<=qr) return s[w];
        int m=(l+r)/2;
        return merge(qu(w*2,l,m,ql,qr),qu(w*2+1,m+1,r,ql,qr));
    }
};
void solve() {
    int n;
    cin>>n;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    SEG seg;
    seg.init(n,a);
    seg.build(1,0,n-1);
    int q;
    cin>>q;
    REP(rd,q) {
        int m;
        cin>>m;
        vector<int> x(m);
        REP(i,m) {
            cin>>x[i];
            x[i]--;
        }
        int an=0;
        REP(i,m) an+=a[x[i]];
        if(m>0) {
            an+=seg.qu(1,0,n-1,0,x[0]-2).v;
            REP(i,m-1) an+=seg.qu(1,0,n-1,x[i]+2,x[i+1]-2).v;
            an+=seg.qu(1,0,n-1,x[m-1]+2,n-1).v;
        }
        else an+=seg.qu(1,0,n-1,0,n-1).v;
        cout<<an<<'\n';
    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
/*
1
5
1 2 3 4 5
5
1 3
2 2 4
2 1 4
1 5
0
*/
