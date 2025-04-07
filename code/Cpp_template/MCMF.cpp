struct MCMF {
    struct E {
        int u,v,w,cap,r;
    };
    vector<E> e;
    Graph g;
    int n;
    int s,t;
    Vi dis,incf,vis,pre;
    void init(int _n) {
        n=_n;
        g=Graph(n);
    }
    void addedge(int u,int v,int w,int c) {
        e.pb({u,v,w,c,c});
        e.pb({v,u,-w,c,0});
        g[u].pb(SZ(e)-2);
        g[v].pb(SZ(e)-1);
    }
    int spfa() {
        dis=Vi(n,inf);
        incf=pre=vis=Vi(n);
        dis[s]=0;
        incf[s]=inf;
        vis[s]=1;
        queue<int> q;
        q.push(s);
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(auto id:g[u]) {
                auto [_,v,w,cap,r]=e[id];
                if(r==0||dis[v]<=dis[u]+w) continue;
                dis[v]=dis[u]+w;
                incf[v]=min(incf[u],r);
                pre[v]=id;
                if(!vis[v]) {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        if(dis[t]==inf) return 0;
        int fl=incf[t];
        int now=t;
        while(now!=s) {
            int id=pre[now];
            e[id].r-=fl;
            e[id^1].r+=fl;
            now=e[id].u;
        }
        return fl;
    }
    int mxf(int _s,int _t) {
        s=_s,t=_t;
        int an=0,mf;
        while(mf=spfa()) an+=mf;
        return an;
    }
};