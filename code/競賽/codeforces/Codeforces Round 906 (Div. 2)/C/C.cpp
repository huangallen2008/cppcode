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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> an;
    REP(rd,300) {
        if(s.size()==0) break;
        if(s[0]!=s[s.size()-1]) {
            s=s.substr(1,s.size()-2);
            continue;
        }
        else if(s[0]=='0') {
            an.pb(rd+s.size());
            s=s.substr(1,s.size()-1)+'0';
            continue;
        }
        else if(s[0]=='1') {
            an.pb(rd);
            s='1'+s.substr(0,s.size()-1);
            continue;
        }
    }
    if(s.size()>0) cout<<"-1\n";
    else {
        cout<<an.size()<<"\n";
        REP(i,an.size()) cout<<an[i]<<" ";
        cout<<"\n";
    }
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
