#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
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
const int mod=998244353;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,l,k;
    cin>>n>>l>>k;
    while(n--) {
        string s;
        cin>>s;
        if(k==1) cout<<l<<'\n';
        else if(k&1) {
            if(l>k) {
                vector<int> cnt1(30),cnt2(30);
                REP(i,l) {
                    if(i&1) cnt1[s[i]-'a']++;
                    else cnt2[s[i]-'a']++;
                }
                int mx1=0,mx2=0;
                REP(i,30) mx1=max(mx1,cnt1[i]);
                REP(i,30) mx2=max(mx2,cnt2[i]);
                cout<<mx1+mx2<<'\n';
            }
            else {
                int an=0;
                REP(i,l/2) an+=(s[i]!=s[l-1-i]);
                cout<<l-an<<'\n';
            }
        }
        else {
            if(l>k) {
                vector<int> cnt(30);
                REP(i,l) cnt[s[i]-'a']++;
                int mx=0;
                REP(i,30) mx=max(mx,cnt[i]);
                cout<<mx<<'\n';
            }
            else {
                int an=0;
                REP(i,l/2) an+=(s[i]!=s[l-1-i]);
                cout<<l-an<<'\n';
            }
        }
    }
    return 0;
}
