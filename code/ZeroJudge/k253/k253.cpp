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
signed main()
{
    IOS();
    int t,s,p;
    cin>>t>>s>>p;
    int a=0;
    if(s>=t/5+1) {
        a+=(int)(p*0.5)*(t/5+1);
        s-=t/5+1;
        if(s>=t/5) {
            a+=(int)(p*0.6)*(t/5);
            s-=t/5;
            if(s>=t/5) {
                a+=(int)(p*0.8)*(t/5);
                s-=t/5;
                if(s>=t/5) a+=(int)(p*0.9)*(t/5);
                else a+=(int)(p*0.9)*s;
            }
            else a+=(int)(p*0.8)*s;
        }
        else a+=(int)(p*0.6)*s;
    }
    else a+=(int)(p*0.5)*s;
    cout<<a<<endl;
    return 0;
}
