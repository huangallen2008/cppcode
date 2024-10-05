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
#define op(x)
#define ope(x)
#define oparr(x)
#define entr
#endif
const int mod=998244353;
const int maxn=2e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int h,w;
    cin>>h>>w;
    vector<vector<bool>> m(h,vector<bool>(w)),p(h,vector<int>(w));
    REP(i,h) {
        REP(j,w) {
            char c;
            cin>>c;
            if(c=='.') m[i][j]=1;
        }
    }
//            REP(i,h) {
//            REP(j,w) cout<<m[i][j];cout<<endl;}cout<<endl;
    int cnt=0;
    REP1(x,h) {
        REP1(y,w) {
            vector<vector<bool>> t(h,vector<bool>(w));
            REP(i,h-x+1) {
                REP(j,w-y+1) {
                    bool ok=1;
                    for(int xx=i;xx<i+x;xx++) {
                        for(int yy=j;yy<j+y;yy++) {
                            if(!m[xx][yy]) {
                                ok=0;
                                break;
                            }
                        }
                        if(!ok) break;
                    }
                    if(!ok) continue;
                    op(i)ope(j)
                    for(int xx=i;xx<i+x;xx++) {
                        for(int yy=j;yy<j+y;yy++) {
                            t[xx][yy]=1;
                        }
                    }
                }
            }
//            REP(i,h) {
//            REP(j,w) cout<<t[i][j];cout<<endl;}cout<<endl;
            bool ook=1;
            REP(i,h){
                REP(j,w) {
                    if(!(t[i][j]||!m[i][j])) {
                            ook=0;
                            break;
                    }
                }
                if(!ook) break;
            }
            cnt+=ook;
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
