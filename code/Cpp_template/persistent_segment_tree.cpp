struct SEG {//a[u]+=v,sum(l,r)
    int s[maxn];
    int lc[maxn];
    int rc[maxn];
    int n;
    int node_id=1;
    Vi ver;
    int _ud(int w,int l,int r,int u,int v) {
        int nn=node_id++;
        if(!w) w=nn;
        lc[nn]=lc[w],rc[nn]=rc[w],s[nn]=s[w];
        if(l==r) {
            s[nn]+=v;
            return nn;
        }
        int m=l+r>>1;
        if(u<=m) lc[nn]=_ud(lc[nn],l,m,u,v);
        else rc[nn]=_ud(rc[nn],m+1,r,u,v);
        s[nn]=s[lc[nn]]+s[rc[nn]];
        return nn;
    }
    int ud(int root,int u,int v) {
        return _ud(root,0,n-1,u,v);
    }
    void init(int _n,Vi &a) {
        n=_n+1;
        ver=Vi(_n+1);
        ver[0]=1;
        Vi las(n);
        REP1(i,_n) {
            ver[i]=ud(ud(ver[i-1],las[a[i]],-1),i,1);
            las[a[i]]=i;
        }
    }
    int _qu(int &w,int l,int r,int ql,int qr) {
        if(!w) return 0;
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return 0;
        int m=l+r>>1;
        return _qu(lc[w],l,m,ql,qr)+_qu(rc[w],m+1,r,ql,qr);
    }
    int qu(int l,int r) {
        return _qu(ver[r],0,n-1,l,r);
    }
}seg;