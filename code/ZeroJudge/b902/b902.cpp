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
#define b(x) ;
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int T;
    cin>>T;
    while(T--) {
        int a,b;
        cin>>a>>b;
        if(a%2==1&&b%2==1) cout<<">\\\\<\n";
        else if(a%2!=b%2) cout<<">//<\n";
        else {
            int c=0;
            while(a!=0&&b!=0) {
                c++;
                if(a<=b) b-=a;
                else a-=b;
            }
            if(c%2) cout<<">//<\n";
            else cout<<">\\\\<\n";
        }
    }
    return 0;
}
/*
6
2 2
2 3
2 0
0 2
5 8
76 32
*/
