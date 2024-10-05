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
const int maxn=35;
const ll inf=1ll<<62;
const ll mod=(ll)1e17+3;
int n,lan=0,ran=0,an=0;
int a[maxn]={};
vector<int> l,r;
void d1(int i,int g) {
    if(i==n/2) {
        l.pb(g%mod);
        lan=max(lan,g%mod);
        return;
    }
    d1(i+1,g);
    d1(i+1,g+a[i]);
}
void d2(int i,int g) {
    if(i==n) {
        r.pb(g%mod);
        ran=max(ran,g%mod);
        return;
    }
    d2(i+1,g);
    d2(i+1,g+a[i]);
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n;
    REP(i,n) {
        cin>>a[i];
    }
    if(n==1) {
        cout<<a[0]%mod<<"\n";
        return 0;
    }
    d1(0,0);
    d2(n/2,0);
    an=max(lan,ran);
    sort(ALL(l));
    sort(ALL(r));
    REP(i,SZ(l)) {
        int t=l[i];
        if(mod-1==t) {
            an=max(an,t);
            continue;
        }
        int id=*prev(upper_bound(ALL(r),mod-t-1));
        int an1=(id+t)%mod,an2=(r[SZ(r)-1]+t)%mod,tan=max(an1,an2);
        an=max(an,tan);
    }
    cout<<an<<"\n";
    return 0;
}
