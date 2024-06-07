#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) ((x%(mod)+(mod))%(mod))
#define pnn pair<Node,Node>
#ifdef local
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
struct Node {
    int x,y,z;
};
struct Q {
    int a,b;
    int id;
    Q(){}
    Q(int _a,int _b,int _id) : a(_a),b(_b),id(_id){}
};
struct edge {
    int u,v,d;
};
bool edges_sort(edge a,edge b) {
    return a.d<b.d;
}
int f,m,n,r,q;
int id(Node a) { return a.x*m*n+a.y*n+a.z; }
vector<int> dis;
vector<Node> rt;
vector<edge> edges;
bool dis_ud(int u,int v,int x,int y,int z) {
    if(x<0||x>=f||y<0||y>=m||z<0||z>=n) return 0;
    if(dis[v]!=-1) return 0;
    dis[v]=dis[u]+1;
    return 1;
}
void build_dis() {
    queue<int> q;
    REP(i,r) {
        int nid=id(rt[i]);
        q.push(nid);
        dis[nid]=0;
    }
    while(q.size()) {
        int u=q.front();
        q.pop();
        int x=u/(m*n),y=(u/n)%m,z=u%n;
        if(dis_ud(u,u+m*n,x+1,y,z)) q.push(u+m*n);
        if(dis_ud(u,u+n,x,y+1,z)) q.push(u+n);
        if(dis_ud(u,u+1,x,y,z+1)) q.push(u+1);
        if(dis_ud(u,u-m*n,x-1,y,z)) q.push(u-m*n);
        if(dis_ud(u,u-n,x,y-1,z)) q.push(u-n);
        if(dis_ud(u,u-1,x,y,z-1)) q.push(u-1);
    }
}
void build_edges() {
    REP(x,f) {
        REP(y,m) {
            REP(z,n) {
                int ida=id({x,y,z});
                if(x<f-1) edges.pb({ida,ida+m*n,min(dis[ida],dis[ida+m*n])});
                if(y<m-1) edges.pb({ida,ida+n,min(dis[ida],dis[ida+n])});
                if(z<n-1) edges.pb({ida,ida+1,min(dis[ida],dis[ida+1])});
            }
        }
    }
    sort(ALL(edges),edges_sort);
}
struct DSU {
    vector<int> p,sz;
    int n;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n);
        REP(i,n) p[i]=i;
        REP(i,n) sz[i]=1;
    }
    void init2(int l,int r) {
        for(int i=l;i<=r;i++) {
            int a=edges[i].u,b=edges[i].v;
            p[a]=a,p[b]=b;
            sz[a]=1,sz[b]=1;
        }
    }
    void init3(vector<Q> &qu) {
        REP(i,qu.size()) {
            p[qu[i].a]=qu[i].a,p[qu[i].b]=qu[i].b;
            sz[qu[i].a]=1,sz[qu[i].b]=1;
        }
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
    }
    bool same(int a,int b) {
        return find(a)==find(b);
    }
};
DSU dsu;
vector<int> an;
void BS(vector<Q> &qu,int l,int r) {
    if(qu.size()==0) return;
    if(l==r) {
        REP(i,qu.size()) an[qu[i].id]=edges[l].d;
        return;
    }
    int o=(l+r)/2;
    dsu.init2(l,r);
    dsu.init3(qu);
    for(int i=o+1;i<=r;i++) dsu.merge(edges[i].u,edges[i].v);
    vector<Q> ql,qr;
    REP(i,qu.size()) {
        if(dsu.same(qu[i].a,qu[i].b)) ql.pb(qu[i]);
        else qr.pb(Q(dsu.find(qu[i].a),dsu.find(qu[i].b),qu[i].id));
    }
    for(int i=l;i<=o;i++) {
        edges[i].u=dsu.find(edges[i].u);
        edges[i].v=dsu.find(edges[i].v);
    }
    BS(ql,o+1,r);
    BS(qr,l,o);
}
signed main() {
    IOS();
    cin>>f>>m>>n>>r;
    dsu.init(f*m*n);
    dis=vector<int>(f*m*n,-1);
    rt=vector<Node>(r);
    REP(i,r) {
        cin>>rt[i].x>>rt[i].y>>rt[i].z;
        rt[i].x--,rt[i].y--,rt[i].z--;
    }
    build_dis();
    build_edges();
    cin>>q;
    an=vector<int>(q,-1);
    vector<Q> qu(q);
    REP(i,q) {
        Node s,e;
        cin>>s.x>>s.y>>s.z>>e.x>>e.y>>e.z;
        s.x--,s.y--,s.z--,e.x--,e.y--,e.z--;
        qu[i]=Q(id(s),id(e),i);
    }
    BS(qu,0,edges.size()-1);
    REP(i,q) cout<<an[i]<<'\n';
    return 0;
}
/*
3 3 3
3
1 1 1
2 2 2
3 3 3
4
1 3 3 3 1 1
1 2 2 3 2 2
1 2 3 1 2 3
1 1 1 3 3 3

2 1 2 0

-------
1 1 3
1
1 1 2
1
1 1 1 1 1 3

0

*/
