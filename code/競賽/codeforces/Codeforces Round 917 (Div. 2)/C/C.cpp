#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=2e3+5;
const int maxk=1e5+5;
const int mod=1e9+7;
int a[maxn],v[maxk];
void solve() {
    int n,k,d;
    cin>>n>>k>>d;
    REP(i,n) cin>>a[i];
    REP(i,k) cin>>v[i];
    int cnt_ei=0;
    REP(i,n) cnt_ei+=(a[i]==i+1);
    int an=((d-1)>>1)+cnt_ei;
    REP(i,min(n*2,d-1)) {
        int t=i%k;
        REP(j,v[t]) {
            if(a[j]==j+1) cnt_ei--;
            a[j]++;
            if(a[j]==j+1) cnt_ei++;
        }
        an=max(an,cnt_ei+((d-2-i)>>1));
    }
    cout<<an<<'\n';
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
