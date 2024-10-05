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
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+9;
vector<int> s(maxn*4);
void ud(int w,int l,int r,int u,int v) {
    if(l==r) {
        s[w]=v;
        return;
    }
    int m=(l+r)/2;
    if(u<=m) ud(w*2,l,m,u,v);
    else ud(w*2+1,m+1,r,u,v);
    s[w]=min(s[w*2],s[w*2+1]);
}
int qu(int w,int l,int r,int ql,int qr) {
    if(ql<=l&&r<=qr) return s[w];
    if(qr<l||ql>r) return inf;
    int m=(l+r)/2;
    return min(qu(w*2,l,m,ql,qr),qu(w*2+1,m+1,r,ql,qr));
}
int n,m;
Graph g;
vector<int> a,d,t,h,w;
vector<bool> it,vis;
void dfs(int u) {
    int mx=0;
    vis[u]=1;
    if(it[u]&&g[u].size()==2) {
        h[u]=a[u];
        w[u]=max(a[u],(int)0);
        return;
    }
    if(g[u].size()==1&&vis[g[u][0]]) {
        h[u]=a[u];
        w[u]=max(a[u],(int)0);
        return;
    }
    for(int v:g[u]) {
        if(vis[v]) continue;
        if(it[v]) continue;
        dfs(v);
        w[u]=max(w[u],max(mx+h[v]+a[u],w[v]));
        mx=max(mx,h[v]);
        h[u]=max(h[u],h[v]+a[u]);
//        cout<<u<<":"<<v<<" "<<h[v]<<" "<<a[u]<<endl;
    }
}
signed main()
{
    IOS();
    cin>>n>>m;
    g=Graph(n);
    a=vector<int>(n);
    h=vector<int>(n);
    w=vector<int>(n);
    d=vector<int>(n);
    vis=vector<bool>(n);
    it=vector<bool>(n);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        d[u]++,d[v]++;
    }
    REP(i,n) cin>>a[i];
    bool al0=1;
    int mx=-inf;
    REP(i,n) {
        if(a[i]>0) al0=0;
        mx=max(mx,a[i]);
    }
    int root=0;
    if(m==n-1) {
        if(al0) cout<<mx<<"\n";
        else {
            dfs(root);
//            cout<<"h:";REP(i,n) cout<<h[i]<<" ";cout<<endl;
//            cout<<"w:";REP(i,n) cout<<w[i]<<" ";cout<<endl;
            cout<<w[root]<<"\n";
        }
    }
    else {
        int an=0;
        queue<int> q;
        REP(i,n) if(d[i]==1) q.push(i);
        while(q.size()) {
            int u=q.front();
            q.pop();
            for(int v:g[u]) {
                d[v]--;
                if(d[v]==1) q.push(v);
            }
        }
        REP(i,n) {
            if(d[i]>1) {
                t.pb(i);
                it[i]=1;
            }
        }
        REP(i,n) if(it[i]) dfs(i);
        REP(i,n) if(it[i]) an=max(an,w[i]);

        vis=vector<bool>(n);
        vector<int> st;
        st.pb(t[0]);
        vis[t[0]]=1;
        int nu=t[0];
        while(1) {
            if(st.size()==t.size()) break;
            for(int v:g[nu]) {
                if(!vis[v]&&it[v]) {
                    st.pb(v);
                    vis[v]=1;
                    nu=v;
                    break;
                }
            }
        }
        t=st;
        vector<int> v(t.size()*2-1),p(t.size()*2-1);
        p[0]=a[t[0]];
        v[0]=p[0]-h[t[0]];
        REP1(i,t.size()-2) {
            p[i]=p[i-1]+a[t[i]];
            v[i]=p[i]-h[t[i]];
            ud(1,0,t.size()*2-2,i,v[i]);
        }
        REP(i,t.size()) {
            int ni=t.size()-1+i;
            p[ni]=p[ni-1]+a[t[i]];
            v[ni]=p[ni]-h[t[i]];
            ud(1,0,t.size()*2-2,ni,v[ni]);
            an=max(an,p[ni-1]-qu(1,0,t.size()*2-2,ni-t.size()+1,ni-1)+h[t[i]]);
//            cout<<an<<endl;
        }
        cout<<an<<"\n";
    }
    return 0;
}
/*
8 7
6 8
2 6
1 3
1 2
1 4
1 5
5 7
-1 2 3 -10 -3 0 4 2
*/
