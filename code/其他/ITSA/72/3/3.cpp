#include<bits/stdc++.h>
using namespace std;
string s,a;
int n,b,c=0;
main()
{
    getline(cin,s);
    getline(cin,a);
    cin>>b;
    n=s.size();
    vector<char> v[b];
    for(int i=0;i<n;i++) v[(c++)%b].push_back(s[i]);
    c%=b;
    if(c>0) for(int i=c;i<b;i++) v[i].push_back(' ');
    for(int i=0;i<b;i++)
        for(int j=v[i].size()-1;j>=0;j--)
            cout<<v[i][j]<<(j==0?"\n":a);
    return 0;
}
