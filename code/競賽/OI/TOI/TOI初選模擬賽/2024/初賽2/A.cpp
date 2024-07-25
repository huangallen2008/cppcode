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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> a(n,vector<bool>(m));
    REP(i,n) {
        REP(j,m) {
            char c;
            cin>>c;
            a[i][j]=(c=='#');
        }
    }
    REP(i,n) {
        REP(j,m) {
            int v=0;
            bool i0=i>0,j0=j>0,in=i<n-1,jm=j<m-1;
            int cnt=0;
            if(i0) {
                if(j0) v^=a[i-1][j-1];
                v^=a[i-1][j]<<1;
                if(jm) v^=a[i-1][j+1]<<2;
            }
            if(j0) {
                v^=a[i][j-1]<<3;
                if(in) v^=a[i+1][j-1]<<2;
            }
            if(in) {
                v^=a[i+1][j]<<1;
                if(jm) v^=a[i+1][j+1];
            }
            if(jm) v^=a[i][j+1]<<3;

            if(i0) {
                if(j0) cnt+=a[i-1][j-1];
                cnt+=a[i-1][j];
                if(jm) cnt+=a[i-1][j+1];
            }
            if(j0) {
                cnt+=a[i][j-1];
                if(in) cnt+=a[i+1][j-1];
            }
            if(in) {
                cnt+=a[i+1][j];
                if(jm) cnt+=a[i+1][j+1];
            }
            if(jm) cnt+=a[i][j+1];
//            op(i)op(j)op(cnt)ope(v)
            if(a[i][j]&&cnt>1&&v>0&&v%5==0){
                cout<<i+1<<' '<<j+1<<'\n';
                return 0;
            }
        }
    }
/*
    REP(i,n) {
        REP(j,m) {
            int v=0;
            bool i0=i>0,j0=j>0,in=i<n-1,jm=j<m-1;
            int cnt=0;
            if(i0) {
                if(j0) v^=a[i-1][j-1];
                v^=a[i-1][j]<<1;
                if(jm) v^=a[i-1][j+1]<<2;
            }
            if(j0) {
                v^=a[i][j-1]<<3;
                if(in) v^=a[i+1][j-1]<<2;
            }
            if(in) {
                v^=a[i+1][j]<<1;
                if(jm) v^=a[i+1][j+1];
            }
            if(jm) v^=a[i][j+1]<<3;

            if(i0) {
                if(j0) cnt+=a[i-1][j-1];
                cnt+=a[i-1][j];
                if(jm) cnt+=a[i-1][j+1];
            }
            if(j0) {
                cnt+=a[i][j-1];
                if(in) cnt+=a[i+1][j-1];
            }
            if(in) {
                cnt+=a[i+1][j];
                if(jm) cnt+=a[i+1][j+1];
            }
            if(jm) cnt+=a[i][j+1];
            if(a[i][j]&&cnt==1){
                cout<<i+1<<' '<<j+1<<'\n';
                return 0;
            }
        }
    }

    REP(i,n) {
        REP(j,m) {
            if(a[i][j]){
                cout<<i+1<<' '<<j+1<<'\n';
                return 0;
            }
        }
    }
    */
    return 0;
}
