#include<bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3")
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
const int maxn=2e5+5;
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n,(1<<30)-1);
    vector<vector<int>> m(n,vector<int>(n));
    REP(i,n) {
        REP(j,n) {
            cin>>m[i][j];
            if(i!=j) {
                a[i]&=m[i][j];
                a[j]&=m[i][j];
            }
        }
    }
    REP(i,n) {
        REP(j,n) {
            if(i==j) continue;
            if((a[i]|a[j])!=m[i][j]) {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    REP(i,n) cout<<a[i]<<' ';
    cout<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
