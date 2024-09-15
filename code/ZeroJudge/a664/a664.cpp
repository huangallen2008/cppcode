#include<bits/stdc++.h>
using namespace std;
long long ccl(string s) {
    long long an=0,l=0;
    char c='+';
    for(int i=0;i<s.size();i++) {
        if(isdigit(s[i])) {
            long long t=0;
            while(isdigit(s[i]))
                t=t*10-'0'+s[i++];
            i--;
            if(c=='+') {
                an+=l;
                l=t;
            }
            else if(c=='-') {
                an+=l;
                l=-t;
            }
            else if(c=='*') {
                l*=t;
            }
            else {
                l/=t;
            }
        }
        if(s[i]=='(') {
            int r=1,tt=i+1;//tt,i-tt
            while(r>0) {
                i++;
                if(s[i]=='(') r++;
                if(s[i]==')') r--;
            }
            long long t=ccl(s.substr(tt,i-tt));
            if(c=='+') {
                an+=l;
                l=t;
            }
            else if(c=='-') {
                an+=l;
                l=-t;
            }
            else if(c=='*') {
                l*=t;
            }
            else {
                l/=t;
            }
        }
        else c=s[i];
    }
    return an+l;
}
main()
{
    int T;
    cin>>T;
    while(T--) {
        string s;
        cin>>s;
        cout<<ccl(s)<<"\n";
    }
    return 0;
}
