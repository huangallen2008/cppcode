#include <bits/stdc++.h>
using namespace std;
int m,n;
string e[101],a;
void d(int k) {
    int t=n/2,cz=0,l=100,r=101;
    char c[201];
    string an="";
    for(int i=n-1;i>=0;i--) {
        if(e[k][i]=='1') c[r++]=a[i];
        else c[l--]=a[i];
    }
    for(int i=l+1;i<r;i++) an+=c[i];
    a=an;
    for(int i=0;i<n;i++) if(e[k][i]=='1') cz++;
    if(cz%2) {
        if(n%2) a=a.substr(n-t,t)+a[t]+a.substr(0,t);
        else a=a.substr(n-t,t)+a.substr(0,t);
    }
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>m>>n;
    for(int i=0;i<m;i++) cin>>e[i];
    cin>>a;
    for(int i=m-1;i>=0;i--) d(i);
    cout<<a;
    return 0;
}
