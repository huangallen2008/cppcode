#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#define Vi vector<int>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=5;
const int maxv=1e9+5;
const int inf=1ll<<62;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
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
        // op(a)ope(b)
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
        // op(2)op(a)ope(b)
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
        // op("q")op(a)ope(b)
        return find2(a)==find2(b); 
    }
};
DSU<int> dsu;
// struct DSU {
//     Map<int,int> p,sz;
//     vector<pii> stk;
//     DSU():
//         p([&](int x) {
//             return x;
//         }),
//         sz([&](int x) {
//             return 1;
//         }){}
//     int find(int u) {
//         return p[u]==u?u:p[u]=find(p[u]);
//     }
//     void merge(int a,int b) {
//         // op(a)ope(b)
//         int x=find(a),y=find(b);
//         if(x==y) return;
//         if(sz[x]>sz[y]) swap(x,y);
//         p[x]=y;
//         sz[y]+=sz[x];
//     }
//     int find2(int u) {
//         return p[u]==u?u:find2(p[u]);
//     }
//     void merge2(int a,int b) {
//         // op(2)op(a)ope(b)
//         int x=find2(a),y=find2(b);
//         if(x==y) return;
//         if(sz[x]>sz[y]) swap(x,y);
//         p[x]=y;
//         sz[y]+=sz[x];
//         stk.pb({x,y});
//     }
//     void cl() {
//         for(auto [x,y]:stk) {
//             p[x]=x;
//             sz[y]-=sz[x];
//         }
//         stk.clear();
//     }
//     bool same(int a,int b) { 
//         // op("q")op(a)ope(b)
//         return find2(a)==find2(b); 
//     }
// }dsu;
int id(int u,int v) {
    return u*maxv+v;
}
struct qur {
    int v,w,id;
};
signed main() {
    IOS(); 
    int n,m,q;
    cin>>n>>m>>q;
    Graphw g(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
        dsu.merge(id(u,w),id(v,w));
    }
    REP(i,n) {
        int k;
        cin>>k;
        if(k>0) {
            int x;
            cin>>x;
            REP(j,k-1) {
                int y;
                cin>>y;
                dsu.merge(id(i,x),id(i,y));
            }
        }
    }
    vector<vector<qur>> qu(n);
    Vi an(q);
    REP(i,q) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        if(u==v) an[i]=1;
        else qu[v].pb({u,w,i});
    }
    REP(u,n) {
        // ope(u)
        for(auto [v,w]:g[u]) {
            dsu.merge2(id(u,w),id(u,maxv-1));
        }
        for(auto [v,w,ii]:qu[u]) {
            if(dsu.same(id(v,w),id(u,maxv-1))) an[ii]=1;
            else an[ii]=0;
        }
        dsu.cl();
    }
    REP(i,q) {
        if(an[i]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}