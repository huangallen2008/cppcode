#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int mod=1e9+7;
const int maxn=1e5+5;
int n;
vector<int> a;
struct DSU {
    vector<int> s;
    DSU() {
        s=vector<int>(4e5);
    }
    void d(int w,int l,int r,int i) {
        if(l==r) {
            s[w]++;
            return;
        }
        int m=(l+r)/2;
        if(i<=m) d(w*2,l,m,i);
        else d(w*2+1,m+1,r,i);
        s[w]=s[w*2]+s[w*2+1];
    }
    int q(int w,int l,int r,int ll,int rr) {
        if(ll<=l&&r<=rr) return s[w];
        if(l>rr||r<ll) return 0;
        int m=(l+r)/2;
        return q(w*2,l,m,ll,rr)+q(w*2+1,m+1,r,ll,rr);
    }
};

signed main() {
    IOS();
    cin>>n;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    DSU dl,dr;
    vector<int> v(n);
    REP(i,n) {
        v[i]=dl.q(1,0,1e5,a[i]+1,1e5);
        dl.d(1,0,1e5,a[i]);
    }
    RREP(i,n) {
        v[i]=min(v[i],dr.q(1,0,1e5,a[i]+1,1e5));
        dr.d(1,0,1e5,a[i]);
    }
    int an=0;
    REP(i,n) an+=v[i];
    cout<<an<<"\n";
    return 0;
}
