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
int cal_k(int n,int x) {
    int l=1,r=n,m;
    while(l<r) {
        m=(l+r)/2;
        int t=n*(n+1)/2-m*(m+1)/2;
        if(t>=x) l=m+1;
        else r=m;
    }
    return l;
}
void solve() {
    string s;
    int x;
    cin>>s>>x;
    int n=s.size();
    int k=cal_k(n,x);
    int l=x-(n*(n+1)/2-(k+1)*k/2);
    int c=0;
    bool ok=0;
    vector<bool> out(n);
    REP1(i,n-1) {
        int id=i-1;
        while(id>=0&&s[i]<s[id]) {
            if(out[id]) {
                id--;
                continue;
            }
            c++;
            out[id]=1;
            if(c==n-k) break;
            id--;
        }
        if(c==n-k) {
            int cnt=0;
            REP(j,n) {
                if(!out[j]) cnt++;
                if(cnt==l) {
                    ok=1;
                    cout<<s[j];
                    break;
                }
            }
        }
        if(ok) break;
    }
    if(!ok) {
        int cnt=0;
        REP(j,n) {
            cnt+=out[j]^1;
            if(cnt==l) {
                ok=1;
                cout<<s[j];
                break;
            }
        }
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
