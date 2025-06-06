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
const int maxn=2e5+5;
const int maxv=1300;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
void solve() {
    int n;
    cin>>n;
    Vi a(n+1),b(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) cin>>b[i];
    Vi p(n+1);
    REP1(i,n) p[a[i]]=b[i];
    int ceq=0;
    Vi to(n+1);
    Vi na(n+1);
    int it=1;
    Vi vis(n+1);
    REP1(i,n) {
        if(vis[i]) continue;
        if(p[i]==i) {
            ceq++;
            na[n+1>>1]=i;
            if(ceq>1) {
                cout<<"-1\n";
                return;
            }
        }
        else {
            if(p[p[i]]==i) {
                vis[p[i]]=1;
                na[it]=i;
                to[i]=it;
                to[p[i]]=n-it+1;
                na[n-it+1]=p[i];
                it++;
                continue;
            }
            cout<<"-1\n";
            return ;
        }
    }
    // oparr(na)
    Vpii an;
    Vi id(n+1);
    REP1(i,n) id[a[i]]=i;
    REP1(i,n){
        if(na[i]!=a[i]) {
            int v1=na[i],v2=a[i];
            an.pb({i,id[v1]});
            swap(a[id[v1]],a[i]);
            swap(id[v1],id[v2]);
        }
    } 
    cout<<SZ(an)<<'\n';  
    for(auto [x,y]:an) cout<<x<<' '<<y<<'\n';
}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
