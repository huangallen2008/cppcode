#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP1(i,n) for(int i=1;i<=n;i++)
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
bool isp(int n) {
    if(n<=1) return 0;
    for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
    return 1;
}
signed main() {
    IOS();
    REP1(i,1000) if(isp(i)) cout<<i<<' ';
    cout<<'\n';
    return 0;
}
