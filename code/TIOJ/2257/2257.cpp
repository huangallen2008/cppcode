#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
Graph g;
vector<int> h,vis,l,r;
vector<pii> e;
int nid=0;
void build(int u) {
    vis[u]=1;
    REP(i,g[u].size()) {
        if(vis[g[u][i]]) continue;
        l[g[u][i]]=nid++;
        h[g[u][i]]=h[u]+1;
        build(g[u][i]);
        r[g[u][i]]=nid-1;
    }
}
struct seg {
    int l,r;
    int v=0;
    int t=0;
};
seg s[4*maxn];
void push(seg &a,seg &b,seg &c) {
    if(a.t) {
        b.v+=a.t*(b.r-b.l+1);
        b.t+=a.t;
        c.v+=a.t*(c.r-c.l+1);
        c.t+=a.t;
        a.t=0;
    }
}
void build_seg(int w,int l,int r) {
    s[w]={l,r,0,0};
    if(l==r) return;
    int m=(l+r)/2;
    build_seg(w*2,l,m);
    build_seg(w*2+1,m+1,r);
}
void ud(int w,int ul,int ur) {
    if(ul<=s[w].l&&s[w].r<=ur) {
        s[w].v+=s[w].r-s[w].l+1;
        s[w].t++;
        return;
    }
    if(ul>s[w].r||ur<s[w].l) return;
    push(s[w],s[w*2],s[w*2+1]);
    ud(w*2,ul,ur);
    ud(w*2+1,ul,ur);
    s[w].v=s[w*2].v+s[w*2+1].v;
}
int qu(int w,int u) {
    if(s[w].l==s[w].r) return s[w].v;
    push(s[w],s[w*2],s[w*2+1]);
    if(u<=(s[w].l+s[w].r)/2) return qu(w*2,u);
    else return qu(w*2+1,u);
}
int mx(int a,int b) {
    if(h[a]>h[b]) return a;
    return b;
}
main() {
    IOS();
    int n,root,t,w;
    cin>>n>>root>>t>>w;
    root--;
    g=Graph(n);
    h=vector<int>(n);
    vis=vector<int>(n);
    l=vector<int>(n);
    r=vector<int>(n);
    e=vector<pii>(n);
    int q=t+w;
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        e[i]={u,v};
    }
    h[root]=0;
    l[root]=nid++;
    r[root]=n-1;
    build(root);
    build_seg(1,0,n-1);
//    cout<<"l:";REP(i,n) cout<<l[i]<<" ";cout<<endl;
//    cout<<"r:";REP(i,n) cout<<r[i]<<" ";cout<<endl;
//    cout<<"h:";REP(i,n) cout<<h[i]<<" ";cout<<endl;
    REP(i,q) {
        int x;
        cin>>x;
        if(x==1) {
            int y,z;
            cin>>y>>z;
            z--;
            cout<<(h[z]-qu(1,l[z]))*y<<"\n";
        }
        else {
            int y;
            cin>>y;
            y--;
            int z=mx(e[y].f,e[y].s);
//            cout<<"z="<<z<<endl;
            ud(1,l[z],r[z]);
        }
//        REP1(j,10) cout<<s[j].v<<" ";cout<<endl;
    }
    return 0;
}
