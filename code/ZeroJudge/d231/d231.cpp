#include<bits/stdc++.h>
using namespace std;
main()
{
    string a,b;
    cin>>a>>b;
    pair<int,vector<char>> c[51][51];
    for(int i=1;i<=a.size();i++) {
        for(int j=1;j<=b.size();j++) {
            if(a[i-1]==b[j-1]) {
                c[i][j]=c[i-1][j-1];
                c[i][j].second.push_back(a[i-1]);
            }
            else {
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    if(c[a.size()][b.size()].second.size()==0)
        cout<<"E";
    else
        for(int i=0;i<c[a.size()][b.size()].second.size();i++)
            cout<<c[a.size()][b.size()].second[i];
    return 0;
}
