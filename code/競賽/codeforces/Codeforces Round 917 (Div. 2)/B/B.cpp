#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
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
const int maxn=1e5+5;
const int mod=1e9+7;
void solve() {
    string s;
    cin>>s;
    vector<bool> c(26);
    int cnt=0;
    int an=0;
    REP(i,s.size()) {
        if(!c[s[i]-'a']) {
            cnt++;
            c[s[i]-'a']=1;
        }
        an+=cnt;
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
