#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int M;
#define Matrix vector<vector<int>>
Matrix operator*(Matrix a,Matrix b) {
    int n=a.size(),m=b.size(),k=b[0].size();
    Matrix c(n,vector<int>(k));
    REP(i,n) REP(j,k) REP(l,m) c[i][j]=(c[i][j]+a[i][l]*b[l][j])%M;
}
Matrix one={{1,0},{0,1}};
signed main() {
    IOS();
    cin>>M;
    int n,q;
    cin>>n>>q;
    vector<vector<Matrix>> st(19,vector<Matrix>(n,one));
    REP(i,n) {
        REP(j,2) REP(k,2) cin>>st[0][i][j][k];
    }
    ope("ok")
    REP1(i,18) {
        REP(j,n) {
            if(j+(1<<i)>n) break;
            st[i][j]=st[i-1][j]*st[i-1][j+(1<<i-1)];
            op(i)ope(j)
        }
    }
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        Matrix an=one;
        l--;
        RREP(j,19) {
            if(l+(1<<j)<=r) {
                an=an*st[j][l];
                l+=1<<j;
            }
        }
        REP(j,2) {
            REP(k,2) cout<<an[j][k]<<' ';
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}