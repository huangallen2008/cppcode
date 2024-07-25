#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
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
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> x(n);
    REP(i,n) cin>>x[i];
    int d;
    cin>>d;
    vector<vector<int>> f(n,vector<int>(17));
    vector<vector<int>> fb(n,vector<int>(17));
    REP(i,n) f[i][0]=prev(upper_bound(ALL(x),x[i]+d))-x.begin();
    REP(i,n) fb[i][0]=lower_bound(ALL(x),x[i]-d)-x.begin();
    REP1(j,16) {
        REP(i,n) {
            f[i][j]=f[f[i][j-1]][j-1];
        }
    }
    REP1(j,16) {
        REP(i,n) {
            fb[i][j]=fb[fb[i][j-1]][j-1];
        }
    }
    int q;
    cin>>q;
    REP(i,q) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        int an=0;
        if(a>b) {
            RREP(j,17) {
                if(fb[a][j]>b) {
                    an+=(1<<j);
                    a=fb[a][j];
                }
            }
            an++;
        }
        else {
            RREP(j,17) {
                if(f[a][j]<b) {
                    an+=(1l<<j);
                    a=f[a][j];
                }
            }
            an++;
        }
        cout<<an<<'\n';
    }
    return 0;
}
