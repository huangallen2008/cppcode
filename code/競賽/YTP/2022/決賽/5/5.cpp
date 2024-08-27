#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define md(x,m) ((x)%(m)+(m))%(m)
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll inf = 1ll<<62;
const int iinf=2147483647;
const ll mod = 1e9+7;
const ll maxn=1e5+5;
const double PI=acos(-1);
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
}
string s;
bool g(int c) {
    for(int i=0;i<=6-c;i++) {
        bool b=1;
        int t=s[i+1]-s[i];
        if(abs(t)>1) continue;
        for(int j=i;j<i+c-1;j++) {
            if(s[j+1]-s[j]!=t) {
                b=0;
                break;
            }
        }
        if(b) return 1;
    }
    return 0;
}
bool b5(string s) {
    if(s[0]==s[3] && s[1]==s[4] && s[2]==s[5]) return 1;
    if(s[0]==s[1] && s[1]==s[2] && s[3]==s[4] && s[4]==s[5]) return 1;
    return 0;
}
int d(string s) {
    if(g(6)) return 50;
    if(g(5)) return 20;
    if(g(4)) return 10;
    if(b5(s)) return 5;
    if(g(3)) return 2;
    else return 1;
}
bool can(string s) {
    if(s.size()!=6) return 0;
    for(int i=0;i<6;i++)
        if(s[i]-'0'<0 || s[i]-'0'>9) return 0;
    return 1;
}
int an=0;
main (){
    IOS();
    while(cin>>s) {
        if(!can(s)) break;
        else an+=d(s);
    }
    cout<<an<<"\n";
}
