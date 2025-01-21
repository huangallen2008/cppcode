#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
struct SEG {
    struct Seg {
        int l,r,sum,ss;
    };
    vector<Seg> s;
    void init(int n) {
        s=vector<Seg>(n*4);
    }
    void build(int w,int l,int r) {
        s[w]={l,r,0,0};
        if(l==r) return ;
        int m=(l+r)/2;
        build(w*2,l,m);
        build(w*2+1,m+1,r);
    }
    void ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w].sum=v;
            s[w].ss=v*v;
            return;
        }
        int m=(l+r)/2;
        if(u<=m) ud(w*2,l,m,u,v);
        else ud(w*2+1,m+1,r,u,v);
        s[w].sum=s[w*2].sum+s[w*2+1].sum;
        s[w].ss=s[w*2].ss+s[w*2+1].ss;
    }
    pii merge(pii a,pii b) {
        return {a.f+b.f,a.s+b.s};
    }
    pii qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return {s[w].sum,s[w].ss};
        if(ql>r||qr<l) return {0,0};
        int m=(l+r)/2;
        return merge(qu(w*2,l,m,ql,qr),qu(w*2+1,m+1,r,ql,qr));
    }
};
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    SEG seg;
    seg.init(n);
    seg.build(1,0,n-1);
    REP(i,n) seg.ud(1,0,n-1,i,a[i]);
    int q;
    cin>>q;
    REP(i,q) {
        int opt,x,y;
        cin>>opt>>x>>y;
        if(opt==1) {
            x--;
            seg.ud(1,0,n-1,x,y);
        }
        else {
            x--,y--;
            pii an=seg.qu(1,0,n-1,x,y);
//            op(an.f) ope(an.s)
            cout<<(an.f*an.f-an.s)/2<<'\n';
        }
//        REP(j,20) cout<<seg.s[j].sum<<' ';cout<<'\n';
    }
    return 0;
}
