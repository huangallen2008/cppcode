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
    int n0,n2;
    cin>>n0>>n2;
    int n=n0+n2;
    if((n2%2==1&&n2<11)) cout<<"-1\n";
    else {
        int c1,c2;
        if(n2%2==0) {
            c1=n2/2;
            c2=n2/2;
        }
        else {
            c1=(n2+11)/2;
            c2=(n2-11)/2;
            if((n%2==1&&c1>=(n+1)/2)||(n%2==0&&c1>n/2)) {
                cout<<"-1\n";
            }
            else if(n%2==0&&c1==n/2) {
                REP(i,n) {
                    if(i%2==0) cout<<2;
                    else if((i+1)/2<c2) cout<<2;
                    else if((i+1)/2==c2) cout<<0;
                    else if((i+1)/2==c2+1) cout<<2;
                    else cout<<0;
                }
                cout<<"\n";
                REP(i,n) {
                    if(i%2==1) cout<<2;
                    else if(i/2<n0-1) cout<<0;
                    else if(i/2==n0-1) cout<<2;
                    else if(i/2==n0) cout<<0;
                    else cout<<2;
                }
                cout<<"\n";
            }
            else {
                REP(i,n) {
                    if(i%2==1&&(i-1)/2<c2) cout<<2;

                }
            }
        }

    }
    return 0;
}
