#include<bits/stdc++.h>
using namespace std;
string s;
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    getline(cin,s);
    if(s[1]==' ') cout<<"Hello,"<<s.substr(5,s.size()-5);
    else cout<<"Hallo,"<<s.substr(8,s.size()-8);
    return 0;
}
