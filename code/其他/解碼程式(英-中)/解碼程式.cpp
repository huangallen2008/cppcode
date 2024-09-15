#include<bits/stdc++.h>
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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
bool is(int x) {
    if(x==0||x==3||x==4||x==6||x==7) return 1;
    return 0;
}
signed main()
{
    IOS();
    vector<string> a={" ","£t","£x","£¾","£¿","£¤","£½","£»","£«","£¯","£³","£·","£u","£y","£|","£¡","£¥","£¨","£¸","£¬","£°","£´","£v","£z","£}","£¢","£¦","£©","£¹","£­","£±","£µ","£w","£{","£~","££","£§","£ª","£º","£®","£²","£¶"};
    string b=" 1234567890-qwertyuiopasdfghjkl;zxcvbnm,./";
    while(1) {
        string s;
        getline(cin,s);
        vector<int> v,g(1000,-1);
        REP(i,b.size()) g[b[i]]=i;
        REP(i,s.size()) v.pb(g[tolower(s[i])]);
        v.pb(0);
        REP(i,s.size()) {
            if(v[i]==39&&!is(v[i+1])) cout<<", ";
            else if(v[i]==-1) cout<<s[i];
            else cout<<a[v[i]];
            if(is(v[i]))cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
