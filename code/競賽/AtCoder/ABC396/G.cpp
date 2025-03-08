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
const int mod=998244353;
const int maxn=5;
const int maxb=30;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int h,w;
    cin>>h>>w;
    vector<vector<Vi>> cnt(w,vector<Vi>(2,Vi(w+1)));
    Vi an(w+1);
    vector<Vi> a(h,Vi(w));
    Vi cc(h);
    REP(i,h) {
        REP(j,w) {
            char c;
            cin>>c;
            a[i][j]=c-'0';
            cc[i]+=a[i][j];
        }
    }
    REP(i,h) an[cc[i]]++;
    REP(i,h) {
        REP(j,w) {
            cnt[j][a[i][j]][cc[i]]++;
        }
    }
    auto flp=[&](int x) {
        REP(i,h-1) {
            an[i]-=cnt[x][0][i];
            an[i+1]+=cnt[x][0][i];
        }
        cnt[x][0].insert(cnt[x][0].begin(),0);
        cnt[x][0].pop_back();
        REP1(i,h-1) {
            an[i]-=cnt[x][1][i];
            an[i-1]+=cnt[x][1][i];
        }
        cnt[x][1].erase(cnt[x][1].begin());
        cnt[x][1].pb(0);
    };
    auto getan=[&]() {
        int ans=0;
        REP(i,w) ans+=min(i,w-i)*an[i];
        return ans;
    };
    int ans=0;
    REP1(i,1<<w) {
        chmin(ans,getan());
        flp(__lg(i&-i));
    }
    cout<<ans<<'\n';
    return 0;
}