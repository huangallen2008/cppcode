#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
const int maxn=1e5+5;
const int maxb=30;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
int cnt[maxn*maxb];
int ch[maxn*maxb][2];
int node_id=0;
void TRIE_init() {
    memset(cnt,0,sizeof(cnt));
    memset(ch,-1,sizeof(ch));
}
struct TRIE {
    int root,an;
    void init() {
        an=0;
        root=node_id++;
    }
    void ud(int u,int v) {
        int w=root;
        cnt[w]+=v;
        RREP(i,maxb) {
            int c=u>>i&1;
            if(ch[w][c]==-1) ch[w][c]=node_id++;
            w=ch[w][c];
            cnt[w]+=v; 
        }
    }
    int mx(int u) {
        int w=root,an=0;
        RREP(i,maxb) {
            int ui=u>>i&1;
            if(cnt[ch[w][ui^1]]==0) w=ch[w][ui];
            else w=ch[w][ui^1],an|=1<<i;
        }
        return an;
    }
    void add(int u) { ud(u,1),chmax(an,mx(u)); }
    void del(int u) { ud(u,-1); }
    int get_an() { return an; }
};
signed main() {
    IOS(); 
    TRIE_init();
    cin>>n;
    Vi a(n+1),d(n);
    REP1(i,n) cin>>a[i],a[i]^=a[i-1];
    map<int,TRIE> mp;
    mp[n+1];
    REP(i,n+1) {
        mp[i].init();
        mp[i].add(a[i]);
    }
    REP(i,n) cin>>d[i];
    int an=0;
    Vi ans(n);
    RREP(i,n) {
        auto it=mp.find(d[i]);
        if(it->f-prev(it)->f>next(it)->f-it->f) {
            for(int j=it->f;j<next(it)->f;j++) prev(it)->s.add(a[j]);
            chmax(an,prev(it)->s.get_an());
            mp.erase(it);
        }
        else {
            for(int j=prev(it)->f;j<it->f;j++) it->s.add(a[j]);
            chmax(an,it->s.get_an());
            swap(it->s,prev(it)->s);
            mp.erase(it);
        }
        ans[i]=an;
    }
    REP(i,n) cout<<ans[i]<<'\n';
    return 0;
}