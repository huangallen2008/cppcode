#include<bits/stdc++.h>
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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
struct str {
    int cnt=0;
    int l,r;
};
signed main()
{
    IOS();
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<int> cnt(n+1,1),ni(n+1);
    str an;
    REP1(i,n) {
        for(int j=1;j*i<n;j++) {
            bool ok=1;
            for(int k=j*i;k<(j+1)*i;k++) {
                if(s[k]!=s[k-i]) {
                    ok=0;
                    break;
                }
            }
            if(!ok) break;
            cnt[i]++;
        }
        ni[i]=cnt[i]*i-1;
    }

    return 0;
}
