#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
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
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> sm(n+1);
    sm[n]=n;
    sm[n-1]=n-1;
    RREP(i,n-1) {
        if(s[i]>=s[sm[i+1]]) sm[i]=i;
        else sm[i]=sm[i+1];
    }
    vector<int> h;
    int t=sm[0];
    while(t<n) {
        h.pb(t);
        t=sm[t+1];
    }
    int mx=s[h[0]];
    int cntm=0;
    REP(i,h.size()) if(s[h[i]]==mx) cntm++;
//    oparr(sm)
//    oparr(h)
    int an=h.size()-1;
    REP(i,h.size()/2) swap(s[h[i]],s[h[h.size()-i-1]]);
    bool ok=1;
    REP(i,n-1) if(s[i]>s[i+1]) ok=0;
    if(ok) cout<<an-cntm+1<<'\n';
    else cout<<"-1\n";
//    entr entr
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
