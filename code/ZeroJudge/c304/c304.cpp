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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    string s;
    while(cin>>s) {
        int n=s.size();
        vector<int> v(n);
        string an="";
        REP(i,n) v[i]=s[i]-'0'+s[n-i-1]-'0';
        RREP(i,n) {
            an=(char)('0'+v[i]%10)+an;
            if(v[i]>10) {
                v[i]-=10;
                if(i>0) v[i-1]++;
                else an='1'+an;
            }
        }
        cout<<an<<endl;
    }
    return 0;
}
