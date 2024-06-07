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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e6;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
struct SEG {
    struct Seg {
        int len,mn,mnc,t;
    };
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t) {
            b.t+=a.t;
            b.mn+=a.t;
            c.t+=a.t;
            c.mn+=a.t;
            a.t=0;
        }
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mn=min(b.mn,c.mn);
        a.mnc=0;
        if(a.mn==b.mn) a.mnc+=b.mnc;
        if(a.mn==c.mn) a.mnc+=c.mnc;
    }
    vector<Seg> s;
    void build(int w,int l,int r) {
        s[w]={r-l+1,0,r-l+1,0};
        if(l==r) return;
        int m=(l+r)/2;
        build(w*2,l,m);
        build(w*2+1,m+1,r);
    }
    void init(int n) {
        s=vector<Seg>(n*4);
        build(1,0,n-1);
    }
    void ud(int w,int l,int r,int ul,int ur,int v) {
        if(ul<=l&&r<=ur) {
            s[w].t+=v;
            s[w].mn+=v;
            return;
        }
        if(ul>r||ur<l) return;
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        ud(w*2,l,m,ul,ur,v);
        ud(w*2+1,m+1,r,ul,ur,v);
        pull(s[w],s[w*2],s[w*2+1]);
    }
    pii get_an() {
        return {s[1].mn,s[1].mnc};
    }
};
struct Rec {
    int l,r,v;
};
signed main() {
    IOS();
    int n;
    cin>>n;
    int N=maxv*2;
    vector<vector<Rec>> rec(N+5);
    REP(i,n) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1+=maxv;
        y1+=maxv;
        x2+=maxv;
        y2+=maxv;
        rec[x1].pb({y1,y2-1,1});
        rec[x2].pb({y1,y2-1,-1});
    }
    int an=0;
    SEG seg;
    seg.init(N);
    REP(i,N) {
        for(auto [l,r,v]:rec[i]) {
            seg.ud(1,0,N-1,l,r,v);
        }
        pii ret=seg.get_an();
        if(ret.f==0) an+=N-ret.s;
        else an+=N;
    }
    cout<<an<<'\n';
    return 0;
}
