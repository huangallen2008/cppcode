#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define oparr(x) cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=6e6+5;
const int maxb=30;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int cnt[maxn];
int ch[maxn][2];
int node_id=2;
vector<pii> stk;
void init_trie() {

}
void ins(int x,int v=1,bool is_add=1) {
    int r=1;
    RREP(i,maxb) {
        int c=x>>i&1;
        if(!ch[r][c]) ch[r][c]=node_id++;
        r=ch[r][c];
        cnt[r]+=v;
    }
    if(is_add)stk.pb({x,v});
}
int mn_xor(int x) {
    int r=1,an=0;
    RREP(i,maxb) {
        int c=~x>>i&1;
        if(cnt[ch[r][c]]==0) r=ch[r][c^1],an^=1<<i;
        else r=ch[r][c];
    }
    return an;
}
void trie_clear() {
    while(stk.size()) {
        ins(stk.back().f,-stk.back().s,0);
        stk.pop_back();
    }
}
int merge(Vi a,int b) {
    oparr(a)ope(b)
    if(a.size()<=1||b<0) return 0;
    Vi l,r;
    REP(i,a.size()) {
        if(a[i]>>b&1) r.pb(a[i]);
        else l.pb(a[i]);
    }
    int an=merge(l,b-1)+merge(r,b-1);
    int ran=inf;
    for(int x:r) ins(x);
    for(int x:l) chmin(ran,mn_xor(x));
    if(ran==inf) ran=0;
    trie_clear();
    an+=ran;
    return an;
}
signed main() {
    IOS();
    init_trie();
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    int an=merge(a,maxb-1);
    cout<<an<<'\n';
    return 0;
}