#include<bits/stdc++.h>
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
#define b(x) ;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
struct edge {
    int u,v,d;
};
bool esort(edge a,edge b) {
    return a.d<b.d;
}
struct DS {
    vector<int> p;
    DS(int n) {
        p=vector<int>(n);
        REP(i,n) p[i]=i;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    bool merge(int x,int y) {
        int a=find(x),b=find(y);
        if(a==b) return 0;
        p[a]=b;
        return 1;
    }
};
int n,m,q;
vector<int> an,qi;
vector<pii> qu;
vector<edge> ae;
void d(vector<edge> e,vector<int> q,int l,int r) {
    cout<<l<<" "<<r<<" ";
    cout<<"{";
    REP(i,q.size()) cout<<q[i]<<",";//cout<<"{"<<qu[q[i]].f<<","<<qu[q[i]].s<<"}  ";
    cout<<"}"<<endl;
    if(l==r) {
        for(auto x:q) an[x]=ae[l].d;
        return;
    }
    DS ds(n);
    int m=(e.size()-1)/2;
    for(int i=0;i<=m;i++) {
        ds.merge(e[i].u,e[i].v);
    }
    vector<int> q1,q2;
    map<int,bool> mp;
    for(int i=(l+r)/2+1;i<=ae.size()-1;i++) mp[min(ae[i].u,ae[i].v)*1e6+max(ae[i].u,ae[i].v)]=1;
    REP(i,q.size()) {
        int f1=ds.find(qu[q[i]].f),f2=ds.find(qu[q[i]].s);
        if(f1==f2) q1.pb(q[i]);
        else {
            if(mp[min(f1,f2)*1e6+max(f1,f2)]>0) q1.pb(q[i]);
            else {
                qu[q[i]]={f1,f2};
                q2.pb(q[i]);
            }
        }
    }
    vector<edge> e2;
    for(int i=m+1;i<=e.size()-1;i++) {
        e2.pb({ds.find(e[i].u),ds.find(e[i].v)});
    }
    REP(i,e.size()-1-m) e.pop_back();
    if(q1.size()) d(e,q1,l,(l+r)/2);
    if(q2.size()) d(e2,q2,(l+r)/2+1,r);
}
signed main()
{
    IOS();
    cin>>n>>m>>q;
    DS ds(n);
    vector<edge> e0;
    an=vector<int>(n);
    REP(i,m) {
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        e0.pb({x,y,z});
        bool tt=ds.merge(x,y);
    }
    sort(ALL(e0),esort);
//    REP(i,m) if(ds.merge(e0[i].u,e0[i].v)) ae.pb(e0[i]);
    REP(i,m) ae.pb(e0[i]);
    REP(i,q) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(ds.find(x)!=ds.find(y)) an[i]=-1;
        else {
            qu.pb({x,y});
            qi.pb(i);
        }
    }
    cout<<endl<<endl;
    REP(i,ae.size()) cout<<ae[i].u<<" "<<ae[i].v<<" "<<ae[i].d<<"\n";
    cout<<endl;
    REP(i,qi.size()) cout<<qu[qi[i]].f<<" "<<qu[qi[i]].s<<"\n";
    cout<<endl;
    d(ae,qi,0,ae.size()-1);
    REP(i,q) cout<<an[i]<<"\n";
    return 0;
}
