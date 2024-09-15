#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,r;
    string s;
    cin>>n>>r>>s;
    n--;
    int ds=0;
    REP(i,n) ds+=s[i]-'0';
    r%=9,ds%=9;
    vector<string> a;
    int u=(r-ds+9)%9;
    REP(i,n+1) {
        string an="";
        REP(j,n+1) {
            if(j==i) an+='0'+u;
            else an+=s[j-(j>i)];
        }
        a.pb(an);
    }
    if(u==0) {
        u=9;
        REP(i,n+1) {
            string an="";
            REP(j,n+1) {
                if(j==i) an+='0'+u;
                else an+=s[j-(j>i)];
            }
            a.pb(an);
        }
    }
    sort(ALL(a));
//    cout<<a.size()<<"\n";
    for(int i=1;i<n;i++) cout<<a[i]<<"\n";
    return 0;
}
