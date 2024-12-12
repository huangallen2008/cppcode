#include<bits/stdc++.h>
using namespace std;
#define int long long //int變成long long，可依照題目要求加或不加
struct SEG {
    int n;
    vector<int> s;
    void build(int w,int l,int r,vector<int> &a) {
        if(l==r) {
            s[w]=a[l];
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        s[w]=s[w<<1]+s[w<<1|1];
    }
    void init(int _n,vector<int> a) {
        n=_n;
        s=vector<int>(n<<2);//n*4
        build(1,0,n-1,a);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            s[w]+=v;
            return;
        }
        int m=l+r>>1;//(l+r)/2
        if(u<=m) _ud(w<<1,l,m,u,v);//w*2
        else _ud(w<<1|1,m+1,r,u,v);//w*2+1
        s[w]=s[w<<1]+s[w<<1|1];
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return 0;
        int m=l+r>>1;
        return _qu(w<<1,l,m,ql,qr)+_qu(w<<1|1,m+1,r,ql,qr);
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
}seg;
#define ld lonf double 
#define sp(x) fixed<<setprecision(x)
signed main() {//signed = int
    int n=6;
    vector<ld> a(n);
    REP(i,n) cin>>a[i];
    vector<ld> b(n);
    REP(i,n) b[i]=a[i]/0.0877;
    vector<int> c(n-1);
    REP(i,n-1) c[i]=b[i+1]-b[i];
    vector<ld> d(n-1);
    REP(i,n-1) d[i]=c[i]/0.877;
    ld avg=0;
    REP(i,n-1) avg+=d[i];
    avg/=n-1;
    REP(i,n) cout<<sp(3)<<b[i]<<' ';cout<<'\n';
    REP(i,n-1) cout<<sp(3)<<c[i]<<' ';cout<<'\n';
    REP(i,n-1) cout<<sp(3)<<d[i]<<' ';cout<<'\n';
    cout<<sp(3)<<avg<<'\n';
    return 0;
}