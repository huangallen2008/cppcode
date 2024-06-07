#include<bits/stdc++.h>
using namespace std;
#define int long long
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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=3e5+5;
const int mod=998244353;
void solve() {
    vector<int> fac(maxn+1);
    fac[0]=1;
    REP1(i,maxn) fac[i]=(fac[i-1]*i)%mod;
    int n,m;
    cin>>n>>m;
    string s
    cin>>s;
    vector<int> a(n);
    int xi=n,ni=1,lx=n,ln=n;
    RREP(i,n) {
        if(s[i]=='>') {
            lx=i;
            a[i]=xi;
            xi--;
        }
        if(s[i]=='<') {
            ln=i;
            s[i]=ni;
            ni--;
        }
    }
    set<int> bi,si;
    REP(i,n) {
        if(s[i]=='>') bi.insert(i);
        if(s[i]=='<') si.insert(i);
    }
    vector<int> pfq(n);
    pfq[0]=(s[0]=='?');
    REP1(i,n-1) pfq[i]=pfq[i-1]+(s[i]=='?');
    int an=0;
    if(pfq[0]==0) an=0;
    else {
        if(*bi.begin()==0) {

        }
    }
    REP(i,m) {
        int u;
        char c;
        cin>>u>>c;

    }
}
signed main() {
    IOS();
//    int T;
//    cin>>T;
//    while(T--) {
        solve();
//    }
    return 0;
}
