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
        int len,c1,t;
    };
    void pull(Seg &a,Seg &b,Seg &c) {
        a.c1=b.c1+c.c1;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        if(a.t) {
            b.t^=1;
            b.c1=b.len-b.c1;
            c.t^=1;
            c.c1=c.len-c.c1;
            a.t=0;
        }
    }
    vector<Seg> s;
    void build(int w,int l,int r) {
        s[w]={r-l+1,0,0};
        if(l==r) return;
        int m=(l+r)/2;
        build(w*2,l,m);
        build(w*2+1,m+1,r);
    }
    void init(int n) {
        s=vector<Seg>(n*4);
        build(1,0,n-1);
    }
    void ud(int w,int l,int r,int ul,int ur) {
        if(ul<=l&&r<=ur) {
            s[w].t^=1;
            s[w].c1=s[w].len-s[w].c1;
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
        if(ql<=l&&r<=qr) return s[w].c1;
        if(ql>r||qr<l) return 0;
        push(s[w],s[w*2],s[w*2+1]);
        int m=(l+r)/2;
        return qu(w*2,l,m,ql,qr)+qu(w*2+1,m+1,r,ql,qr);
    }
};
Graph g;
vector<int> in,out;
int cnt=0;
void dfs(int u,int p) {
    in[u]=cnt++;
    for(int v:g[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
    out[u]=cnt++;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    g=Graph(n);
    in=vector<int>(n);
    out=vector<int>(n);
    vector<int> p(n),t(n);
    REP1(i,n-1) {
        cin>>p[i];
        p[i]--;
        g[p[i]].pb(i);
    }
    int N=n*2;
    dfs(0,-1);
    SEG seg;
    seg.init(N);
    REP(i,n) {
        int t;
        cin>>t;
        if(t) {
            seg.ud(1,0,N-1,in[i],in[i]);
            seg.ud(1,0,N-1,out[i],out[i]);
        }
    }
    int q;
    cin>>q;
    REP(i,q) {
        string opt;
        int v;
        cin>>opt>>v;
        v--;
        if(opt[0]=='p') {
            seg.ud(1,0,N-1,in[v],out[v]);
        }
        else {
            int an=seg.qu(1,0,N-1,in[v],out[v])/2;
            cout<<an<<'\n';
        }
    }
    return 0;
}
