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
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
struct range{
    int l,r,id;
};
bool so(pipii a,pipii b) {
    if(a.s.f==b.s.f) return a.s.s>b.s.s;
    return a.s.f<b.s.f;
}
struct BIT {
    vector<int> b;
    int n;
    void init(int _n) {
        n=_n;
        b=vector<int>(n+1);
    }
    void ud(int u) {
        for(;u<=n;u+=(u&-u)) b[u]++;
    }
    int qu(int u) {
        int r=0;
        for(;u>0;u-=(u&-u)) r+=b[u];
        return r;
    }
};
void solve() {
    int n;
    cin>>n;
    vector<pipii> a(n);
    REP(i,n) {
        a[i].f=i;
        cin>>a[i].s.f>>a[i].s.s;
    }
    vector<int> a1(n),a2(n);
    sort(ALL(a),so);
    vector<pii> v(n);
    REP(i,n) v[i]={a[i].s.s,a[i].f};
    vector<int> t(n);
    REP(i,n) t[i]=v[i].f;
    sort(ALL(t));
    REP(i,n) v[i].f=lower_bound(ALL(t),v[i].f)-t.begin()+1;
    BIT bit;
    bit.init(n);
//    REP(i,n) cout<<v[i].f<<" ";cout<<"\n\n";
    REP(i,n) {
        a2[v[i].s]=i-bit.qu(v[i].f-1);
        bit.ud(v[i].f);
    }
    bit.init(n);
    RREP(i,n) {
        a1[v[i].s]=bit.qu(v[i].f);
        bit.ud(v[i].f);
    }
    REP(i,n) cout<<a1[i]<<" ";cout<<"\n";
    REP(i,n) cout<<a2[i]<<" ";cout<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
