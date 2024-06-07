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
    int u,v,t;
};
struct qs {
    vector<int> q;
    int l,r;
};
struct DS {
    vector<int> p;
    int c=0;
    DS(int n) {
        p=vector<int>(n);
        REP(i,n) p[i]=i;
        c=0;
    }
    int find(int u) {
        if(p[u]==u) return u;
        return p[u]=find(p[u]);
    }
    bool merge(int x,int y) {
        int a=find(x),b=find(y);
        if(a==b) return 0;
        p[a]=b;
        c++;
        return 1;
    }
};
signed main()
{
    IOS();
    int n,qu;
    cin>>n>>qu;
    DS ads(n);
    vector<vector<int>> q;
    vector<int> qi,qt;
    vector<edge> e;
    REP(i,qu) {
        int x;
        cin>>x;
        if(x==1) {
            int u,v;
            cin>>u>>v;
            u--,v--;
            if(ads.merge(u,v)) e.pb({u,v,i+1});
        }
        else {
            q.pb({});
            int k;
            cin>>k;
            REP(i,k) {
                int y;
                cin>>y;
                y--;
                q.back().pb(y);
            }
            qt.pb(i+1);
        }
    }
    vector<int> an(q.size());
//    cout<<"esize:"<<e.size()<<endl;
//    cout<<"et:"; REP(i,e.size()) cout<<e[i].t<<" ";cout<<endl;
    REP(i,q.size()) qi.pb(i);
    queue<qs> queue;
    queue.push({qi,0,(e.size()-1)*2});
    DS ds(n);
    while(queue.size()) {
//        cout<<"queue size:"<<queue.size()<<endl;
        vector<int> v=queue.front().q;
        int l=queue.front().l,r=queue.front().r;
        queue.pop();
//        cout<<l<<" "<<r<<" {";
//        REP(i,v.size()) cout<<v[i]<<" ";cout<<"}"<<endl;
        if(l>=e.size()) {
            for(int p:v) an[p]=-1;
            continue;
        }
        if(l==r) {
            for(int p:v) an[p]=e[l].t;
            continue;
        }
        int m=(l+r)/2;
        vector<int> lv,rv;
        if(ds.c>m) {
            ds=DS(n);
            REP(i,m+1) ds.merge(e[i].u,e[i].v);
        }
        else {
            for(int i=ds.c;i<=m;i++) ds.merge(e[i].u,e[i].v);
        }
        REP(i,v.size()) {
            bool il=1;
            int t=ds.find(q[v[i]][0]);
            REP1(j,q[v[i]].size()-1) {
                if(ds.find(q[v[i]][j])!=t) {
                    il=0;
//                    cout<<i<<" "<<j<<"o"<<" "<<ds.find(q[v[i]][0])<<"!="<<ds.find(q[v[i]][j])<<endl;
                    break;
                }
            }
            if(il) lv.pb(v[i]);
            else rv.pb(v[i]);
        }
        if(lv.size()) queue.push({lv,l,m});
        if(rv.size()) queue.push({rv,m+1,r});
    }
    REP(i,an.size()) {
        if(qt[i]<=an[i]) cout<<"-1\n";
        else cout<<an[i]<<"\n";
    }
    return 0;
}
