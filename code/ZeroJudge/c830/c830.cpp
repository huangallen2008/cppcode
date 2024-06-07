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
    IOS();
    string a,b;
    vector<int> p,s;
    cin>>a>>b;
    int x=a.size(),y=b.size();
    REP(i,a.size()) if(a[i]=='.') x=i;
    REP(i,b.size()) if(b[i]=='.') y=i;
    RREP(i,x) p.pb(a[i]-'0');
    RREP(i,y) {
        if(p.size()<y-i) p.pb(b[i]-'0');
        else p[y-i-1]+=b[i]-'0';
    }
    for(int i=x+1;i<a.size();i++) s.pb(a[i]-'0');
    for(int i=y+1;i<b.size();i++) {
        if(s.size()<i-y) s.pb(b[i]-'0');
        else s[i-y-1]+=b[i]-'0';
    }
    int ne=0;
    RREP(i,s.size()) {
        s[i]+=ne;
        ne=0;
        if(s[i]>=7) {
            ne=1;
            s[i]-=7;
        }
    }
    REP(i,p.size()) {
        p[i]+=ne;
        ne=0;
        if(p[i]>=7) {
            ne=1;
            p[i]-=7;
        }
    }
    if(ne==1) p.pb(1);
    int t=0;
    REP(i,s.size()) t+=s[i];
    if(p.size()==0) {
        if(t==0) cout<<0<<"\n";
        else {
            cout<<"0.";
            REP(i,s.size()) cout<<s[i]; cout<<"\n";
        }
    }
    else {
        RREP(i,p.size()) cout<<p[i];
        if(t>0) {
            cout<<".";
            REP(i,s.size()) cout<<s[i];
        }
        cout<<"\n";
    }
    return 0;
}
