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
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) ((x%(mod)+(mod))%(mod))
#ifdef local
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
signed main() {
    IOS();
    multiset<int> s;
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    REP(i,n) s.insert(a[i]);
    REP(i,q) {
        int opt,x;
        cin>>opt>>x;
        if(opt==1) s.insert(x);
        if(opt==2) {
            s.erase(s.find(x));
        }
        if(opt==3) {
                int t=*prev(s.end(),x);
            cout<<t<<'\n';
        }
    }
    return 0;
}
