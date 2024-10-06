template<typename K,typename V>
struct Map : public map<K, V> {
// private:
public:
    function<K(V)> func;  // 儲存傳入的函數

    Map(function<K(V)> f) : func(f) {}
    V& operator[](K key) {
        if (this->find(key) == this->end()) {
            this->insert({key,func(key)});
        }
        return map<K,V>::operator[](key);
    }
};

struct DSU {
    Map<int,int> p,sz;
    vector<pii> stk;
    DSU():
        p([&](int x) {
            return x;
        }),
        sz([&](int x) {
            return 1;
        }){}
    int find(int u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(int a,int b) {
        // op(a)ope(b)
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
    }
    int find2(int u) {
        return p[u]==u?u:find2(p[u]);
    }
    void merge2(int a,int b) {
        // op(2)op(a)ope(b)
        int x=find2(a),y=find2(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        stk.pb({x,y});
    }
    void cl() {
        for(auto [x,y]:stk) {
            p[x]=x;
            sz[y]-=sz[x];
        }
        stk.clear();
    }
    bool same(int a,int b) { 
        // op("q")op(a)ope(b)
        return find2(a)==find2(b); 
    }
};

template<typename S>//S:operator==
struct DSU {
    Map<S,S> p;
    Map<S,int>sz;
    vector<pair<S,S>> stk;
    DSU():
        p([&](S x) {
            return x;
        }),
        sz([&](S x) {
            return 1;
        }){}
    S find(S u) {
        return p[u]==u?u:p[u]=find(p[u]);
    }
    void merge(S a,S b) {
        S x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
    }
    S find2(S u) {
        return p[u]==u?u:find2(p[u]);
    }
    void merge2(S a,S b) {
        S x=find2(a),y=find2(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        p[x]=y;
        sz[y]+=sz[x];
        stk.pb({x,y});
    }
    void cl() {
        for(auto [x,y]:stk) {
            p[x]=x;
            sz[y]-=sz[x];
        }
        stk.clear();
    }
    bool same(S a,S b) { 
        return find2(a)==find2(b); 
    }
}dsu;