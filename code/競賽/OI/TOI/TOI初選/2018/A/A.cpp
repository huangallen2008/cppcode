#include<bits/stdc++.h>
using namespace std;
//#define ll long long
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
const int inf=(1ll<<63)-1;
const int maxn=1e6+5;
const int mod=1e9+7;
string s;
map<string,int> m;
pii num(int i) {
    int r=0;
    bool nok=1;
    while(i<SZ(s)&&isdigit(s[i])) {
        r=r*10+(s[i]-'0');
        i++;
        nok=0;
    }
    if(nok) return {1,i};
    return {r,i};
}
pair<map<string,int>,int> f(int i) {
    map<string,int> m;
    int c=1;
    i++;
    string t="##";
    while(1) {
        if(s[i]=='(') {
            pair<map<string,int>,int> p=f(i);
            pii r=num(p.s);
            i=r.s;
            for(auto [x,y]:p.f) m[x]+=y*r.f;
        }
        if(s[i]==')') {
            m[t]+=c;
            return {m,i+1};
        }
        if(isdigit(s[i])) {
            pii p=num(i);
            c=p.f;
            i=p.s;
        }
        if(isalpha(s[i])) {
            m[t]+=c;
            c=1;
            if(islower(s[i+1])) {
                t=s.substr(i,2);
                i+=2;
            }
            else {
                t=s.substr(i,1);
                i++;
            }
        }
    }
}
signed main()
{
    IOS();
    cin>>s;
    cout<<s<<"\n";
    s="("+s+")";
    m=f(0).f;
    for(auto [a,b]:m) {
        if(a=="##") continue;
        cout<<a<<":"<<b<<"\n";
    }
    return 0;
}
