#include<bits/stdc++.h>
using namespace std;
main()
{
    int T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        int m=s.size(),an=0,a=0;
        bool b=false;
        for(int i=0;i<m;i++) {
            if(s[i]=='(') { a++; an++; }
            else if(a) a--;
            else {
                b=true;
                break;
            }
        }
        if(a>0 || b) cout<<0<<"\n";
        else cout<<an<<"\n";
    }
    return 0;
}
