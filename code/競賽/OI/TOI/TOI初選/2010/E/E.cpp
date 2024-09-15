#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
bool so(pii a,pii b) {
    if(a.f==b.f) return a.s>b.s;
    return a.f>b.f;
}
int k,m;
vector<pii> v;
vector<int> t;
vector<int> s(4e5);
void ud(int w,int l,int r,int i) {
    if(l==r) {
        s[w]++;
        return;
    }
    int m=(l+r)/2;
    if(i<=m) ud(w*2,l,m,i);
    else ud(w*2+1,m+1,r,i);
    s[w]=s[w*2]+s[w*2+1];
}
int q(int w,int l,int r,int i) {
    if(l>i) return 0;
    if(r<=i) return s[w];
    int m=(l+r)/2;
    return q(w*2,l,m,i)+q(w*2+1,m+1,r,i);
}
signed main()
{
    IOS();
    int an=0;
    cin>>k>>m;
    v=vector<pii>(k);
    t=vector<int>(k);
    REP(i,k) {
        cin>>v[i].f;
    }
    REP(i,k) {
        cin>>v[i].s;
        t[i]=v[i].s;
    }
    sort(ALL(t));
    REP(i,k) v[i].s=lower_bound(ALL(t),v[i].s)-t.begin();
    sort(ALL(v),so);
    REP(i,k) {
//        cout<<v[i].f<<" "<<v[i].s<<"  ";
        an+=q(1,0,k,v[i].s-1);
//        cout<<an<<endl;
        ud(1,0,k,v[i].s);
    }
    cout<<an<<endl;
    return 0;
}
