#include<bits/stdc++.h>
using namespace std;
main()
{
    int T;
    cin>>T;
    while(T--) {
        int n,a;
        cin>>n;
        int t=0,m=-10005;
        for(int i=0;i<n;i++) {
            cin>>a;
            t+=a;
            m=max(m,t);
            if(t<0) t=0;
        }
        cout<<m<<"\n";
    }
    return 0;
}
