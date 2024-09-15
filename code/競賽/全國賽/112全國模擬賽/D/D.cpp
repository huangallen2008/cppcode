#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
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
#define md(x) (x%mod+mod)%mod
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=2e3+5;
const int mod=1e9+7;
int a[maxn][maxn];
signed main() {
    IOS();
    int n,m,k;
    cin>>n>>m>>k;
    a[0][0]=0;
    REP1(i,n) a[i][0]=0;
    REP1(i,m) a[0][i]=0;
    REP1(i,n) {
        REP1(j,m) {
            char c;
            cin>>c;
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+c-'0';
        }
    }
    int mx=0;
    vector<int> an(n*m+1);
    REP1(i,n) {
        REP1(j,m) {
            REP(ni,i) {
                RREP(nj,j) {
                    if(a[i][j]-a[ni][j]-a[i][nj]+a[ni][nj]<=k) {
                        int A=(i-ni)*(j-nj);
                        an[A]++;
                        mx=max(mx,A);
                    }
                    else break;
                }
            }
        }
    }
    cout<<mx<<'\n';
    REP1(i,n*m) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}
