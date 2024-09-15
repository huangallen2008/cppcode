#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";//cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
signed main() {
    IOS();
    int h,w;
    cin>>h>>w;
    vector<vector<int>> a(h,vector<int>(w)),b(h,vector<int>(w));
    REP(i,h) REP(j,w) cin>>a[i][j];
    REP(i,h) REP(j,w) cin>>b[i][j];
    vector<int> rp(h),cp(w);
    REP(i,h) rp[i]=i;
    REP(i,w) cp[i]=i;
    int an=inf;
    do {
        do {
//            oparr(rp)oparr(cp)entr
            int cost=0;
            bool ok=1;
            REP(i,h) {
                REP(j,w) {
                    if(a[rp[i]][cp[j]]!=b[i][j]) {
                        ok=0;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(!ok) continue;
            vector<int> rp0(h),cp0(w);
            REP(i,h) rp0[i]=i;
            REP(i,w) cp0[i]=i;
            REP(i,h) {
                bool fd=0;
                for(int j=h-1;j>=i;j--) {
                    if(!fd) {
                        if(rp0[j]==rp[i]) fd=1;
                    }
                    else {
                        swap(rp0[j],rp0[j+1]);
                        cost++;
                    }
                }
            }
            REP(i,w) {
                bool fd=0;
                for(int j=w-1;j>=i;j--) {
                    if(!fd) {
                        if(cp0[j]==cp[i]) fd=1;
                    }
                    else {
                        swap(cp0[j],cp0[j+1]);
                        cost++;
                    }
                }
            }
//            ope(cost)
            an=min(an,cost);
        }while(next_permutation(ALL(cp)));
    }while(next_permutation(ALL(rp)));
    if(an==inf) cout<<"-1\n";
    else cout<<an<<'\n';
    return 0;
}
