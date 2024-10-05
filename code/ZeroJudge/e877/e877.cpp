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
    cin.tie(0);
    cin.sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        int t=0;
        priority_queue<int> pq;
        vector<pii> a(n);
        REP(i,n) cin>>a[i].s>>a[i].f;
        sort(ALL(a));
        REP(i,n) {
            int h=a[i].s,l=a[i].f;
            if(t<=l) {
                pq.push(h);
                t+=h;
            } else {
                if(pq.size()==0) continue;
                if(h>pq.top()) continue;
                if(t-pq.top()<=l) {
                    t+=h-pq.top();
                    pq.pop();
                    pq.push(h);
                }
            }
        }
        cout<<pq.size()<<"\n";
    }
    return 0;
}
