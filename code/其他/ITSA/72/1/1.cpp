#include<bits/stdc++.h>
using namespace std;
int n;
main()
{
    while(cin>>n) {
        bool b=true;
        for(int i=2;i*i<=n;i++) if(n%i==0) b=false;
        if(b) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
