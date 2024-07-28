#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
// vector<int> v;
bool ok(int a,int b,int c) {
    return a+b>c&&a+c>b&&c+b>a;
}
struct DS {
    set<pii> s;
    set<int> s1;
    vector<int> o;
    void init(int n) {
        o=vector<int>(n+1);
    }
    void push_1(int x) {
        s1.insert(x);
    }
    void pop_1(int x) {
        if(s1.find(x)!=s1.end()) s1.erase(x);
    }
    void push(int x,int id) {
        auto it=s.lower_bound({x,id}),itl=it;
        vector<set<pii>::iterator> nxt,las;
        if(it!=s.end()) {
            nxt.pb(it);
            it=next(it);
            if(it!=s.end()) nxt.pb(it);
        }
        if(itl!=s.begin()) {
            itl=prev(itl);
            las.pb(itl);
            if(itl!=s.begin()) {
                itl=prev(itl);
                las.pb(itl);
            }
        }
        if(las.size()==2) {
            bool oo=ok((*las[0]).f,(*las[1]).f,x);
            if(oo) { 
                push_1((*las[1]).s);
                o[(*las[1]).s]=1;
            }
            las.pop_back();
        }
        if(las.size()+nxt.size()>=2) {
            bool oo=ok((*las[0]).f,(*nxt[0]).f,x);
            if(oo) { 
                push_1((*las[0]).s);
                o[(*las[0]).s]=1;
            }
            las.pop_back();
        }
        if(nxt.size()==2) {
            bool oo=ok((*nxt[0]).f,(*nxt[1]).f,x);
            if(oo) { 
                push_1(id);
                o[id]=1;
            }
        }
        s.insert({x,id});
    }
    void pop(int x,int id) {
        auto it=s.find({x,id});
        if(o[id]==1) {
            o[id]=0;
            s1.erase(id);
        }
        s.erase(it);
        auto it=s.lower_bound({x,id}),itl=it;
        vector<set<pii>::iterator> nxt,las;
        if(it!=s.end()) {
            nxt.pb(it);
            it=next(it);
            if(it!=s.end()) nxt.pb(it);
        }
        if(itl!=s.begin()) {
            itl=prev(itl);
            las.pb(itl);
            if(itl!=s.begin()) {
                itl=prev(itl);
                las.pb(itl);
            }
        }
        if(las.size()==2) {
            bool oo=ok((*las[0]).f,(*las[1]).f,x);
            if(!oo) { 
                pop_1((*las[1]).s);
                o[(*las[1]).s]=0;
            }
            las.pop_back();
        }
        if(las.size()+nxt.size()>=2) {
            bool oo=ok((*las[0]).f,(*nxt[0]).f,x);
            if(!oo) { 
                pop_1((*las[0]).s);
                o[(*las[0]).s]=0;
            }
            las.pop_back();
        }
        if(nxt.size()==2) {
            bool oo=ok((*nxt[0]).f,(*nxt[1]).f,x);
            if(!oo) { 
                pop_1(id);
                o[id]=0;
            }
        }
    }
}ds;
int sn=0;
void solve() {
    int n,q;
    cin>>n>>q;
    sn=sqrt(n);
    ds.init(n);
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    vector<int> c(n);
    REP1(i,n) c[i]+=c[i-1];
    vector<pipii> qu(q);
    REP(i,q) {
        qu[i].f=i;
        cin>>qu[i].s.f>>qu[i].s.s;
    }
    sort(ALL(qu),[&](pipii a,pipii b) { if((int)a.s.f/sn==(int)b.s.f/sn) return a.s.s<b.s.s;return a.s.f/sn<b.s.f/sn; })
    REP(i,q) {
        while (l > ql) ds.push(a[--l]);
        while (r < qr) ds.push(a[++r]);
        while (l < ql) ds.pop(a[l++]);
        while (r > qr) ds.pop(a[r--]);
    }
}
signed main() {
    IOS();
    // int T;
    // cin>>T;
    // while(T--) 
        solve();
    return 0;
}