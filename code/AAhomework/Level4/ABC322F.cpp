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
        int len,p0,s0,c0,p1,s1,c1,t;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.len=b.len+c.len;
        if(b.p0==b.len) a.p0=b.len+c.p0;
        else a.p0=b.p0;
        if(c.s0==c.len) a.s0=c.len+b.s0;
        else a.s0=c.s0;
        a.c0=max(b.s0+c.p0,max(b.c0,c.c0));
        if(b.p1==b.len) a.p1=b.len+c.p1;
        else a.p1=b.p1;
        if(c.s1==c.len) a.s1=c.len+b.s1;
        else a.s1=c.s1;
        a.c1=max(b.s1+c.p1,max(b.c1,c.c1));
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t) {
            b.t^=1;
            swap(b.p0,b.p1);
            swap(b.s0,b.s1);
            swap(b.c0,b.c1);
            c.t^=1;
            swap(c.p0,c.p1);
            swap(c.s0,c.s1);
            swap(c.c0,c.c1);
            a.t=0;
        }
    }
    Seg merge(Seg a,Seg b) {
        Seg c;
        pull(c,a,b);
        return c;
    }
    vector<Seg> s;
    string S;
    void build(int w,int l,int r) {
        if(l==r) {
            if(S[l]=='0') s[w]={1,1,1,1,0,0,0,0};
            else s[w]={1,0,0,0,1,1,1,0};
            return;
        }
        int m=(l+r)/2;
        build(w*2,l,m);
        build(w*2+1,m+1,r);
        pull(s[w],s[w*2],s[w*2+1]);
    }
    void init(int n,string &SS) {
        s=vector<Seg>(n*4);
        S=SS;
        build(1,0,n-1);
    }
    void ud(int w,int l,int r,int ul,int ur) {
        if(ul<=l&&r<=ur) {
            s[w].t^=1;
            swap(s[w].p0,s[w].p1);
            swap(s[w].s0,s[w].s1);
            swap(s[w].c0,s[w].c1);
            return;
        }
        if(ul>r||ur<l) return;
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        ud(w*2,l,m,ul,ur);
        ud(w*2+1,m+1,r,ul,ur);
        pull(s[w],s[w*2],s[w*2+1]);
    }
    Seg qu_s(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return {0,0,0,0,0,0,0,0};
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        return merge(qu_s(w*2,l,m,ql,qr),qu_s(w*2+1,m+1,r,ql,qr));
    }
    int qu(int w,int l,int r,int ql,int qr) {
        Seg ret=qu_s(w,l,r,ql,qr);
        return ret.c1;
    }
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    SEG seg;
    seg.init(n,s);
    REP(i,q) {
        int opt;
        cin>>opt;
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(opt==1) {
            seg.ud(1,0,n-1,l,r);
        }
        else {
            int an=seg.qu(1,0,n-1,l,r);
            cout<<an<<'\n';
        }
    }
    return 0;
}
