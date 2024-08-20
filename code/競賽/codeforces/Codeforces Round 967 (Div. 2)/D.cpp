#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=3e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii mn[maxb][maxn];
pii mx[maxb][maxn];
vector<int> a;
int n;
pii min(pii a,pii b) {
    if(a.f<b.f) return a;
    if(a.f>b.f) return b;
    else return {a.f,min(a.s,b.s)};
}
pii max(pii a,pii b) {
    if(a.f>b.f) return a;
    if(a.f<b.f) return b;
    else return {a.f,min(a.s,b.s)};
}
void init() {
    REP(i,n) mn[0][i]=mx[0][i]={a[i],i};
    REP1(i,maxb-1) {
        REP(j,n) {
            mn[i][j]=min(mn[i-1][j],mn[min(n-1,i+(1<<j-1))][j]);
            mx[i][j]=max(mx[i-1][j],mx[min(n-1,i+(1<<j-1))][j]);
        }
    }
}
pii rmn(int l,int r) { 
    int lg=__lg(r-l+1);
    return min(mn[lg][l],mn[lg][r-(1<<lg)+1]);
}
pii rmx(int l,int r) { 
    int lg=__lg(r-l+1);
    return max(mx[lg][l],mx[lg][r-(1<<lg)+1]);
}
void solve() {
    cin>>n;
    a=vector<int>(n);
    REP1(i,n) cin>>a[i],a[i]--;
    init();
    vector<int> las(n,-1);
    REP1(i,n) las[a[i]]=i;
    vector<bool> isl(n);
    int cntd=0;
    REP1(i,n) {
        if(las[i]!=-1) {
            isl[i]=1;
            cntd++;
        }
    }
    int it=0;
    REP(i,n) if(isl[i]) {
        it=i;
        break;
    }
    ope("ok")
    int l=0;
    vector<int> an;
    vector<bool> used(n);
    REP1(rd,cntd) {
        if(rd&1) { 
            pii ret=rmx(l,it);
            op(l)op(it)op(ret.f)ope(ret.s)
            l=ret.s+1;
            if(used[ret.f]) {
                rd--;
                continue;
            }
            an.pb(ret.f);
            used[ret.f]=1;
            if(ret.s==it) {
                it++;
                while(it<n&&!isl[it]) it++;
            }
        }
        else {
            pii ret=rmn(l,it);
            l=ret.s+1;
            if(used[ret.f]) {
                rd--;
                continue;
            }
            an.pb(ret.f);
            used[ret.f]=1;
            if(ret.s==it) {
                it++;
                while(it<n&&!isl[it]) it++;
            }
        }
    }
    cout<<an.size()<<'\n';
    for(int &x:an) cout<<x<<' ';
    cout<<'\n'; 
}
signed main() {
    IOS();
    int T=1;
    cin>>T;while(T--) 
    solve();
    return 0;
}