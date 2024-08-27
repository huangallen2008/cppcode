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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
map<int,int> mp;
int cnt=0,cb=0;
void spl(int x) {
    auto it=mp.lower_bound(x);
    if(it->f!=x) {
        mp[x]=prev(it)->s;
        if(mp[x]==0) cnt++;
    }
}
void paint(int color,int l,int r) {
    spl(l),spl(r);
    auto it_l=mp.find(l);
    auto it_r=mp.find(r);
    for(auto it=it_l;it!=it_r;it++) {
        if(it->s==0) cnt--,cb-=(next(it)->f-it->f);
    }
    it_l->s=color;
    mp.erase(next(it_l),it_r);
    if(!color) cnt++,cb+=next(it_l)->f-it_l->f;
    while(it_l!=mp.begin()&&prev(it_l)->s==it_l->s) {
        if(!it_l->s) cnt--;
        it_l--;
        mp.erase(next(it_l));
    }
    while(it_r!=prev(mp.end())&&next(it_r)->s==it_r->s) {
        if(!it_r->s) cnt--;
        it_r++;
        mp.erase(prev(it_r));
    }
    if(it_r->s==it_l->s) {
        if(!it_r->s) cnt--;
        it_r++;
        mp.erase(prev(it_r));
    }
}
signed main() {
    IOS();
    int n;
    cin>>n;
    mp[-inf]=1;
    REP(i,n) {
        char c;
        int l,x;
        cin>>c>>l>>x;
        if(c=='B') paint(0,l,l+x);
        else paint(1,l,l+x);
        cout<<cnt<<' '<<cb<<'\n';
        // for(auto [x,y]:mp) cout<<"{"<<x<<","<<y<<"} ";entr
    }
    return 0;
}