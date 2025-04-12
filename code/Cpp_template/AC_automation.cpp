struct AC_node {
    int fail;
    int ch[26];
    int cnt;
    bool vis;
}ac[maxn];
int AC_node_id=1;
struct AC {
    int root;
    void init() { 
        root=AC_node_id++; 
        ac[root].fail=root;
    }
    void add(string s) {
        int now=root;
        for(char _c:s) {
            int c=_c-'a';
            if(!ac[now].ch[c]) ac[now].ch[c]=AC_node_id++;
            now=ac[now].ch[c];
        }
        ac[now].cnt++;
    }
    void build(vector<string> v) {
        for(auto s:v) add(s);
        queue<int> q;
        REP(i,26) {
            if(ac[root].ch[i]) {
                ac[ac[root].ch[i]].fail=root;
                q.push(ac[root].ch[i]);
            }else ac[root].ch[i]=root;
        }
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            REP(c,26) {
                if(ac[u].ch[c]) {
                    ac[ac[u].ch[c]].fail=ac[ac[u].fail].ch[c];
                    q.push(ac[u].ch[c]);
                }else ac[u].ch[c]=ac[ac[u].fail].ch[c];
            }
        }
    }
    int qu(string s) {
        int now=root,an=0;
        Vi vv;
        for(char _c:s) {
            int c=_c-'a';
            now=ac[now].ch[c];
            for(int t=now;t!=root&&!ac[t].vis;t=ac[t].fail) {
                ac[t].vis=1;
                vv.pb(t);
                an+=ac[t].cnt;
            }
        }
        for(int x:vv) ac[x].vis=0;
        return an;
    }
};
////////////////////////
struct AC_node {
    int fail;
    int ch[26];
    int cnt;
    Vi end;
    bool vis;
}ac[maxn];
int AC_node_id=1;
struct AC {
    int root;
    int n;
    void init() { 
        root=AC_node_id++; 
        ac[root].fail=root;
    }
    void add(string s,int id) {
        int now=root;
        for(char _c:s) {
            int c=_c-'a';
            if(!ac[now].ch[c]) ac[now].ch[c]=AC_node_id++;
            now=ac[now].ch[c];
        }
        ac[now].cnt++;
        ac[now].end.pb(id);
    }
    void build(vector<string> v) {
        n=SZ(v);
        REP(i,n) add(v[i],i);
        queue<int> q;
        REP(i,26) {
            if(ac[root].ch[i]) {
                ac[ac[root].ch[i]].fail=root;
                q.push(ac[root].ch[i]);
            }else ac[root].ch[i]=root;
        }
        while(SZ(q)) {
            int u=q.front();
            q.pop();
            REP(c,26) {
                if(ac[u].ch[c]) {
                    ac[ac[u].ch[c]].fail=ac[ac[u].fail].ch[c];
                    q.push(ac[u].ch[c]);
                }else ac[u].ch[c]=ac[ac[u].fail].ch[c];
            }
        }
    }
    Vi qu(string s) {
        Vi an(n);
        int now=root;
        Vi vv;
        for(char _c:s) {
            int c=_c-'a';
            now=ac[now].ch[c];
            for(int t=now;t!=root&&!ac[t].vis;t=ac[t].fail) {
                ac[t].vis=1;
                for(int id:ac[t].end) an[id]=1;
                vv.pb(t);
            }
        }
        for(int x:vv) ac[x].vis=0;
        return an;
    }
};
/////////////////////////////