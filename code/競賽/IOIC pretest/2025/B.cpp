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
const int maxb=20;
const int inf=1ll<<62;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
map<int,int> mp;
void sep(int x) {
    auto it=mp.lower_bound(x);
    if(it->f!=x) mp[x]=it->s;
}
void ins(int l,int r,int x) {
    l--;
    sep(l);sep(r);
    auto it_l=mp.find(l);
    auto it_r=mp.find(r);
    mp.erase(next(it_l),it_r);
    mp[r]=x;
}
int qur(int l,int r) {
    l--;
    sep(l);sep(r);
    auto it_l=mp.find(l);
    auto it_r=mp.find(r);
    map<int,int> cnt;
    for(auto it=next(it_l);it!=next(it_r);it++) {
        if(it->s!=0) cnt[it->s]+=it->f-prev(it)->f;
    }
    mp.erase(next(it_l),it_r);
    mp[r]=0;
    int an=0;
    for(auto &[x,y]:cnt) an+=y*y;
    for(auto &[x,y]:cnt) cout<<"{"<<x<<' '<<y<<"} ";entr
    return an;
}
void init() {
    mp[inf]=0;
}
signed main() {
    IOS(); 
    init();
    int n,q;
    cin>>n>>q;
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,x;
            cin>>l>>r>>x;
            ins(l,r,x);
        }
        else {
            int l,r;
            cin>>l>>r;
            cout<<qur(l,r)<<'\n';
        }
    }
    return 0;
}