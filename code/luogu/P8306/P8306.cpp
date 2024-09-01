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
const int maxn=3e6+5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int cnt[maxn];
int ch[maxn][62];
int node_id=0;
void TRIE_init() {
    node_id=0;
    memset(cnt,0,sizeof(cnt));
    memset(ch,-1,sizeof(ch));
}
struct TRIE {
    int toi(char c) {
        if('0'<=c&&c<='9') return c-'0';
        if('a'<=c&&c<='z') return c-'a'+10;
        return c-'A'+36;
    }
    int root;
    void init() {
        root=node_id++;
    }
    void ins(string s) {
        int w=root;
        cnt[root]++;
        for(char &c:s) {
            int t=toi(c);
            if(ch[w][t]==-1) ch[w][t]=node_id++;
            w=ch[w][t];
            cnt[w]++;
            op(w)ope(cnt[w])
        }
    }
    int qu(string s) {
        int w=root;
        for(char &c:s) {
            int t=toi(c);
            if(ch[w][t]==-1) return 0;
            w=ch[w][t];
        }
        return cnt[w];
    }
}trie;
void solve() {
    trie.init();
    int n,m;
    cin>>n>>m;
    REP(i,n) {
        string s;
        cin>>s;
        trie.ins(s);
    }
    REP(i,m) {
        string s;
        cin>>s;
        cout<<trie.qu(s)<<'\n';
    }
} 
signed main() {
    IOS();
    TRIE_init();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}