#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP1(i,n) for(int i=1;i<=n;i++)
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
signed main() {
    IOS();
    vector<bool> isp(1001,1);
    isp[0]=0,isp[1]=0;
    for(int i=2;i*i<=1000;i++)
        if(isp[i])
            for(int j=i*i;j<=1000;j+=i)
                isp[j]=0;
    REP1(i,1000) if(isp[i]) cout<<i<<' ';
    cout<<'\n';
    return 0;
}
