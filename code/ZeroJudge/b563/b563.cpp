#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    while(cin>>n) {
        map<int,map<int,int>> m;
        int an=0;
        for(int i=0;i<n;i++) {
            int x,y;
            cin>>x>>y;
            if(m[y][x]>0) { an++; m[y][x]--; }
            else m[x][y]++;
        }
        cout<<an<<"\n";
    }
    return 0;
}
