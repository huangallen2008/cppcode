#include<bits/stdc++.h>
using namespace std;
vector<int> v[6];
bool h[6][6];
void d(bool a[][6],int u,string t) {
    if(t.size()==9) { cout<<t<<"\n"; return; }
    for(int s:v[u]) {
        if(a[u][s]==0) {
            a[u][s]=1;
            a[s][u]=1;
            d(a,s,t+to_string(s));
            a[u][s]=0;
            a[s][u]=0;
        }
    }
}
main()
{
    v[1].push_back(2); v[1].push_back(3); v[1].push_back(5);
    v[2].push_back(1); v[2].push_back(3); v[2].push_back(5);
    v[3].push_back(1); v[3].push_back(2); v[3].push_back(4); v[3].push_back(5);
    v[4].push_back(3); v[4].push_back(5);
    v[5].push_back(1); v[5].push_back(2); v[5].push_back(3); v[5].push_back(4);
    d(h,1,"1");
    return 0;
}
