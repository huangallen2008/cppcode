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
#define pii pair<int,int>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=2e3+5;
const int maxk=1e5+5;
const int mod=998244353;
void solve() {
    int n,k;
    cin>>n>>k;
    if(k&1) {
        cout<<"NO\n";
        return;
    }
    if((k>>1)&1) {
        if((n>>1)&1) {
            if(k<n) {
                cout<<"NO\n";
                return;
            }
            if(k>n*(n-1)) {
                cout<<"NO\n";
                return;
            }
            cout<<"YES\n";
            int h=n/2;
            k-=n;
            k>>=2;
            REP(i,n) {
                REP(j,n) {
                    if(i==n-1) cout<<1<<' ';
                    else if(i/2<k/h) cout<<1<<' ';
                    else if(i/2==k/h&&j/2<k%h) cout<<1<<' ';
                    else cout<<0<<' ';
                }
                cout<<'\n';
            }
            return;
        }
        else {
            cout<<"NO\n";
            return;
        }
    }
    else {
        cout<<"YES\n";
        int h=n/2;
        k>>=2;
        REP(i,n) {
            REP(j,n) {
                if(i/2<k/h) cout<<1<<' ';
                else if(i/2==k/h&&j/2<k%h) cout<<1<<' ';
                else cout<<0<<' ';
            }
            cout<<'\n';
        }
        return;
    }
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
