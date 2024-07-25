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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int n,x,num=1,mon=0;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mon+=(((int)((a[i])/100))*num);
        while(mon>=a[i])
        {
            num++;
            mon-=a[i];
//            mon+=(((int)(a[i]/100)));
        }
//        cout<<i<<" "<<num<<" "<<mon<<endl;
    }
//    cout<<num<<" "<<mon<<" "<<a[n-1]<<endl;
    if((num*a[n-1]+mon)>x)
        cout<<"stonks\n";
    else
        cout<<"not stonks\n";
    return 0;
}
