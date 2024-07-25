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
    int cost=0;
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
        if(l.size()==0) {
            l.insert(v);
            return;
        }
        cost+=abs(v-*l.rbegin());
        if((l.size()+h.size())&1) {
            if(v>=*l.rbegin()) {
                h.insert(v);
//                cost+=abs(v-*l.rbegin());
            }
            else {
//                cost+=abs(v-*l.rbegin());
                l.insert(v);
                lth();
//                cost+=(l.size()-h.size())*r;
            }
        }
        else {
            if(v<=*l.rbegin()) {
                l.insert(v);
            }
            else {
//                cost+=abs(v-*l.rbegin());
                int me=*l.rbegin();
                h.insert(v);
                htl();
                cost+=me-*l.rbegin();
            }
        }
    }
    void pop(int v) {
        cost-=abs(v-*l.rbegin());
        if((l.size()+h.size())&1) {
            if(v<=*l.rbegin()) {
                l.erase(l.find(v));
            }
            else {
                lth();
                h.erase(h.find(v));
            }
        }
        else {
            if(v>*l.rbegin()) {
                h.erase(h.find(v));
            }
            else {
                int me=*l.rbegin();
                htl();
                l.erase(l.find(v));
                cost-=*l.rbegin()-me;
            }
        }
    }
    int getcost() { return cost; }
};
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),p(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) p[i]=p[i-1]+a[i];
    Med med;
    REP1(i,k) {
        med.add(a[i]);
    }
    cout<<med.getcost()<<" ";
    for(int i=k+1;i<=n;i++) {
        med.add(a[i]);
        med.pop(a[i-k]);
        cout<<med.getcost()<<" ";
    }
    cout<<"\n";
}
signed main() {
    IOS();
    solve();
    return 0;
}
