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
const int mod=1e9+7;
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<bool>> b(m,vector<bool>(n));
    vector<bool> a(m);
    REP(i,m) {
        REP(j,n) {
            char c;
            cin>>c;
            b[i][j]=(c=='1');
        }
        int x;
        cin>>x;
        a[i]=x;
    }
    int NM=n*m;
    REP(rd,NM) {
        bool used=0;
        REP(i,n) {
            REP(k,2) {
                bool fa=0,isf=0,ok=1;
                REP(j,m) {
                    if(b[j][i]==k) {
                        if(!isf) {
                            fa=a[j];
                            isf=1;
                        }
                        else if(fa!=a[j]) {
                            ok=0;
                            break;
                        }
                    }
                }
                if(ok) {
                    RREP(j,m) {
                        if(b[j][i]==k) {
                            b.erase(b.begin()+j);
                            a.erase(a.begin()+j);
                        }
                    }
                    m=b.size();
                    used=1;
                }
            }
        }
        if(!used) break;
    }
    if(a.size()) cout<<"LIE\n";
    else cout<<"OK\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
