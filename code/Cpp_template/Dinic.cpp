struct Dinic {
    struct E {
        int u,v,cap,r;
    };
    vector<E> es;
    Graph g;
    int n;
    int s,t;
    Vi dis,it;
    void init(int _n) {
        n=_n;
        g=Graph(n);
    }
    void addedge(int u,int v,int c) {
        es.pb({u,v,c,c});
        es.pb({v,u,c,0});
        g[u].pb(SZ(es)-2);
        g[v].pb(SZ(es)-1);
    }
    bool bfs() {
        dis=Vi(n,inf);
        dis[s]=0;
        queue<int> q;
        q.push(s);
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            for(auto id:g[u]) {
                auto [_,v,cap,r]=es[id];
                if(r&&dis[v]>dis[u]+1) {
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return dis[t]!=inf;
    }
    int dfs(int u,int cap) {
        if(u==t||cap==0) return cap;
        int an=0;
        for(int &i=it[u];i<SZ(g[u]);i++) {
            int id=g[u][i];
            auto [_,v,_c,r]=es[id];
            if(dis[v]!=dis[u]+1) continue;
            int ret=dfs(v,min(cap,r));
            if(ret>0) {
                es[id].r-=ret;
                es[id^1].r+=ret;
                an+=ret;
                cap-=ret;
                if(cap==0) break;
            }
        }
        return an;
    }
    int mxf(int _s,int _t) {
        s=_s,t=_t;
        int an=0,mf;
        while(bfs()) {
            it=Vi(n);
            while((mf=dfs(s,inf))>0) {
                an+=mf;
            }
        }
        return an;
    }
    bool inS(int u) { return dis[u]!=inf; } //min cut
};