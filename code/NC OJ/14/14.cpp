#include<bits/stdc++.h>
using namespace std;
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
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int n,m,q,s,t;
    cin>>n>>m>>q>>s>>t;
    s--,t--;
    vector<vector<pii>> g(n);
    vector<int> qu(q);
    REP(i,q) {
        cin>>qu[i];
        qu[i]--;
    }
    REP(i,m) {
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        g[x].pb({y,z});
        g[y].pb({x,z});
    }
    vector<int> sd(n,-1),sc(n+1),td(n,-1),tc(n+1);
    priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
    pq.push({0,{n,s}});
    sc[n]=1;
    while(pq.size()) {
        int u=pq.top().s.s,p=pq.top().s.f,d=pq.top().f;
        pq.pop();
        if(sd[u]>=0&&d>sd[u]) continue;
        else if(sd[u]==d) sc[u]=(sc[u]+sc[p])%mod;
        else {
            sd[u]=d;
            sc[u]=sc[p];
            for(auto [v,l]:g[u])
                if(d+l==sd[v]||sd[v]<0)
                    pq.push({d+l,{u,v}});
        }
    }
    pq.push({0,{n,t}});
    tc[n]=1;
    while(pq.size()) {
        int u=pq.top().s.s,p=pq.top().s.f,d=pq.top().f;
        pq.pop();
        if(td[u]>=0&&td[u]<d) continue;
        else if(td[u]==d) tc[u]=(tc[u]+tc[p])%mod;
        else {
            td[u]=d;
            tc[u]=tc[p];
            for(auto [v,l]:g[u])
                if(d+l==td[v]||td[v]<0)
                    pq.push({d+l,{u,v}});
        }
    }
    REP(i,q) cout<<sd[qu[i]]+td[qu[i]]<<" "<<(sc[qu[i]]*tc[qu[i]])%mod<<"\n";
    return 0;
}
