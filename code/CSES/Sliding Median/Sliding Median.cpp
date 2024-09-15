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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
struct Med {
    multiset<int> l,h;
    int getmed() {
        if(l.size()==0) return -1;
        return *l.rbegin();
    }
    void htl() {

        l.insert(*h.begin());
        h.erase(h.find(*h.begin()));
    }
    void lth() {
        h.insert(*l.rbegin());
        l.erase(l.find(*l.rbegin()));
    }
    void add(int v) {
        if((l.size()+h.size())&1) {
            if(v>=*l.rbegin()) h.insert(v);
            else {
                l.insert(v);
                lth();
            }
        }
        else {
            if(v<=*l.begin()) l.insert(v);
            else {
                h.insert(v);
                htl();
            }
        }
    }
    void pop(int v) {
        if((l.size()+h.size())&1) {
            if(v<=*l.rbegin()) l.erase(l.find(v));
            else {
                lth();
                h.erase(h.find(v));
            }
        }
        else {
            if(v>*l.rbegin()) h.erase(h.find(v));
            else {
                htl();
                l.erase(l.find(v));
            }
        }
    }
};
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    Med med;
    REP(i,k) {
        med.add(a[i]);
    }
    cout<<med.getmed()<<" ";
    for(int i=k;i<n;i++) {
        med.add(a[i]);
        med.pop(a[i-k]);
        cout<<med.getmed()<<" ";
    }
    cout<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
