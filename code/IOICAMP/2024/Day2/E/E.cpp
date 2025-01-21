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
        int t1,tn,ts;
    };
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t1!=-1) {
            if(b.t1==-1) b.t1=a.t1;
            else b.ts+=a.t1^b.tn;
            b.ts+=a.ts;
            b.tn=a.tn;
            if(c.t1==-1) c.t1=a.t1;
            else c.ts+=a.t1^c.tn;
            c.ts+=a.ts;
            c.tn=a.tn;
            a.t1=-1,a.tn=-1,a.ts=0;
        }
    }
    vector<Seg> s;
    void init(int n) {
        s=vector<Seg>(n*4);
    }
    void build(int w,int l,int r) {
        s[w]={-1,-1,0};
        if(l==r) return;
        int m=(l+r)/2;
        build(w*2,l,m);
        build(w*2+1,m+1,r);
    }
    void ud(int w,int l,int r,int ul,int ur,int v) {
        if(ul<=l&&r<=ur) {
            if(s[w].t1==-1) s[w].t1=v;
            else s[w].ts+=s[w].tn^v;
            s[w].tn=v;
            return;
        }
        if(ul>r||ur<l) return;
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        ud(w*2,l,m,ul,ur,v);
        ud(w*2+1,m+1,r,ul,ur,v);
    }
    int qu(int w,int l,int r,int u) {
        if(l==r) return s[w].ts;
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        if(u<=m) return qu(w*2,l,m,u);
        else return qu(w*2+1,m+1,r,u);
    }
};
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    SEG seg;
    seg.init(n);
    seg.build(1,0,n-1);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,x;
            cin>>l>>r>>x;
            l--,r--;
            seg.ud(1,0,n-1,l,r,x);
        }
        else {
            int p;
            cin>>p;
            p--;
            int an=seg.qu(1,0,n-1,p);
            cout<<an<<'\n';
        }
    }
    return 0;
}
