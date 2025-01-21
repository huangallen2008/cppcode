#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=1e6+5;
int h[maxn];
void solve() {
    int n;
    cin>>n;
    cout<<h[n]*3-n*2<<'\n';
}
signed main() {
    IOS();
    REP1(i,maxn) {
        for(int j=i;j<=maxn;j+=i) {
            h[j]++;
        }
    }
    REP1(i,maxn) h[i]+=h[i-1];
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
