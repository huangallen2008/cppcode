const int maxn=1e6+5;
const int inf=1ll<<29;


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

///////////////////////////

struct Seg {
    int mn,mx,v;
};
const Seg zero={inf,-inf,inf};
Seg s[maxn]={zero};
int lc[maxn],rc[maxn];
int node_id=1;
struct SEG {
    int n;
    Vi ver;
    int cver=0;
    void pull(int w) {
        int b=lc[w],c=rc[w];
        s[w].mn=min(s[b].mn,s[c].mn);
        s[w].mx=max(s[b].mx,s[c].mx);
        s[w].v=min({s[b].v,s[c].v,s[c].mn-s[b].mx});
    }
    void build(int &w,int l,int r) { if(!w) s[w=node_id++]=zero;
        if(l==r) return;
        int m=l+r>>1;
        build(lc[w],l,m);
        build(rc[w],m+1,r);
    }
    void init(int _n) {
        n=_n;
        ver.pb(node_id++);
        build(ver.back(),0,n-1);
    }
    int _ud(int w,int l,int r,int u,int v) {
        s[w=node_id++]=s[w];
        if(l==r) {
            s[w].mn=s[w].mx=v;
            return w;
        }
        int m=l+r>>1;
        if(u<=m) _ud(lc[w],l,m,u,v);
        else _ud(rc[w],m+1,r,u,v);
        pull(w);
        return w;
    }
    void ud(int u,int v) {
        ver.pb(_ud(ver.back(),0,n-1,u,v));
    }
    
};