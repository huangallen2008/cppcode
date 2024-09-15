#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=2e5+5;
const ll mod=1e9+7;
struct edge {
    int u,v,t;
};
struct DS {
    vector<int> p,sz;
    void init(int n) {
        p=vector<int>(n);
        sz=vector<int>(n,1);
    }
    void init2() {
        REP(i,p.size()) p[i]=i,sz[i]=1;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    bool merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return 0;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        return 1;
    }
};
vector<edge> e;
vector<pii> q;
vector<int> qi,an,qt;
int n,m;
DS ds;
void f(int l,int r,vector<int> &qi) {
//    cout<<l<<"~"<<r<<": { ";
//    for(int id:qi) cout<<id<<" ";
//    cout<<"}"<<endl;
    if(qi.size()==0) return;
    if(l==r) {
        for(int id:qi) an[qt[id]]=e[l].t;
        return;
    }
    vector<int> q1,q2;
    int m=(l+r)/2;
//    ds.init(n);
    for(int i=l;i<=r;i++) ds.p[e[i].u]=e[i].u,ds.p[e[i].v]=e[i].v;
    for(int i=l;i<=r;i++) ds.sz[e[i].u]=1,ds.sz[e[i].v]=1;
    for(int i=l;i<=m;i++) ds.merge(e[i].u,e[i].v);
    for(int id:qi) {
//    cout<<id<<endl;
        if(ds.find(q[id].f)==ds.find(q[id].s)) q1.pb(id);
        else q2.pb(id);
    }
    for(int i=m+1;i<=r;i++) {
        e[i].u=ds.find(e[i].u),e[i].v=ds.find(e[i].v);
    }
    REP(i,q2.size()) {
        q[q2[i]]={ds.find(q[q2[i]].f),ds.find(q[q2[i]].s)};
    }
    f(l,m,q1);
    f(m+1,r,q2);
}
signed main() {
    IOS();
    cin>>n>>m;
    an=vector<int>(m);
    ds.init(n);
    ds.init2();
    REP(i,m) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(ds.merge(a,b)) e.pb({a,b,i+1});
        else {
            q.pb({a,b});
            qt.pb(i);
        }
    }
    REP(i,q.size()) qi.pb(i);
//    REP(i,e.size()) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].t<<endl;
    f(0,e.size()-1,qi);
    REP(i,m) {
        if(an[i]==0) cout<<"Mukyu\n";
        else cout<<an[i]<<'\n';
    }
    return 0;
}
/*
3 3
1 2
2 3
1 3

2 3
2 1
1 2
2 1

6 8
1 2
2 1
1 3
4 3
3 2
3 5
1 5
1 4


*/
