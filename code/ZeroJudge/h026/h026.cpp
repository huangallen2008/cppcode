#include<bits/stdc++.h>
using namespace std;
int ab(int a,int b) {
    if((a==0 && b==2) || (a==2 && b==5) || (a==5 && b==0)) return 0;
    else if(a==b) return 1;
    return 2;
}
int w(int a) {
    if(a==0) return 5;
    if(a==2) return 0;
    if(a==5) return 2;
}
main()
{
    int b,n,s[15]={};
    bool ww=true;
    cin>>b>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    cout<<b<<" ";
    int tt=ab(b,s[1]);
    if(tt==0)      cout<<": Won at round 1";
    else if(tt==2) cout<<": Lost at round 1";
    else {
        for(int i=2;i<=n;i++) {
            if(i>=3 && s[i-1]==s[i-2]) b=w(s[i-1]);
            else                       b=s[i-1];
            cout<<b<<" ";
            tt=ab(b,s[i]);
            if(tt==0) {      cout<<": Won at round "<<i;  ww=false; break; }
            else if(tt==2) { cout<<": Lost at round "<<i; ww=false; break; }
        }
        if(ww) cout<<": Drew at round "<<n;
    }
    return 0;
}
