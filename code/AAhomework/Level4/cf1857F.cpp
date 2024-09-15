#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
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
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
bool is_psn(int n) {
    int s=sqrt(n);
    return s*s==n;
}
void solve() {
    int n;
    cin>>n;
    map<int,int> m;
    REP(i,n) {
        int x;
        cin>>x;
        m[x]++;
    }
    int q;
    cin>>q;
    REP(i,q) {
        int a,b;
        cin>>a>>b;
        if(is_psn(a*a-4*b)) {
            int sq=sqrt(a*a-4*b);
            if(!((a+sq)&1)) {
                int x1=(a+sq)>>1,x2=(a-sq)>>1;
                if(x1!=x2) cout<<m[x1]*m[x2]<<' ';
                else cout<<(m[x1]*(m[x1]-1)/2)<<' ';
            }
            else cout<<"0 ";
        }
        else cout<<"0 ";
    }
    cout<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
