#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
#define pii pair<int,int>
#define pipii pair<int,pii>
#define ppi pair<pii,int>
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
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=1e9+7;
const int maxn=1e6+5;
const int maxv=1000;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
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
signed main() {
    IOS();
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> a(n);
    REP(i,n) cin>>a[i];
    AC ac;
    ac.init();
    ac.build(a);
    Vi an=ac.qu(s);
    REP(i,n) cout<<(an[i]?"YES":"NO")<<'\n';
    return 0;
}
