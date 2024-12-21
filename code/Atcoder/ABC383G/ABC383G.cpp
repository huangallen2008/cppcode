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
const int mod=1e9+7;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k;
Vi a;
vector<vector<Vi>> f(int l,int r) {
    if(l==r) {
        vector<vector<Vi>> res(k,vector<Vi>(k));
        if(k==1) {
            res[0][0]={0,a[l]};
        }else {
            res[0][0]={0};
            REP(i,k-1) res[i][i+1]={a[l]};
            res[k-1][0]={-inf,a[l]};
        }
        return res;
    }
    int m=l+r>>1;
    vector<vector<Vi>> lr=f(l,m),rr=f(m+1,r);
    // op(l)ope(r)
    // REP(i,k) REP(j,k)oparr(lr[i][j])
    // REP(i,k) REP(j,k)oparr(rr[i][j])
    vector<vector<Vi>> an(k,vector<Vi>(k));
    auto merge=[&](Vi a,Vi b) ->Vi{
        if(a.empty()||b.empty()) return {};
        int n=a.size(),m=b.size();
        Vi r(n+m-1);
        int it1=0,it2=0;
        r[0]=a[0]+b[0];
        REP1(i,n+m-2) {
            int v1=it1<n-1?a[it1+1]-a[it1]:-inf;
            int v2=it2<m-1?b[it2+1]-b[it2]:-inf;
            if(v1>v2) {
                it1++;
            }else it2++;
            r[i]=a[it1]+b[it2];
        }
        oparr(a)oparr(b)oparr(r)
        return r;
    };
    auto upd=[&](Vi &a,Vi b) {
        a.resize(max(a.size(),b.size()),-inf);
        REP(i,b.size()) chmax(a[i],b[i]);
    };
    REP(i,k) {
        REP(j,k) {
            REP(l,k) {
                op(i)op(j)ope(l)
                upd(an[i][l],merge(lr[i][j],rr[j][l]));
            }
        }
    }
    return an;
}
signed main() {
    IOS();
    cin>>n>>k;
    a=Vi(n);
    REP(i,n) cin>>a[i];
    vector<vector<Vi>> an=f(0,n-1);
    int nn=n/k;
    REP1(i,nn) cout<<an[0][0][i]<<' ';
    cout<<'\n';
    return 0;
}