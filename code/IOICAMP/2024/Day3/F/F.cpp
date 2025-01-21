#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
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
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    char f=s[0];
    int cnt=1;
    bool t=0;
    int fi=0;
    REP1(i,n-1) {
        if(s[i]==s[i-1]) {
            cnt++;
            if(s[i]==f&&fi!=i-1) cnt++;
            f=s[i];
            fi=i;
            t=1;
            s[i-1]='?';
        }
        else t=0;
    }
    if(s[n-1]==f&&n-1!=fi) cnt++;
    cout<<cnt<<'\n';
}
signed main() {
    IOS();
    int n;
    cin>>n;
    REP(i,n) {
        solve();
    }
    return 0;
}
